#ifndef atCoreH
#define atCoreH
#include "core/atCoreExporter.h"

#define MOTOR_WARNING_MESSAGE "MOTOR_WARNING_MESSAGE"
#define INFO_MESSAGE_DIALOG "INFO_MESSAGE_DIALOG"

AT_CORE const unsigned int 	getABCoreMessageID(const string& msg);
AT_CORE void 				initABCoreLib();


#endif
