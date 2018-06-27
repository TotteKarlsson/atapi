#ifndef atCoreH
#define atCoreH
#include "atCoreExporter.h"
#include <string>

#define MOTOR_WARNING_MESSAGE "MOTOR_WARNING_MESSAGE"
#define INFO_MESSAGE_DIALOG "INFO_MESSAGE_DIALOG"

using std::string;

AT_CORE string 				getVersion();
AT_CORE const unsigned int 	getABCoreMessageID(const string& msg);
AT_CORE void 				initABCoreLib();

#endif
