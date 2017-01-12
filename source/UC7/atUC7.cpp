#pragma hdrstop
#include "atUC7.h"
#include "mtkIniFile.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------

using namespace mtk;

UC7::UC7()
:
	mINIFileSection("UC7"),
    mCOMPort(-1),
    mSerial(-1, 19200)
{}

UC7::~UC7()
{
	disConnect();
}

bool UC7::connect(int com)
{
	Log(lInfo) << "Connecting UC7 client on COM"<<com;
    mSerial.connect(com, 19200);
}

bool UC7::disConnect()
{
	return mSerial.disConnect();
}

bool UC7::isConnected()
{
	return mSerial.isConnected();
}

string UC7::getVersion()
{}



