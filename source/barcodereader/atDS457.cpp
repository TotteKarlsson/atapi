#pragma hdrstop
#include "atDS457.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;



DS457::DS457(HWND handle)
:
mHandle(handle),
mCOMPort(-1),
mBaudRate(0)
{
}

DS457::~DS457(){}

bool DS457::connect(int port, int baudRate)
{
	mCOMPort = port;
    mBaudRate = baudRate;

    int status = SSIConnect(mHandle, mBaudRate, mCOMPort);

    Log(lInfo) << "DS457 Connect status: "<<status;
    if(status == 0)
    {
//        PostMessage(WM_SENDGETVERSIONMSG, 0,0);
        SetVideoBuffer(		    mCOMPort, 	mVideoData, MAX_VIDEO_LEN);
        SetDecodeBuffer(	    mCOMPort, 	mVideoData, MAX_VIDEO_LEN); // use is mutually exclusive so this is ok
        SetParameterBuffer(	    mCOMPort,   mVideoData, MAX_VIDEO_LEN); // as long as we reset it as soon as we
        SetVersionBuffer(	    mCOMPort, 	mVideoData, MAX_VIDEO_LEN); // get the data
        SetCapabilitiesBuffer(	mCOMPort, 	mVideoData, MAX_VIDEO_LEN);
        return true;
    }
    else
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }
	return false;
}

bool DS457::disconnect()
{
	int status = SSIDisconnect(mHandle, mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::isConnected()
{
    return IsConnected(mCOMPort);
}

const unsigned char* DS457::getMemoryBuffer() const
{
	return mVideoData;
}

bool DS457::scanEnable()
{
  	int status = ScanEnable(mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::scanDisable()
{
  	int status = ScanDisable(mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::beep(int b)
{
	int status = SoundBeeper(mCOMPort, b);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::aimOn()
{
	int status = AimOn(mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::aimOff()
{
	int status = AimOff(mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::LEDsOn()
{
	int status = LedOn(mCOMPort, 1);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::LEDsOff()
{
	int status = LedOff(mCOMPort, 1);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::illuminationOn()
{
	int status = IlluminationOn(mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}

bool DS457::illuminationOff()
{
	int status = IlluminationOff(mCOMPort);
    if(status)
    {
    	Log(lError) << "The barcodereader returned with an Error. Error ID = " << status;
    }

	return status == 0 ? true : false;
}
