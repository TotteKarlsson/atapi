#ifndef atUC7CommandH
#define atUC7CommandH
#include "atABObject.h"
//---------------------------------------------------------------------------

//!Simple enum to hold commands
enum UC7CommandName
				{SOFTWARE_RESET                             = 0,
				 GET_PART_ID 	                            ,
                 LOGIN			                            ,
                 COMMAND_TRANSMISSION_ERROR                 ,
                 GET_VERSION	                            ,

                 FEEDRATE_MOTOR_CONTROL						,
                 SEND_POSITION_AT_MOTION                    ,
                 FEED                                       ,

                 NORTH_SOUTH_MOTOR_MOVEMENT                 ,
                 SEND_POSITION_AT_MOVEMENT_NORTH_SOUTH      ,

                 EAST_WEST_MOTOR_MOVEMENT                   ,
				 SEND_POSITION_AT_MOVEMENT_EAST_WEST        ,

                 CUTTING_MOTOR_CONTROL                      ,
                 CUTTING_SPEED                              ,
                 RETURN_SPEED                               ,
                 HANDWHEEL_POSITION
                };

UC7CommandName toCommandName(const string& cmd, char controllerAddress);
string toString(UC7CommandName cmd);

class AT_CORE UC7Command : public ABObject
{
	public:
					            UC7Command(const string& cmd = "");

        string		            receiver();
        string		            sender();
		string		            command();
		string					data();
		string		            getMessage();
        bool		            check();

	private:
    	char					mReceiver;
        char					mSender;
        string					mData;
        string					mCheckSum;
        string 					mCommandString;
        UC7CommandName			mCommandName;
        bool					parse(const string& cmd, bool isResponse = false);
};

#endif
