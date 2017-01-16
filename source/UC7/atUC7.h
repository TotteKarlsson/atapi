#ifndef atUC7H
#define atUC7H
#include "atABObject.h"
#include "serial/atSerial.h"
//---------------------------------------------------------------------------

using mtk::gEmptyString;
//!Simple enum to hold commands
enum UC7Command {SOFTWARE_RESET                             = 0,
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


class AT_CORE UC7 : public ABObject
{
	public:
										UC7();
										~UC7();

		bool							connect(int comPort);
        bool							disConnect();
        bool							isConnected();
        bool							getVersion();
        bool							sendRawMessage(const string& msg);

        bool							startCutter();
        bool							stopCutter();
        bool							getCutterStatus();
        int								calculateCheckSum(const string& cmd);

    protected:
        string							mINIFileSection;
        int								mCOMPort;
    	Serial							mSerial;
        void							onSerialMessage(const string& msg);
        bool							sendUC7Command(UC7Command uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);
		bool    						decodeUC7Command(const string& msg);
};

#endif
