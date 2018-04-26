#include <System.hpp>
#pragma hdrstop
#include "TMotorFrame.h"
#include "TMotorPositionFrame.h"
USEFORM("..\..\source\vcl\aptFrames\TMotorPositionFrame.cpp", MotorPositionFrame); /* TFrame: File Type */
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------
#pragma argsused
extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

static inline void ValidCtrCheck(TMotorFrame *)
{
  new TMotorFrame("", NULL);
}

namespace Tmotorframe
{
    void __fastcall PACKAGE Register()
    {
        TComponentClass classes[1] = {__classid(TMotorFrame)};
        RegisterComponents("AIComponents", classes, 0);
    }
}

static inline void ValidCtrCheck(TMotorPositionFrame *)
{
  new TMotorPositionFrame(NULL, NULL);
}

namespace Tmotorpositionframe
{
    void __fastcall PACKAGE Register()
    {
        TComponentClass classes[1] = {__classid(TMotorPositionFrame)};
        RegisterComponents("AIComponents", classes, 0);
    }
}

//---------------------------------------------------------------------------
#pragma comment(lib, "dslCommon.lib")
#pragma comment(lib, "dslVCLCommon.lib")
#pragma comment(lib, "dslVCLComponents.bpi")

#pragma comment(lib, "atArrayBotCore.lib")
