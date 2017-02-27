#pragma hdrstop
#include "atUC7Component.h"
#include "mtkIniFile.h"
#include "mtkLogger.h"
#include "mtkStringUtils.h"
//---------------------------------------------------------------------------

using namespace mtk;

UC7::UC7(HWND__ *h)
:
	mINIFileSection("UC7"),
    mCOMPort(-1),
    mSerial(-1, 19200, '!', '\r', SerialPort::EHandshake::EHandshakeOff),
    mFeedRate(-1),
    mPrepareForNewRibbon(false),
    mPrepareToCutRibbon(false),
    mPresetFeedRate(70),
	mUC7MessageReceiver(*this, h),
    mUC7MessageSender(*this),
    mIsActive(false),
    mSetNumberOfZeroStrokes(0),
    mNumberOfZeroStrokes(0)
{
	mSerial.assignMessageReceivedCallBack(onSerialMessage);
    mCustomTimer.setInterval(5);
}

UC7::~UC7()
{
	disConnect();
}

bool UC7::connect(int com)
{
	Log(lInfo) << "Connecting UC7 client on COM"<<com;

    mUC7MessageReceiver.start();
    mUC7MessageSender.start();

    if(!mSerial.connect(com, 19200))
    {
		return false;
    }

    return true;
}

bool UC7::disConnect()
{
    mUC7MessageSender.stop();
    mUC7MessageReceiver.stop();
	return mSerial.disConnect();
}

bool UC7::isConnected()
{
	return mSerial.isConnected();
}

bool UC7::setStrokeState(EStrokeState state)
{
	mStrokeState = state;
    if(state == ssCutting && mFeedRate == 0)
    {
    	mNumberOfZeroStrokes++;
    }

    if(mFeedRate != 0)
    {
		mNumberOfZeroStrokes =0;
    }

    //When the state changes, certain events may take place
    if(mPrepareToCutRibbon)
    {
        if(mStrokeState == ssAfterCutting)
        {
            Log(lInfo) << "Preparing new Ribbon: (1) Setting feedrate to 0 nm";
            setFeedRate(0);
        }
        else if(mStrokeState == ssRetracting && mFeedRate == 0)
        {
        	if(mNumberOfZeroStrokes >= mSetNumberOfZeroStrokes)
            {
            	mCustomTimer.assignTimerFunction(onPrepareToCutRibbon);
            	mCustomTimer.start();
            	Log(lInfo) << "Started Custom Timer";
            	prepareToCutRibbon(false);
            }
        }
    }
    else if(mPrepareForNewRibbon)
    {
        if(mPrepareForNewRibbon == true && mStrokeState == ssAfterCutting)
        {
            Log(lInfo) << "Preparing new Ribbon: (1) Setting feedrate to: "<<mPresetFeedRate<<" nm";
            setFeedRate(mPresetFeedRate);
        }
        else if (mStrokeState == ssRetracting && mFeedRate == mPresetFeedRate)
        {
        	//This will move the stage
            mCustomTimer.assignTimerFunction(onPrepareForNewRibbon);
            mCustomTimer.start();
            Log(lInfo) << "Started Custom Timer";
            prepareForNewRibbon(false);
        }
    }
    return true;
}

bool UC7::setStageMoveDelay(int ms)
{
	return mCustomTimer.setInterval(ms);
}

void UC7::onPrepareToCutRibbon()
{
    Log(lInfo) << "Custom Timer fired";
    mCustomTimer.stop();
	Log(lInfo) << "Moving Knife stage SOUTH";
    moveKnifeStageSouth(mKnifeStageJogPreset);
}

void UC7::onPrepareForNewRibbon()
{
    Log(lInfo) << "Custom Timer fired";
    mCustomTimer.stop();
	Log(lInfo) << "Moving Knife stage NORTH";
    moveKnifeStageNorth(mKnifeStageJogPreset);
}

bool UC7::getStatus()
{
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
	return false;
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
		//Get mutex using a scoped lock
        {
        	Poco::ScopedLock<Poco::Mutex> lock(mReceiveBufferMutex);
	        mIncomingMessagesBuffer.push_back(cmd);
        }

        //Send a signal
        mNewReceivedMessageCondition.signal();
    }
    else
    {
   		Log(lError) << "Bad checksum for message: "<<msg<<" Message discarded";
    }
}

bool UC7::sendRawMessage(const string& msg)
{
	//Put the message on the utgoing queue
    {
        Poco::ScopedLock<Poco::Mutex> lock(mSendBufferMutex);
    	mOutgoingMessagesBuffer.push_back(msg);
    }

    //Send a signal
    mNewMessageToSendCondition.signal();
	return true;
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
	mSectionCounter.disable();
}

void UC7::enableCounter()
{
	mSectionCounter.enable();
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
	(mFeedRate > 0) ?  mSectionCounter.enable() : mSectionCounter.disable();
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
  			Log(lInfo) << "Not implemented!";
 		break;

        case GET_PART_ID:
  			Log(lInfo) << "Not implemented!";
 		break;

        case LOGIN:
  			Log(lInfo) << "Not implemented!";
 		break;

        case COMMAND_TRANSMISSION_ERROR:
  			Log(lInfo) << "Not implemented!";
 		break;

        case GET_VERSION:
  			Log(lInfo) << "Not implemented!";
 		break;

        case FEEDRATE_MOTOR_CONTROL:
       		cmd <<gStepperControllerAddress<<sender<<20<<data1;
	        mUC7Message.init(cmd.str());
 		break;

        case SEND_POSITION_AT_MOTION:
  			Log(lInfo) << "Not implemented!";
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
  			Log(lInfo) << "Not implemented!";
   		break;

        case EAST_WEST_MOTOR_MOVEMENT:
  			Log(lInfo) << "Not implemented!";
 		break;

        case SEND_POSITION_AT_MOVEMENT_EAST_WEST:
  			Log(lInfo) << "Not implemented!";
 		break;

        case CUTTING_MOTOR_CONTROL:
       		cmd <<gMotorControllerAddress<<sender<<20<<data1;
	        mUC7Message.init(cmd.str());
 		break;

        case CUTTING_SPEED:
  			Log(lInfo) << "Not implemented!";
 		break;

        case RETURN_SPEED:
  			Log(lInfo) << "Not implemented!";
 		break;

        case HANDWHEEL_POSITION:
  			Log(lInfo) << "Not implemented!";
 		break;

        default:
        	Log(lInfo) << "Unhandled Message!";
        break;

    }

    Log(lInfo) << "Sending UC7 command: "<<mUC7Message.getMessageNameAsString() <<"\t\t("<<mUC7Message.getFullMessage()<<")";
	sendRawMessage(mUC7Message.getFullMessage());
    return true;
}


