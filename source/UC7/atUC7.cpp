#pragma hdrstop
#include "atUC7.h"
#include "mtkIniFile.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------

using namespace mtk;

UC7::UC7()
:
	mINIFileSection("UC7"),
    mCOMPort(-1),
    mSerial(-1, 19200,'!', '\r')
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
    return mSerial.connect(com, 19200);
}

bool UC7::disConnect()
{
	return mSerial.disConnect();
}

bool UC7::isConnected()
{
	return mSerial.isConnected();
}

//This returns the checksum as a HEX number
int UC7::calculateCheckSum(const string& cmd)
{
	int cs = 0xFF;
	return cs;
}

bool UC7::getVersion()
{
	return "";
}

void UC7::onSerialMessage(const string& msg)
{
	Log(lDebug4) << "Decoding UC7 message: "<<msg;
    UC7Command cmd(msg, true);
    if(cmd.check())
    {
        Log(lDebug4) << "Receiver: "	<<cmd.receiver();
        Log(lDebug4) << "Sender: "		<<cmd.sender();
        Log(lDebug4) << "Command: "		<<cmd.command();
        Log(lDebug4) << "Data: "		<<cmd.data();
        Log(lDebug4) << "Checksum: "	<<hex<<cmd.checksum();
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
   		Log(lInfo) << "Bad CheckSum for message: "<<msg;
    }
}


bool UC7::sendRawMessage(const string& msg)
{
	Log(lInfo) << "Sending raw message: "<<msg;
	return mSerial.send(msg);
}

bool UC7::startCutter()
{
	return sendUC7Command(CUTTING_MOTOR_CONTROL, "01");
}

bool UC7::stopCutter()
{
	return sendUC7Command(CUTTING_MOTOR_CONTROL, "00");
}

bool UC7::getCutterStatus()
{
	return sendUC7Command(CUTTING_MOTOR_CONTROL, "FF");
}

bool UC7::sendUC7Command(const UC7CommandName& uc, const string& data1, const string& data2)
{
	stringstream cmd;

	//This function constructs a proper command to send to the UC7
    switch(uc)
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

 		break;

        case SEND_POSITION_AT_MOTION:

 		break;

        case FEED:

 		break;

        case NORTH_SOUTH_MOTOR_MOVEMENT:

 		break;

        case SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH:

 		break;

        case EAST_WEST_MOTOR_MOVEMENT:

 		break;

        case SEND_POSITION_AT_MOVEMENT_EAST_WEST:

 		break;

        case CUTTING_MOTOR_CONTROL:
//        	cmd <<"!"<<mSender<<"5"<<data1;
//            string cs = calculateCheckSum(cmd);
//            cmd<<'\r';
 		break;

        case CUTTING_SPEED:

 		break;

        case RETURN_SPEED:

 		break;

        case HANDWHEEL_POSITION:

 		break;

        default: break;

    }

    Log(lDebug4) << "Sending UC7 command: "<<cmd.str();
    return true;
}


