#pragma hdrstop
#include "atUC7Command.h"
#include "mtkLogger.h"

using namespace mtk;


//---------------------------------------------------------------------------


UC7Command::UC7Command(const string& cmd)
:
mReceiver(0),
mSender(0),
mData(""),
mCheckSum(""),
mCommandString("")
{
	if(!parse(cmd))
    {
    	Log(lError) << "The UC7 command: " <<cmd<<" failed to parse";
    }
}

bool UC7Command::parse(const string& cmd, bool isResponse)
{
	//A command has to be at least 6 chars long
    if(cmd.size() < 6)
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
    mCommandString = cmd[2] + cmd[3];
    mCommandName = toCommandName(mCommandString, mReceiver);

}

string UC7Command::receiver()
{}

string UC7Command::sender()
{}

string UC7Command::command()
{}

string UC7Command::data()
{}

string UC7Command::getMessage()
{}

bool UC7Command::check()
{}

UC7CommandName toCommandName(const string& cmd, char controllerAddress)
{

}

string toString(UC7CommandName cmd)
{
	//This function constructs a proper command to send to the UC7
    switch(cmd)
    {
        case SOFTWARE_RESET:		                        return "F0";
        case GET_PART_ID:			                        return "F1";
        case LOGIN:					                        return "F2";
        case COMMAND_TRANSMISSION_ERROR:                    return "F3";
        case GET_VERSION:                                   return "F5";
        case FEEDRATE_MOTOR_CONTROL:                        return "20";
        case SEND_POSITION_AT_MOTION:                       return "21";
        case FEED:                                          return "23";
        case NORTH_SOUTH_MOTOR_MOVEMENT:                    return "30";
        case SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH:         return "31";
        case EAST_WEST_MOTOR_MOVEMENT:                      return "40";
        case SEND_POSITION_AT_MOVEMENT_EAST_WEST:           return "41";
        case CUTTING_MOTOR_CONTROL:                         return "20";
        case CUTTING_SPEED:                                 return "30";
        case RETURN_SPEED:                                  return "31";
        case HANDWHEEL_POSITION:                            return "40";

        default:
        	Log(lError) << "Bad command: "<<cmd;	   		return "";
}
