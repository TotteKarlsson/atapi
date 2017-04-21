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
mArrayCamRequest(request),
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

bool ArrayCamRequest::assignArrayCamClient(ArrayCamClient* acc)
{
	mArrayCamClient = acc;
}

XMLElement* ArrayCamRequest::addToXMLDocumentAsChildProcess(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
    //Create XML for saving to file
	XMLElement* delay = doc.NewElement("arrayCamRequest");
	delay->SetText(mtk::toString(mArrayCamRequest).c_str() );
    docRoot->InsertEndChild(delay);
    return delay;
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
