#pragma hdrstop
#include "atArrayCamProtocol.h"
//---------------------------------------------------------------------------

map<int, string> ArrayCamProtocol::mRequests;


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

ACRequest ArrayCamProtocol::strToEnum(const string& msg)
{

}

string ArrayCamProtocol::operator[](ACRequest r)
{
	return mRequests[r];
}


