#ifndef abUtilitiesH
#define abUtilitiesH
#include "atCoreExporter.h"
#include <vector>
#include <string>
#include "mtkStringList.h"
#include "mtkProperty.h"
#include "mtkTypeInfo.h"
#include "mtkIniFile.h"
//---------------------------------------------------------------------------
using std::string;
using std::vector;
using mtk::StringList;
using mtk::Property;
using mtk::IniFile;

//!We are using an enum for process type in order to save/retrieve different processes from XML
enum ProcessType
{
	ptBaseType = 0,
    ptMaster,
    ptParallell,
    ptAbsoluteMove,
    ptArduinoServerCommand,
    ptTimeDelay,
    ptStopAndResumeProcess,
    ptArrayCamRequestProcess,
    ptUnknown
};

AT_CORE string toString(ProcessType tp);
AT_CORE ProcessType toProcessType(const string& str);

//!Logic operators, used in triggers
enum LogicOperator {loLargerThan = 0, loSmallerThan, loLargerThanOrEqual, loSmallerThanOrEqual, loEqualTo, loUndefined};

AT_CORE string 			toString(LogicOperator o);
AT_CORE LogicOperator 	toLogicOperator(const string& p);
AT_CORE string 			tlError(int errCode);




#endif
