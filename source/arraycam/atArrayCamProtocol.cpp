#pragma hdrstop
#include "atArrayCamProtocol.h"
//---------------------------------------------------------------------------

map<ACMessageID, string> ArrayCamProtocol::mIPCMessage;

//	acrStartVideoRecording = 0,
//  acrVideoRecorderStarted,
//	acrStopVideoRecorder,
//  acrVideoRecorderStopped,
//	acrTakeSnapShot,
//	acrSnapShotTaken,
//  acrEnableBarcodeScanner,
//  acrBarcodeScanSucceded,
//  acrBarcodeScanFailed,
//  acrDisableBarcodeScanner,
//  acrBarcodeScannerDisabled,
//  acrUnknown

ArrayCamProtocol::ArrayCamProtocol()
{
    mIPCMessage[acrStartVideoRecorder] 		= "Start Video Recorder";
    mIPCMessage[acrVideoRecorderStarted] 	= "Video Recorder Started";
    mIPCMessage[acrStopVideoRecorder] 		= "Stop Video Recorder";
    mIPCMessage[acrTakeSnapShot] 			= "Take Snapshot";
    mIPCMessage[acrSnapShotTaken] 			= "Snapshot Taken";
    mIPCMessage[acrEnableBarcodeScanner] 	= "Enable Barcode Scanner";
    mIPCMessage[acrBarcodeScanSucceded] 	= "Barcode Scan Succeded";
    mIPCMessage[acrBarcodeScanFailed] 		= "Barcode Scan Failed";
    mIPCMessage[acrDisableBarcodeScanner]	= "Disable Barcode Scanner";
    mIPCMessage[acrBarcodeScannerDisabled]	= "Barcode Scanner Disabled";
    mIPCMessage[acrSetZoomAndFocus]			= "Set Zoom and Focus";

    mIPCMessage[acrUnknown]					= "Unknown";
}

ACMessageID ArrayCamProtocol::idFromString(const string& r)
{
    map<ACMessageID, string>::const_iterator it;
    ACMessageID key = acrUnknown;

    for (it = mIPCMessage.begin(); it != mIPCMessage.end(); ++it)
    {
	    if (it->second == r)
    	{
		    key = it->first;
			return key;
	    }
    }

   	return acrUnknown;
}

string ArrayCamProtocol::operator[](ACMessageID r)
{
	return mIPCMessage[r];
}
