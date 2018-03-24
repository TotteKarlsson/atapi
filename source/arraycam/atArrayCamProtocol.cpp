#pragma hdrstop
#include "atArrayCamProtocol.h"
#include <string>
//---------------------------------------------------------------------------

map<ACMessageID, string> ArrayCamProtocol::mIPCMessage;

ArrayCamProtocol::ArrayCamProtocol()
{
    mIPCMessage[acrStartVideoRecorder] 		    = "Start Video Recorder";
    mIPCMessage[acrVideoRecorderStarted] 	    = "Video Recorder Started";
    mIPCMessage[acrStopVideoRecorder] 		    = "Stop Video Recorder";
    mIPCMessage[acrVideoRecorderStopped] 	    = "Video Recorder Stoppped";
    mIPCMessage[acrTakeSnapShot] 			    = "Take Snapshot";
    mIPCMessage[acrSnapShotTaken] 			    = "Snapshot Taken";
    mIPCMessage[acrEnableBarcodeScanner] 	    = "Enable Barcode Scanner";
    mIPCMessage[acrBarcodeScanSucceded] 	    = "Barcode Scan Succeded";
    mIPCMessage[acrBarcodeScanFailed] 		    = "Barcode Scan Failed";
    mIPCMessage[acrDisableBarcodeScanner]	    = "Disable Barcode Scanner";
    mIPCMessage[acrBarcodeScannerDisabled]	    = "Barcode Scanner Disabled";
    mIPCMessage[acrSetZoomAndFocus]			    = "Set Focus and Zoom";
    mIPCMessage[acrFocusAndZoomSet]			    = "Focus and Zoom Set";
    mIPCMessage[acrZoomIn]					    = "Zoom In";
    mIPCMessage[acrZoomInSet]	  			    = "Zoom In set";
    mIPCMessage[acrZoomOut]					    = "Zoom Out";
    mIPCMessage[acrZoomOutSet]	  			    = "Zoom Out set";

    mIPCMessage[acrFocusIn]					    = "Focus In";
    mIPCMessage[acrFocusInSet]	  			    = "Focus In set";
    mIPCMessage[acrFocusOut]					= "Focus Out";
    mIPCMessage[acrFocusOutSet]	  			    = "Focus Out set";

    mIPCMessage[acrStartUC7]				    = "Start UC7";
    mIPCMessage[acrStopUC7]					    = "Stop  UC7";
    mIPCMessage[acrSetLEDIntensity]			    = "Set LED Intensity";
    mIPCMessage[acrLEDIntensitySet]	  		    = "LED Intensity set";

    mIPCMessage[acrTriggerRibbonSeparator]      = "Trigger Ribbon Separator";
    mIPCMessage[acrRibbonSeparatorTriggered]    = "Ribbon Separator Triggered";

    mIPCMessage[acmBeforeCutting]	 		    = "Before Cutting";
    mIPCMessage[acmCutting]	 				    = "Cutting";
    mIPCMessage[acmAfterCutting]			    = "After Cutting";
    mIPCMessage[acmRetracting]				    = "Retracting";
    mIPCMessage[abrMoveWhiskerForward]		    = "Move Whisker Forward";

    mIPCMessage[acrSetMoveWhiskerForwardOn]		= "Set Move Whisker Forward ON";
    mIPCMessage[acrMoveWhiskerForwardOnSet]     = "Move Whisker Forward ON set";
    mIPCMessage[acrSetMoveWhiskerForwardOff]    = "Set Move Whisker Forward OFF";
    mIPCMessage[acrMoveWhiskerForwardOffSet]    = "Move Whisker Forward OFF set";

    mIPCMessage[acrUnknown]						= "Unknown";
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
