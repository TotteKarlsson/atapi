#pragma hdrstop
#include "atUC7MessageConsumer.h"
#include "mtkStringUtils.h"
#include "Poco/Mutex.h"
#include "mtkLogger.h"
#include "mtkUtils.h"
#include "atUC7.h"
//---------------------------------------------------------------------------

using Poco::Mutex;
using namespace mtk;

//----------------------------------------------------------------
UC7MessageConsumer::UC7MessageConsumer(UC7& messageContainer,  const string& threadName)
:
mtk::Thread(threadName),
mAllowProcessing(true),
mUC7(messageContainer),
mProcessedCount(0),
mNotifyUI(NULL),
//mLastProcessedCommand(mcNone),
mProcessTimeDelay(150)
{}

//----------------------------------------------------------------
UC7MessageConsumer::~UC7MessageConsumer()
{
	if(mIsRunning)
    {
		stop();
    }
}


//MotorCommandEnum UC7MessageConsumer::getLastProcessedMessage()
//{
//	return mLastProcessedCommand;
//}

bool UC7MessageConsumer::start(bool inThread)
{
	if(isRunning())
	{
		Log(lWarning) << "Tried to start a runnning thread";
		return true;
	}
	if(inThread)
	{
		return mtk::Thread::start();
	}
	else
	{
		worker();
		return true;
	}
}

void UC7MessageConsumer::pauseProcessing()
{
	mAllowProcessing = false;
}

void UC7MessageConsumer::resumeProcessing()
{
	mAllowProcessing = true;
}

void UC7MessageConsumer::stop()
{
	//Sets time to die to true
	mtk::Thread::stop();

	//If thread is waiting.. get it out of wait state
	mUC7.mNewMessageCondition.signal();
}

void UC7MessageConsumer::run()
{
	worker();
}

void UC7MessageConsumer::worker()
{
	Log(lDebug)<<"Entering Command Processor Worker Function.";
	while(mIsTimeToDie == false)
	{
		{
			Poco::ScopedLock<Poco::Mutex> lock(mUC7.mBufferMutex);
			if(mUC7.mIncomingMessagesBuffer.size() == 0)
			{
				Log(lDebug3) << "Waiting for UC7 message.";
				mUC7.mNewMessageCondition.wait(mUC7.mBufferMutex);
			}

            while(mUC7.hasMessage() && mIsTimeToDie == false)
            {
	           	UC7Command cmd = mUC7.mIncomingMessagesBuffer.front();
                mUC7.mIncomingMessagesBuffer.pop_front();

    	        Log(lDebug) << "Processing command: "<<cmd.command();

                switch(toInt(cmd.sender()))
                {
//                    case mcNone:
//		    	        Log(lWarning) << "Processing NONE command";
//					break;

                    default: Log(lError) << "UC7 Message: "<<cmd.command()<<" was not reckognized!";

                }

                //mLastProcessedCommand = cmd.getCore();
                sleep(mProcessTimeDelay);
            }

		}//mutex
	}

    Log(lInfo) << "UC7 Message Processor finished";
	mIsFinished = true;
	mIsRunning = false;
}
