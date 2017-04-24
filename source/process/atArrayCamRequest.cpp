#pragma hdrstop
#include "atArrayCamRequest.h"
#include "atXYZUnit.h"
#include "mtkLogger.h"
#include "mtkXMLUtils.h"

using namespace mtk;
using namespace tinyxml2;

//---------------------------------------------------------------------------
ArrayCamRequest::ArrayCamRequest(const string& lbl, const string& request)
:
Process(lbl, NULL),
mRequest(arrayCamRequestFromString(request)),
mArrayCamClient(NULL)
{
	mProcessType = ptArrayCamRequest;
}

void ArrayCamRequest::clear()
{}

const string ArrayCamRequest::getTypeName() const
{
	return "arrayCamRequest";
}

bool ArrayCamRequest::setRequest(const string& request)
{
	mRequest = arrayCamRequestFromString(request);
    return true;
}

bool ArrayCamRequest::setRequest(ACRequest r)
{
	mRequest = r;
    return true;
}

bool ArrayCamRequest::assignArrayCamClient(ArrayCamClient* acc)
{
	mArrayCamClient = acc;
    return true;
}

XMLElement* ArrayCamRequest::addToXMLDocumentAsChildProcess(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
    //Create XML for saving to file
	XMLElement* e = doc.NewElement("arrayCamRequest");
	e->SetText(requestToString((ACRequest) mRequest).c_str() );
    docRoot->InsertEndChild(e);
    return e;
}

bool ArrayCamRequest::isBeingProcessed()
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

bool ArrayCamRequest::start()
{
//	mArrayCamClient
	return Process::start();
}

bool ArrayCamRequest::stop()
{
	return Process::stop();
}

bool ArrayCamRequest::isProcessed()
{
    if(mIsProcessed == true)
    {
    	return true;
    }

    if(isDone())
    {
        //Consider this process to be "processed"
        mIsProcessed 		= true;
        mIsBeingProcessed 	= false;
        return true;
    }

	return false;
}

bool ArrayCamRequest::isDone()
{
	if(!mIsStarted)
    {
    	return false;
    }

    return true;
}

string requestToString(ACRequest r)
{
	switch(r)
    {
    	case acrStartVideo: 				return "Start Video";
    	case acrStopVideo: 					return "Stop Video";
    	case acrTakeSnapShot: 				return "Take Snapshot";
    	case acrEnableBarcodeScanner: 		return "Enable Barcode Scanner";
    	case acrDisableBarcodeScanner: 		return "Disable Barcode Scanner";
    	case acrValidateBarcode: 			return "Validate Barcode";
        default: 							return "Unknown";
    }
}

ACRequest arrayCamRequestFromString(const string& t)
{
    if(compareNoCase(t, "Start Video"))
    {
    	return acrStartVideo;
    }
    if(compareNoCase(t, "Stop Video"))
    {
    	return acrStopVideo;
    }
    if(compareNoCase(t, "Stop Video"))
    {
    	return acrStopVideo;
    }
    if(compareNoCase(t, "Stop Video"))
    {
    	return acrStopVideo;
    }
    if(compareNoCase(t, "Stop Video"))
    {
    	return acrStopVideo;
    }
    if(compareNoCase(t, "Stop Video"))
    {
    	return acrStopVideo;
    }
    else
    {
    	return acrUnknown;
    }
}
