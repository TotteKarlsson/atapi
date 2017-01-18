#pragma hdrstop
#include "atUC7Message.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;

int hexToDec(const string& hex);

UC7Message::UC7Message(const string& cmd, bool isResponse)
:
mReceiver(""),
mSender(""),
mData(""),
mCheckSum(""),
mCommandString(""),
mIsResponse(isResponse)
{
	if(cmd.size())
    {
        if(!parse(cmd, mIsResponse))
        {
            Log(lError) << "The UC7 command: " <<cmd<<" failed to parse";
        }
    }
}

bool UC7Message::parse(const string& cmd, bool isResponse)
{
	//A command has to be at least 6 chars long
    int minCmdSize = 6;

    if(cmd.size() < minCmdSize)
    {
    	Log(lError) << "UC7 command is to short";
        return false;
    }

	if(isResponse)
    {
        //First letter is the receiver
        mReceiver = cmd[0];

        //Second letter is the sender
        mSender = cmd[1];
    }
    else
    {
        //First letter is the receiver
        mReceiver = cmd[1];

        //Second letter is the sender
        mSender = cmd[0];
    }

    //Next two chars are the command
    mCommandString.push_back(cmd[2]);
    mCommandString.push_back(cmd[3]);
    mCommandName = toCommandName(mCommandString, toInt(mSender));

    //The data is everything after the command and before the checksum
    if(cmd.size() == minCmdSize)
    {
    	mData = "";
    }
    else
    {
    	int lengthOfData = cmd.size() - minCmdSize;
    	mData = cmd.substr(4, lengthOfData);
    }

    mCheckSum.push_back(cmd[cmd.size() - 2]);
    mCheckSum.push_back(cmd[cmd.size() - 1]);
    return true;
}

string UC7Message::receiver()
{
	return mReceiver;
}

string UC7Message::sender() const
{
	return mSender;
}

string UC7Message::command()
{
	return mCommandString;
}

string UC7Message::data()
{
	return mData;
}

string UC7Message::checksum()
{
	return mCheckSum;
}


string UC7Message::getFullMessage()
{
	return mReceiver + mSender + mCommandString + mData + mCheckSum;
}

int addUpDataToInt(const string& mData)
{
	int sum(0);

    for(int i = 0; i < mData.size(); i += 2)
    {
        string val;
        val.push_back(mData[i]);
        val.push_back(mData[i+1]);
        sum += hexToDec(val);
    }
    return sum;
}

string UC7Message::getMessageNameAsString()
{
	return toLongString(mCommandName);
}

bool UC7Message::check()
{
	//Check command against checksum for integrity
    string recSndrSum(mReceiver + mSender);
    unsigned char sum = hexToDec(recSndrSum) + hexToDec(mCommandString);

	int data = addUpDataToInt(mData);
    sum += data;

    //take two's complement, of a two byte variable
    sum = ~sum + 1;

    int cs(hexToDec(mCheckSum));
    return (sum == cs) ? true : false;
}

UC7MessageName toCommandName(const string& cmd, int controllerAddress)
{
	switch(controllerAddress)
    {
    	case 1: 		return UNKNOWN;
        case 2:			return UNKNOWN;
        case 3:			return UNKNOWN;
        case 4:
        {
        	if(cmd == "20")
            {
            	return FEEDRATE_MOTOR_CONTROL;
            }
            else if(cmd == "21")
            {
            	return SEND_POSITION_AT_MOTION;
            }
            else if(cmd == "23")
            {
            	return FEED;
            }
            else if(cmd == "30")
            {
            	return NORTH_SOUTH_MOTOR_MOVEMENT;
            }
            else if(cmd == "31")
            {
            	return SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH;
            }
            else if(cmd == "40")
            {
            	return EAST_WEST_MOTOR_MOVEMENT;
            }
            else if(cmd == "41")
            {
            	return SEND_POSITION_AT_MOVEMENT_EAST_WEST;
            }
			else
            {
            	return UNKNOWN;
            }
        }
		case 5:
        {
        	if(cmd == "20")
            {
            	return CUTTING_MOTOR_CONTROL;
            }
        	else if(cmd == "30")
            {
            	return CUTTING_SPEED;
            }
        	else if(cmd == "31")
            {
            	return RETURN_SPEED;
            }
        	else if(cmd == "40")
            {
            	return HANDWHEEL_POSITION;
            }
            else
            {
            	return UNKNOWN;
            }
        }

        default: return UNKNOWN;
    }
}

string toShortString(UC7MessageName cmd)
{
    switch(cmd)
    {
        case SOFTWARE_RESET:		                        return "F0";
        case GET_PART_ID:			                        return "F1";
        case LOGIN:					                        return "F2";
        case COMMAND_TRANSMISSION_ERROR:                    return "F3";
        case GET_VERSION:                                   return "F5";

        //Controller #4
        case FEEDRATE_MOTOR_CONTROL:                        return "20";
        case SEND_POSITION_AT_MOTION:                       return "21";
        case FEED:                                          return "23";
        case NORTH_SOUTH_MOTOR_MOVEMENT:                    return "30";
        case SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH:         return "31";
        case EAST_WEST_MOTOR_MOVEMENT:                      return "40";
        case SEND_POSITION_AT_MOVEMENT_EAST_WEST:           return "41";

        //Controller #5
        case CUTTING_MOTOR_CONTROL:                         return "20";
        case CUTTING_SPEED:                                 return "30";
        case RETURN_SPEED:                                  return "31";
        case HANDWHEEL_POSITION:                            return "40";

        default:
        	Log(lError) << "UNKNOWN UC7 message: "<<cmd;    return "UNKNOWN";
    }
}

string toLongString(UC7MessageName cmd)
{
    switch(cmd)
    {
        case SOFTWARE_RESET:		                        return "Software Reset";
        case GET_PART_ID:			                        return "Get part ID (WKZ)";
        case LOGIN:					                        return "Login";
        case COMMAND_TRANSMISSION_ERROR:                    return "Command-/Transmission error";
        case GET_VERSION:                                   return "Get version";

        //Controller #4
        case FEEDRATE_MOTOR_CONTROL:                        return "Feedrate motoro control";
        case SEND_POSITION_AT_MOTION:                       return "Send position at motion";
        case FEED:                                          return "Feed";
        case NORTH_SOUTH_MOTOR_MOVEMENT:                    return "North/South Motor movement";
        case SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH:         return "Send Position at movement (North/South)";
        case EAST_WEST_MOTOR_MOVEMENT:                      return "East/West motor movement";
        case SEND_POSITION_AT_MOVEMENT_EAST_WEST:           return "Send position at movement East/West";

        //Controller #5
        case CUTTING_MOTOR_CONTROL:                         return "Cutting motor control";
        case CUTTING_SPEED:                                 return "Cutting Speed";
        case RETURN_SPEED:                                  return "Return Speed";
        case HANDWHEEL_POSITION:                            return "Handwheel position";

        default:
        	Log(lError) << "UNKNOWN UC7 message: "<<cmd;	return "UNKNOWN";
    }
}

int hexToDec(const string& hex)
{
	stringstream convert(hex);
    int val;
    convert >> std::hex >> val;
    return val;
}

