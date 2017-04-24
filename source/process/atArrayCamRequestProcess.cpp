#pragma hdrstop
#include "atArrayCamRequestProcess.h"
#include "atXYZUnit.h"
#include "mtkLogger.h"
#include "mtkXMLUtils.h"
#include "clients/atArrayCamClient.h"
using namespace mtk;
using namespace tinyxml2;

ArrayCamProtocol ap;
//---------------------------------------------------------------------------
ArrayCamRequestProcess::ArrayCamRequestProcess(const string& lbl, const string& request)
:
Process(lbl, NULL),
mRequest(ap.request(request)),
mArrayCamClient(NULL)
{
	mProcessType = ptArrayCamRequestProcess;
}

void ArrayCamRequestProcess::clear()
{}

const string ArrayCamRequestProcess::getTypeName() const
{
	return "arrayCamRequestProcess";
}

bool ArrayCamRequestProcess::setRequest(const string& request)
{
	ArrayCamProtocol ap;
	mRequest = ap.request(request);
    return true;
}

bool ArrayCamRequestProcess::setRequest(ACRequest r)
{
	mRequest = r;
    return true;
}

bool ArrayCamRequestProcess::assignArrayCamClient(ArrayCamClient* acc)
{
	mArrayCamClient = acc;
    return true;
}

XMLElement* ArrayCamRequestProcess::addToXMLDocumentAsChildProcess(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
	ArrayCamProtocol ap;
    //Create XML for saving to file
	XMLElement* e = doc.NewElement("request");
	e->SetText(ap[mRequest].c_str() );
    docRoot->InsertEndChild(e);
    return e;
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
//	mArrayCamClient
	return Process::start();
}

bool ArrayCamRequestProcess::stop()
{
	return Process::stop();
}

bool ArrayCamRequestProcess::isProcessed()
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

bool ArrayCamRequestProcess::isDone()
{
	if(!mIsStarted)
    {
    	return false;
    }

    return true;
}


