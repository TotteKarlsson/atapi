#ifndef atArrayCamProtocolH
#define atArrayCamProtocolH
#include <map>
#include "core/atCoreExporter.h"
//---------------------------------------------------------------------------
using std::map;


//Put this in a header to be shared between server/client
//!Valid messages/requests enum
AT_CORE enum  ACMessageID
{
	acrStartVideoRecorder = 0,
    acrVideoRecorderStarted,
	acrStopVideoRecorder,
    acrVideoRecorderStopped,
	acrTakeSnapShot,
	acrSnapShotTaken,
    acrEnableBarcodeScanner,
    acrBarcodeScanSucceded,
    acrBarcodeScanFailed,
    acrDisableBarcodeScanner,
    acrBarcodeScannerDisabled,
    acrSetZoomAndFocus,
	acrFocusAndZoomSet,
    acrUnknown
};

class AT_CORE ArrayCamProtocol
{
	public:
							        		ArrayCamProtocol();

		ACMessageID			        		idFromString(const string& msg);
		string 	   			        		operator[](ACMessageID r);
    	static map<ACMessageID, string>   	mIPCMessage;

	private:
	    map<ACMessageID, string>::iterator	mIt;
};

#endif
