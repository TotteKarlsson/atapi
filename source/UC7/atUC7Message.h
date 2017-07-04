#ifndef atUC7MessageH
#define atUC7MessageH
#include "core/atATObject.h"
//---------------------------------------------------------------------------

const int gStepperControllerAddress = 4;
const int gMotorControllerAddress   = 5;
const int gSystemCommands  			= 8;


//!Simple enum to hold commands
enum UC7MessageEnum
{
    SOFTWARE_RESET                             = 0,
	GET_PART_ID 	                           ,
    LOGIN			                           ,
    COMMAND_TRANSMISSION_ERROR                 ,
    GET_VERSION	                               ,

    FEEDRATE_MOTOR_CONTROL					   ,
    SEND_POSITION_AT_MOTION                    ,
    FEED                                       ,

    NORTH_SOUTH_MOTOR_MOVEMENT                 ,
    SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH      ,

    EAST_WEST_MOTOR_MOVEMENT                   ,
    SEND_POSITION_AT_MOVEMENT_EAST_WEST        ,

    CUTTING_MOTOR_CONTROL                      ,
    CUTTING_SPEED                              ,
    RETURN_SPEED                               ,
    HANDWHEEL_POSITION						   ,
    UNKNOWN
};

UC7MessageEnum toCommandName(const string& cmd, int controllerAddress);
string toShortString(UC7MessageEnum cmd);
string toLongString(UC7MessageEnum cmd);

class AT_CORE UC7Message : public ATObject
{
	public:
					            UC7Message(const string& cmd = "", bool hasCS = false, bool isResponse = false);
		bool					init(const string& cmd, bool hasCS = false);
        string		            getReceiver() const;
        string		            getSender() const;
		string		            getCommand() const;
		string					getData() const;

		string		            getMessage() const;
		string		            getFullMessage() const;

        string					getCheckSum() const;
        string					getMessageNameAsString() const;
        string					getXX() const;

        bool					calculateCheckSum();
        bool		            check() const;

	private:
    	string 					mReceiver;
        string 					mSender;
        string					mData;
        string					mCheckSum;
        string 					mCommandString;
        bool					mIsResponse;

        UC7MessageEnum			mCommandNameEnum;
        bool					parse(const string& cmd, bool isResponse = false);
};

#endif
