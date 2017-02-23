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
    mSerial(-1, 19200, '!', '\r', SerialPort::EHandshake::EHandshakeOff),
    mFeedRate(-1),
    mPrepareForNewRibbon(false),
    mPrepareToCutRibbon(false),
    mPresetFeedRate(30)
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

	//Query HW status
    if(!getCurrentFeedRate())
    {
    	Log(lError) << "Failed query: FeedRate";
    }


	if(!getKnifeStagePosition())
    {
    	Log(lError) << "Failed query: Feed, Absolute position";
    }
    return true;
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
//        Log(lDebug4) << "Receiver: "	<<cmd.getReceiver();
//        Log(lDebug4) << "Sender: "		<<cmd.getSender();
//        Log(lDebug4) << "Command: "		<<cmd.getCommand();
//        Log(lDebug4) << "Data: "		<<cmd.getData();
//        Log(lDebug4) << "Checksum: "	<<hex<<cmd.getCheckSum();
//        Log(lDebug4) << "Checksum Check: "<<(cmd.check() ? "OK" : "Failed");

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
	bool r = mSerial.send(msg);
    return r;
}

bool UC7::startCutter()
{
	return sendUC7Message(CUTTING_MOTOR_CONTROL, "01");
}

bool UC7::stopCutter()
{
	return sendUC7Message(CUTTING_MOTOR_CONTROL, "00");
}

bool UC7::startRibbon()
{

	//Move knife stage north using preset
	moveKnifeStageNorth(mKnifeStageJogPreset);

	//Set cut thickness to preset
    setFeedRate(100);
    return true;
}

bool UC7::getKnifeStagePosition()
{
	return sendUC7Message(NORTH_SOUTH_MOTOR_MOVEMENT, "FF");
}

bool UC7::moveKnifeStageSouth(int nm, bool isRequest)
{
	string dataStr(zeroPadString(4, toHex(nm)));
	sendUC7Message(NORTH_SOUTH_MOTOR_MOVEMENT, "06", dataStr);
    mKnifeStageJogPreset = (nm);
    return true;
}

bool UC7::moveKnifeStageNorth(int nm, bool isRequest)
{
	string dataStr(zeroPadString(4, toHex(nm)));
	sendUC7Message(NORTH_SOUTH_MOTOR_MOVEMENT, "07", dataStr);
    return true;
}

void UC7::disableCounter()
{
	mCounter.disable();
}

void UC7::enableCounter()
{
	mCounter.enable();
}

bool UC7::setPresetFeedRate(int rate)
{
	if(rate != -1)
    {
		mPresetFeedRate = rate;
    }

    setFeedRate(mPresetFeedRate);
    return true;
}

bool UC7::setFeedRate(int feedRate, bool isRequest)
{
	if(isRequest)
    {
		string dataStr(zeroPadString(4, toHex(feedRate)));
		return sendUC7Message(FEED, "01", dataStr);
    }

    mFeedRate = feedRate;
	(mFeedRate > 0) ?  mCounter.enable() : mCounter.disable();
    return true;
}

bool UC7::getCutterMotorStatus()
{
	return sendUC7Message(CUTTING_MOTOR_CONTROL, "FF");
}

int UC7::getCurrentFeedRate(bool isRequest)
{
	if(isRequest)
    {
		return sendUC7Message(FEED, "FF");
    }
   	return mFeedRate;
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

    Log(lDebug4) << "Sending UC7 command: "<<mUC7Message.getMessageNameAsString() <<"("<<mUC7Message.getFullMessage()<<")";
	sendRawMessage(mUC7Message.getFullMessage());
    return true;
}


