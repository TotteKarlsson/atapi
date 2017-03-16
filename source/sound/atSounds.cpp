#pragma hdrstop
#include "atSounds.h"
#include "mtkWin32Utils.h"
#include <windows.h>

//---------------------------------------------------------------------------

using namespace mtk;

string getSoundResourceName(ABSound a)
{
	switch(a)
    {
    	case absMotorStop: 		return "MOTOR_STOP_SOUND";
    	case absMotorWarning: 	return "MOTOR_WARNING_SOUND";

        case absSlowSpeed:
        case absAlert1:			return "ALERT_1";

	    case absMediumSpeed:    return "BOING_1";
    	case absFastSpeed:		return "BUTTON_CLICK_5";

		case absBeforeBackOff:	return "SHORT_BEEP_1";

		case absButtonClick4:
        case absDefaultClick:	return "BUTTON_CLICK_4";

        default: 	  			return "MOTOR_WARNING_SOUND";
    }
}

//Non working SHORT_BEEP_1, CLOSING_DOWN_1, SHORT_BEEP_2

void playABSound(ABSound a, long flags)
{
	string fName(getSoundResourceName(a));
	PlayResource(fName, flags);
}

bool PlayResource(const string& resName, long flags)
{
	try
    {
        HINSTANCE modHandle = GetModuleHandle("atResources.dll");
        HRSRC hResInfo= FindResourceA(modHandle, resName.c_str(), RT_RCDATA);
        if(hResInfo == NULL)
        {
            string err = getLastWin32Error();
            Log(lError) << "Failed loading resource. Error was: "<<err;
           return false;
        }

        HANDLE hRes = LoadResource(modHandle, hResInfo);
        if(hRes == NULL)
        {
            return false;
        }

        LPSTR lpRes = (LPSTR) LockResource(hRes);
        if(lpRes == NULL)
        {
            return false;
        }

        if(PlaySound(lpRes, modHandle, SND_MEMORY | flags)  == false)
        {
            string error = getLastWin32Error();
            return false;
        }

        /* Free the WAVE resource and return success or failure. */
        FreeResource(hRes);
    }
    catch(...)
    {
    	Log(lError) << "Problem playing sound...";
    }
    return true;
}

