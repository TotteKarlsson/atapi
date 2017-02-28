#pragma hdrstop
#include "atArduinoSerialMessageSender.h"
#include "atArduinoDevice.h"
//---------------------------------------------------------------------------
using namespace mtk;
using Poco::Mutex;

//----------------------------------------------------------------
ArduinoSerialMessageSender::ArduinoSerialMessageSender(ArduinoDevice& d)
:
mtk::Thread(""),
mTheArduino(d),
mProcessTimeDelay(1)
{}

//----------------------------------------------------------------
ArduinoSerialMessageSender::~ArduinoSerialMessageSender()
{
	if(mIsRunning)
    {
		stop();
    }
}

//----------------------------------------------------------------
void ArduinoSerialMessageSender::run()
{
	mIsRunning = true;
	Log(lDebug)<<"Entering UC7 message sender thread";
	while(mIsTimeToDie == false)
	{
		{
			Poco::ScopedLock<Poco::Mutex> lock(mTheArduino.mSendBufferMutex);
			if(mTheArduino.mOutgoingMessagesBuffer.size() == 0)
			{
				Log(lDebug3) << "Waiting for incoming UC7 messages.";
				mTheArduino.mNewMessageToSendCondition.wait(mTheArduino.mSendBufferMutex);
			}

            while(mTheArduino.mOutgoingMessagesBuffer.size() && mIsTimeToDie == false)
            {
            	try
                {
                    string msg = mTheArduino.mOutgoingMessagesBuffer.front();
                    mTheArduino.mOutgoingMessagesBuffer.pop_front();

                    //Send windows message and let UI handle the message
                    if(!mTheArduino.mSerial.send(msg))
                    {
                        Log(lError) << "Sending a UC7 message failed..";
                    }

                    //Use a delay in case the serial devices input buffer overflows
                    sleep(mProcessTimeDelay);

                }
                catch(...)
                {
                	Log(lError) << "Exception thrown in message sender code..";
                }
            }

		}//scoped lock
	}

    Log(lDebug) << "UC7 Message Sender thread finished";
	mIsFinished = true;
	mIsRunning = false;
}

//----------------------------------------------------------------
bool ArduinoSerialMessageSender::start(bool inThread)
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
		run();
		return true;
	}
}

//----------------------------------------------------------------
void ArduinoSerialMessageSender::stop()
{
	//Sets time to die to true
	mtk::Thread::stop();

	//If thread is waiting.. get it out of wait state
	mTheArduino.mNewMessageToSendCondition.signal();
}

