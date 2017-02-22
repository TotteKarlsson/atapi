#pragma hdrstop
#include "atUC7Component.h"
#include "mtkIniFile.h"
#include "mtkLogger.h"
#include "mtkStringUtils.h"


//---------------------------------------------------------------------------

using namespace mtk;

UC7::UC7()
:
	mINIFileSection("UC7"),
    mCOMPort(-1),
    mSerial(-1, 19200, '!', '\r', SerialPort::EHandshake::EHandshakeOff)
{
	mSerial.assignMessageReceivedCallBack(onSerialMessage);
}

UC7::~UC7()
{
	disConnect();
}

bool UC7::connect(int com)
{
	Log(lInfo) << "Connecting UC7 client on COM"<<com;
    if(!mSerial.connect(com, 19200))
    {
		return false;
    }

    return true;
}

bool UC7::disConnect()
{
	return mSerial.disConnect();
}

bool UC7::isConnected()
{
	return mSerial.isConnected();
}

bool UC7::getStatus()
{
	//Don't like the sleeps, but sending data
    //too fast over serial port causes a problem :(

	//Query HW status
    if(!getCutterMotorStatus())
    {
    	Log(lError) << "Failed query: Cutter Status";
    }

	sleep(50);

	//Query HW status
    if(!getCurrentFeedRate())
    {
    	Log(lError) << "Failed query: FeedRate";
    }

	sleep(50);
	if(!getKnifeStagePosition())
    {
    	Log(lError) << "Failed query: Feed, Absolute position";
    }
}

bool UC7::getVersion()
{
	return "";
}

bool UC7::hasMessage()
{
	return mIncomingMessagesBuffer.size() ? true : false;
}

UC7Message UC7::getLastSentMessage()
{
	return mUC7Message;
}

//This one is called from serial port listening thread
void UC7::onSerialMessage(const string& msg)
{
	Log(lDebug) << "Decoding UC7 message: "<<msg;
    UC7Message cmd(msg, true, true);
    if(cmd.check())
    {
        Log(lDebug4) << "Receiver: "	<<cmd.getReceiver();
        Log(lDebug4) << "Sender: "		<<cmd.getSender();
        Log(lDebug4) << "Command: "		<<cmd.getCommand();
        Log(lDebug4) << "Data: "		<<cmd.getData();
        Log(lDebug4) << "Checksum: "	<<hex<<cmd.getCheckSum();
        Log(lDebug4) << "Checksum Check: "<<(cmd.check() ? "OK" : "Failed");

		//Get mutex using a scoped lock
        {
        	Poco::ScopedLock<Poco::Mutex> lock(mBufferMutex);
	        mIncomingMessagesBuffer.push_back(cmd);
        }

        //Send a signal
        mNewMessageCondition.signal();
    }
    else
    {
   		Log(lError) << "Bad CheckSum for message: "<<msg;
    }
}

bool UC7::sendByte(const unsigned char b)
{
	Log(lDebug5) << "Sending byte: "<<b;
	return mSerial.send(b);
}

bool UC7::sendRawMessage(const string& msg)
{
	Log(lInfo) << "Sending raw message: "<<msg;
	return mSerial.send(msg);
}

bool UC7::startCutter()
{
	return sendUC7Message(CUTTING_MOTOR_CONTROL, "01");
}

bool UC7::stopCutter()
{
	return sendUC7Message(CUTTING_MOTOR_CONTROL, "00");
}

bool UC7::setFeedRate(int feedRate)
{
	string dataStr(zeroPadString(4, toHex(feedRate)));
	return sendUC7Message(FEED, "01", dataStr);
}

bool UC7::getCutterMotorStatus()
{
	return sendUC7Message(CUTTING_MOTOR_CONTROL, "FF");
}

bool UC7::getCurrentFeedRate()
{
	return sendUC7Message(FEED, "FF");
}

bool UC7::getKnifeStagePosition()
{
	return sendUC7Message(NORTH_SOUTH_MOTOR_MOVEMENT, "FF");
}

bool UC7::sendUC7Message(const UC7MessageEnum& msgName, const string& data1, const string& data2)
{
	stringstream cmd;
	string sender("1");

	//This function constructs a proper command to send to the UC7
    switch(msgName)
    {
        case SOFTWARE_RESET:

 		break;

        case GET_PART_ID:

 		break;

        case LOGIN:

 		break;

        case COMMAND_TRANSMISSION_ERROR:

 		break;

        case GET_VERSION:

 		break;

        case FEEDRATE_MOTOR_CONTROL:
       		cmd <<gStepperControllerAddress<<sender<<20<<data1;
	        mUC7Message.init(cmd.str());
 		break;

        case SEND_POSITION_AT_MOTION:

 		break;

        case FEED:
       		cmd <<gStepperControllerAddress<<sender<<23<<data1<<data2;
	        mUC7Message.init(cmd.str());
 		break;

        case NORTH_SOUTH_MOTOR_MOVEMENT:
       		cmd <<gStepperControllerAddress<<sender<<30<<data1<<data2;
	        mUC7Message.init(cmd.str());
 		break;

        case SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH:

 		break;

        case EAST_WEST_MOTOR_MOVEMENT:

 		break;

        case SEND_POSITION_AT_MOVEMENT_EAST_WEST:

 		break;

        case CUTTING_MOTOR_CONTROL:
       		cmd <<gMotorControllerAddress<<sender<<20<<data1;
	        mUC7Message.init(cmd.str());
 		break;

        case CUTTING_SPEED:

 		break;

        case RETURN_SPEED:

 		break;

        case HANDWHEEL_POSITION:

 		break;

        default: break;

    }

    Log(lDebug4) << "Sending UC7 command: "<<mUC7Message.getFullMessage();
	sendRawMessage(mUC7Message.getFullMessage());
    return true;
}


