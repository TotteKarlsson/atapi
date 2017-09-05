#pragma hdrstop
#include "atArrayCamProtocol.h"
//---------------------------------------------------------------------------

map<ACMessageID, string> ArrayCamProtocol::mIPCMessage;

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
    mIPCMessage[acrSetZoomAndFocus]			= "Set Focus and Zoom";
    mIPCMessage[acrFocusAndZoomSet]			= "Focus and Zoom Set";
    mIPCMessage[acrStartUC7]				= "Start UC7";
    mIPCMessage[acrStopUC7]					= "Stop  UC7";
    mIPCMessage[acrSetLEDIntensity]			= "Set LED Intensity";
    mIPCMessage[acrLEDIntensitySet]	  		= "LED Intensityr set";

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
