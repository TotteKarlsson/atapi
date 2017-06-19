#ifndef atArduinoUtilsH
#define atArduinoUtilsH
#include "atCoreExporter.h"
#include <string>
//---------------------------------------------------------------------------
using std::string;

int 	AT_CORE getArduinoIPCMessageID(const string& msg);
string  AT_CORE getArduinoIPCMessageName(int cs);

enum AB_IPC_ID
{
        cMakeAPuff            	= 500,
        cSetPufferPuffDuration 	= 501
};

#endif
