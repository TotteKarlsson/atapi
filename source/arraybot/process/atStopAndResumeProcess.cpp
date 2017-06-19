#pragma hdrstop
#include "atStopAndResumeProcess.h"
#include "atXYZUnit.h"
#include "apt/atAPTMotor.h"
#include "mtkLogger.h"
#include "apt/atMove.h"
#include "mtkXMLUtils.h"
#include "atProcessSequence.h"

using namespace mtk;
using namespace at;
using namespace tinyxml2;

//---------------------------------------------------------------------------
StopAndResumeProcess::StopAndResumeProcess(const string& lbl)
:
Process(lbl, NULL),
mResume(false)
{
	mProcessType = ptStopAndResumeProcess;
}

void StopAndResumeProcess::clear()
{}

const string StopAndResumeProcess::getTypeName() const
{
	return "stopAndResumeProcess";
}

bool StopAndResumeProcess::write()
{
	if(mProcessSequence)
    {
    	return mProcessSequence->write();
    }
	return false;
}

XMLElement* StopAndResumeProcess::addToXMLDocumentAsChild(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
    //Create XML for saving to file
	XMLElement* delay = doc.NewElement(getTypeName().c_str());
    return delay;
}

bool StopAndResumeProcess::isBeingProcessed()
{
	if(isDone())
    {
		mIsBeingProcessed 	= false;
        mIsProcessed 		= true;
       	Timestamp now;
        mEndTime = now;
    }

    return mIsBeingProcessed;
}

void StopAndResumeProcess::init(ArrayBot& ab)
{
	mResume = false;
    Process::init(ab);
}

bool StopAndResumeProcess::start()
{
	return Process::start();
}

bool StopAndResumeProcess::stop()
{
	return Process::stop();
}

bool StopAndResumeProcess::resume()
{
	mResume = true;
    return true;
}

bool StopAndResumeProcess::isProcessed()
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

bool StopAndResumeProcess::isDone()
{
	if(!mIsStarted)
    {
    	return false;
    }

    return mResume;
}
