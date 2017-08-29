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
static unsigned int WM_MOTOR_WARNING_MESSAGE 	= WM_APP + 100;
static unsigned int WM_INFO_MESSAGE_DIALOG 		= WM_APP + 101;

void initABCoreLib()
{
	HMODULE	handle 				= LoadLibraryA("atResources");
    WM_MOTOR_WARNING_MESSAGE 	= RegisterWindowMessageA(MOTOR_WARNING_MESSAGE);
    WM_INFO_MESSAGE_DIALOG   	= RegisterWindowMessageA(INFO_MESSAGE_DIALOG);
}

const unsigned int getABCoreMessageID(const string& msg)
{
	if(compareStrings(msg, MOTOR_WARNING_MESSAGE))
    {
    	return WM_MOTOR_WARNING_MESSAGE;
    }
    else if(compareStrings(msg, INFO_MESSAGE_DIALOG))
    {
    	return WM_INFO_MESSAGE_DIALOG;
    }

    return 0;
}





