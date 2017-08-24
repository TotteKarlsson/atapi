#pragma hdrstop
#include "atArrayCamRequestProcess.h"
#include "atXYZUnit.h"
#include "mtkLogger.h"
#include "mtkXMLUtils.h"
#include "arraycam/atArrayCamClient.h"
#include "atProcessSequence.h"

using namespace mtk;
using namespace tinyxml2;

ArrayCamProtocol ap;
//---------------------------------------------------------------------------
ArrayCamRequestProcess::ArrayCamRequestProcess(ArrayCamClient& acc, const string& lbl, const string& request)
:
Process(lbl, NULL),
mRequest(ap.idFromString(request)),
mArrayCamClient(acc),
mParameter1(0),
mParameter2(0)
{
	mProcessType = ptArrayCamRequest;
    mArrayCamClient.assignOnMessageReceivedCallBack(onReceivedResponse);
}

void ArrayCamRequestProcess::clear()
{}

bool ArrayCamRequestProcess::write()
{
	if(mProcessSequence)
    {
    	return mProcessSequence->write();
    }
	return false;
}

const string ArrayCamRequestProcess::getTypeName() const
{
	return "arrayCamRequestProcess";
}

bool ArrayCamRequestProcess::setRequest(const string& request)
{
	ArrayCamProtocol ap;
	mRequest = ap.idFromString(request);
    return true;
}

bool ArrayCamRequestProcess::setRequest(ACMessageID r)
{
	mRequest = r;
    return true;
}

XMLElement* ArrayCamRequestProcess::addToXMLDocumentAsChild(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
    //Create XML for saving to file
	ArrayCamProtocol ap; //To get string value
    XMLElement* request	  		= doc.NewElement("request");
	request->SetText(ap[mRequest].c_str() );
    docRoot->InsertEndChild(request);

	if(mRequest == acrSetZoomAndFocus) //Need parameters for this one
    {
        XMLElement* f = doc.NewElement("focus");
        f->SetText(mParameter1.getValueAsString().c_str());
        docRoot->InsertEndChild(f);

        XMLElement* zoom = doc.NewElement("zoom");
        zoom->SetText(mParameter2.getValueAsString().c_str());
        docRoot->InsertEndChild(zoom);
    }

    return request;
}

bool ArrayCamRequestProcess::isBeingProcessed()
{
	if(isDone())
    {
		mIsBeingProcessed = false;
        mIsProcessed = true;
       	Timestamp now;
        mEndTime = now;
    }

    return mIsBeingProcessed;
}

bool ArrayCamRequestProcess::start()
{
	switch(mRequest)
    {
     	case ACMessageID::acrStartVideoRecorder:
	        mArrayCamClient.startVideo();
		break;

     	case ACMessageID::acrStopVideoRecorder:
	        mArrayCamClient.stopVideo();
		break;

     	case ACMessageID::acrEnableBarcodeScanner:
	        mArrayCamClient.enableBarcodeScanner();
		break;

     	case ACMessageID::acrDisableBarcodeScanner:
	        mArrayCamClient.disableBarcodeScanner();
		break;

     	case ACMessageID::acrTakeSnapShot:
	        mArrayCamClient.takeSnapShot();
		break;

     	case ACMessageID::acrSetZoomAndFocus:
	        mArrayCamClient.setZoomAndFocus(mParameter1, mParameter2);
		break;

		default:
        	Log(lError) << "Bad ArrayCamRequest in process";
			return false;
    }

	return Process::start();
}

bool ArrayCamRequestProcess::stop()
{
	return Process::stop();
}

bool ArrayCamRequestProcess::isProcessed()
{
    if(isDone())
    {
        //Consider this process to be "processed"
        mIsProcessed 		= true;
        mIsBeingProcessed 	= false;
        return true;
    }

	return false;
}

void ArrayCamRequestProcess::onReceivedResponse(const string& msg)
{
	if(!mIsBeingProcessed)
    {
    	return;
    }
    ArrayCamProtocol p;

    Log(lInfo) << "Got ArrayCam Response: "<<msg;

    switch(mRequest)
    {
    	case acrEnableBarcodeScanner:
        	if(msg == p[acrBarcodeScanSucceded])
    		{
                mIsProcessed = true;
            }
		break;

    	case acrDisableBarcodeScanner:
        	if(msg == p[acrBarcodeScannerDisabled])
    		{
                mIsProcessed = true;
            }
		break;

    	case acrStartVideoRecorder:
        	if(msg == p[acrVideoRecorderStarted])
    		{
                mIsProcessed = true;
            }
		break;

    	case acrStopVideoRecorder:
        	if(msg == p[acrVideoRecorderStopped])
    		{
                mIsProcessed = true;
            }
		break;

    	case acrTakeSnapShot:
        	if(msg == p[acrSnapShotTaken])
    		{
                mIsProcessed = true;
            }
		break;

    	case acrSetZoomAndFocus:
        	if(msg == p[acrFocusAndZoomSet])
    		{
                mIsProcessed = true;
            }
		break;
    }
}

bool ArrayCamRequestProcess::isDone()
{
	if(!mIsStarted)
    {
    	return false;
    }

    return mIsProcessed;
}


