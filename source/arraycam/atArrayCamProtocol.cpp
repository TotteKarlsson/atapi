#pragma hdrstop
#include "atArrayCamProtocol.h"
//---------------------------------------------------------------------------

map<ACRequest, string> ArrayCamProtocol::mRequests;


ArrayCamProtocol::ArrayCamProtocol()
{
    mRequests[acrStartVideo] 			= "Start Video";
    mRequests[acrStopVideo] 			= "Stop Video";
    mRequests[acrTakeSnapShot] 			= "Take Snapshot";
    mRequests[acrEnableBarcodeScanner] 	= "Enable Barcode Scanner";
    mRequests[acrDisableBarcodeScanner]	= "Disable Barcode Scanner";
    mRequests[acrValidateBarcode]		= "Validate Barcode";
    mRequests[acrUnknown]				= "Unknown";
}

ACRequest ArrayCamProtocol::request(const string& r)
{
    map<ACRequest, string>::const_iterator it;
    ACRequest key = acrUnknown;

    for (it = mRequests.begin(); it != mRequests.end(); ++it)
    {
	    if (it->second == r)
    	{
		    key = it->first;
			return key;
	    }
    }

   	return acrUnknown;
}

string ArrayCamProtocol::operator[](ACRequest r)
{
	return mRequests[r];
}
