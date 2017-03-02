#pragma hdrstop
#include <windows.h>
#include "atCore.h"
#include "mtkStringUtils.h"
#include "mtkWin32Utils.h"
using namespace mtk;

//Module entry point..
extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

//These integers are local data in the DLL
static unsigned int WM_MOTOR_WARNING_MESSAGE = 0;

void initABCoreLib()
{
	HMODULE	handle = LoadLibraryA("atResources");
    WM_MOTOR_WARNING_MESSAGE = RegisterWindowMessageA(MOTOR_WARNING_MESSAGE);
}

unsigned int getABCoreMessageID(const string& msg)
{
	if(compareStrings(msg, MOTOR_WARNING_MESSAGE))
    {
    	return WM_MOTOR_WARNING_MESSAGE;
    }
    return 0;
}





