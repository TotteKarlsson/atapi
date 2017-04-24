#ifndef atArrayCamProtocolH
#define atArrayCamProtocolH
#include <map>
#include "atExporter.h"
//---------------------------------------------------------------------------
using std::map;


//Put this in a header to be shared between server/client
//!Valid message request enum
AT_CORE enum  ACRequest
{
	acrStartVideo = 0,
	acrStopVideo,
	acrTakeSnapShot,
    acrEnableBarcodeScanner,
    acrDisableBarcodeScanner,
    acrValidateBarcode,
    acrUnknown
};


class AT_CORE ArrayCamProtocol
{
	public:
							        	ArrayCamProtocol();

		ACRequest			        	request(const string& msg);
		string 	   			        	operator[](ACRequest r);
    	static map<ACRequest, string>   mRequests;

	private:
	    map<ACRequest, string>::iterator	mIt;
};

#endif
