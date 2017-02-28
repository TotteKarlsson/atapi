#pragma hdrstop
#include "atArduinoDevice.h"
#include "mtkWin32Utils.h"
#include "mtkLogger.h"
#include "Poco/Mutex.h"
using namespace mtk;

ArduinoDevice::ArduinoDevice(int pNr, int baudRate)
:
mSerial(pNr, baudRate),
mMessageSender(*this)
{}

ArduinoDevice::~ArduinoDevice()
{
	mSerial.assignMessageReceivedCallBack(NULL);
    mSerial.disConnect();
}

bool ArduinoDevice::connect(int portNr, int baudRate)
{
    mMessageSender.start();
	return mSerial.connect(portNr, baudRate);
}

bool ArduinoDevice::isConnected()
{
	return mSerial.isConnected() || mMessageSender.isAlive();
}

bool ArduinoDevice::disConnect()
{
	mMessageSender.stop();
	return mSerial.disConnect();
}

bool ArduinoDevice::readDigitalPin(int pin)
{
	return false;
}

bool ArduinoDevice::writeDigitalPin(int pin)
{
	return false;
}

bool ArduinoDevice::send(int val)
{
	return send(toString(val));
}

bool ArduinoDevice::send(const string& msg)
{
	//Put the message on the utgoing queue
    {
        Poco::ScopedLock<Poco::Mutex> lock(mSendBufferMutex);
    	mOutgoingMessagesBuffer.push_back(msg);
    }

    //Send a signal
    mNewMessageToSendCondition.signal();
	return true;

//	return mSerial.send(msg);
}

//bool UC7::sendRawMessage(const string& msg)
//{
//	//Put the message on the utgoing queue
//    {
//        Poco::ScopedLock<Poco::Mutex> lock(mSendBufferMutex);
//    	mOutgoingMessagesBuffer.push_back(msg);
//    }
//
//    //Send a signal
//    mNewMessageToSendCondition.signal();
//	return true;
//}


void ArduinoDevice::assignSerialMessageReceivedCallBack(SerialMessageReceivedCallBack cb)
{
	mSerial.assignMessageReceivedCallBack(cb);
}

bool ArduinoDevice::hasMessage()
{
	return mSerial.hasMessage();
}

string ArduinoDevice::getMessage()
{
	return mSerial.popMessage();
}
