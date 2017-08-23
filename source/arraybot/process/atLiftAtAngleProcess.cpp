#pragma hdrstop
#include "atLiftAtAngleProcess.h"
//---------------------------------------------------------------------------

using namespace mtk;
//using namespace at;

//---------------------------------------------------------------------------
LiftAtAngleProcess::LiftAtAngleProcess(const string& lbl)
:
ParallelProcess(lbl)
{
	mProcessType = ptLiftAtAngleProcess;
}

const string LiftAtAngleProcess::getTypeName() const
{
	return ::toString(mProcessType);
}

void LiftAtAngleProcess::init(ArrayBot& ab)
{
	Process::init(ab);

    //Call init for each sub move
    for(int i = 0; i < mProcesses.size(); i++)
    {
    	if(mProcesses[i])
        {
        	mProcesses[i]->init(ab);
        }
    }
}

//void LiftAtAngleProcess::clear()
//{
//	mProcesses.clear();
//}
//
//bool LiftAtAngleProcess::write()
//{
//	if(mProcessSequence)
//    {
//    	return mProcessSequence->write();
//    }
//	return false;
//}
//
//void LiftAtAngleProcess::addProcess(Process* lm)
//{
//	if(!lm)
//    {
//    	return;
//    }
//	if(lm->getProcessName() =="")
//    {
//    	lm->setProcessName("Action " + mtk::toString((mProcesses.size() + 1)));
//    }
//
//	mProcesses.push_back(lm);
//}
//
//bool LiftAtAngleProcess::removeProcess(const string& name)
//{
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//    	if(mProcesses[i]->getProcessName() == name)
//        {
//        	Process* lm = (mProcesses[i]);
//            mProcesses.erase(mProcesses.begin() + i);
//        }
//    }
//    return true;
//}
//
//bool LiftAtAngleProcess::removeProcess(Process* m)
//{
//	return false;
//}
//
//Process* LiftAtAngleProcess::getProcess(int i)
//{
//	if(i < mProcesses.size())
//    {
//    	return (mProcesses[i]);
//    }
//    return NULL;
//}
//
//Process* LiftAtAngleProcess::getProcess(const string& lbl)
//{
//	// look for item
//    for(int i = 0 ; i < mProcesses.size(); i++)
//    {
//    	Process* mv = mProcesses[i];
//        if(mv->getProcessName() == lbl)
//        {
//        	return mv;
//        }
//    }
//    return NULL;
//}
//
//Process* LiftAtAngleProcess::getProcess(const Process* p)
//{
//	// look for item
//    for(int i = 0 ; i < mProcesses.size(); i++)
//    {
//    	Process* aProc = mProcesses[i];
//        if(aProc == p)
//        {
//        	return aProc;
//        }
//    }
//    return NULL;
//}
//

XMLElement* LiftAtAngleProcess::addToXMLDocumentAsChild(tinyxml2::XMLDocument& doc, XMLNode* docRoot)
{
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//    	Process* lm = mProcesses[i];
//        mtk::XMLElement* e = lm->addToXMLDocument(doc, docRoot);
//        lm->addToXMLDocumentAsChild(doc, e);
//    }

    return dynamic_cast<XMLElement*>(docRoot);
}
//
//bool LiftAtAngleProcess::isBeingProcessed()
//{
//	if(isDone())
//    {
//		mIsBeingProcessed = false;
//        mIsProcessed = true;
//       	Timestamp now;
//        mEndTime = now;
//    }
//
//    return mIsBeingProcessed;
//}
//
//bool LiftAtAngleProcess::isProcessed()
//{
//    if(mIsProcessed == true)
//    {
//    	return true;
//    }
//
//    if(isDone())
//    {
//        //Consider this process to be "processed"
//        mIsProcessed 		= true;
//        mIsBeingProcessed 	= false;
//        return true;
//    }
//
//	return false;
//}
//
//bool LiftAtAngleProcess::isCommandPending()
//{
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//	    Move* m = dynamic_cast<Move*>(mProcesses[i]);
//    	if(m && m->isMotorCommandPending())
//        {
//        	return true;
//        }
//    }
//
//    return false;
//}
//
//bool LiftAtAngleProcess::areMotorsActive()
//{
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//	    Move* m = dynamic_cast<Move*>(mProcesses[i]);
//    	if(m && m->isMotorCommandPending())
//        {
//        	return true;
//        }
//    }
//
//    return false;
//}
//
//bool LiftAtAngleProcess::start()
//{
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//    	mProcesses[i]->start();
//        Log(lInfo) << "Started Action \"" << mProcesses[i]->getProcessName()<<"\"";
//    }
//
//	return Process::start();
//}
//
//bool LiftAtAngleProcess::stop()
//{
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//    	mProcesses[i]->stop();
//    }
//
//	return Process::stop();
//}
//
//bool LiftAtAngleProcess::isDone()
//{
//	//Check all subprocesses here
//	for(int i = 0; i < mProcesses.size(); i++)
//    {
//    	if(!mProcesses[i]->isDone())
//        {
//        	return false;
//        }
//    }
//
//    return true;
//}
//
//bool LiftAtAngleProcess::undo()
//{
//	return false;
//}
