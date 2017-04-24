#ifndef atArrayCamProtocolH
#define atArrayCamProtocolH
#include <map>
#include "atExporter.h"
//---------------------------------------------------------------------------
using std::map;


//Put this in a header to be shared between server/client
//!Valid message request enum
AT_CORE enum  ACRequest {	acrStartVideo = 0,
					acrStopVideo,
				 	acrTakeSnapShot,
                    acrEnableBarcodeScanner,
                 	acrDisableBarcodeScanner,
                    acrValidateBarcode,
                    acrUnknown};


string 	requestToString(ACRequest r);
ACRequest arrayCamRequestFromString(const string& t);


class AT_CORE ArrayCamProtocol
{
	public:
							        ArrayCamProtocol();

		ACRequest			        strToEnum(const string& msg);
		string 	   			        operator[](ACRequest r);
    	static map<int, string>   	mRequests;

	private:
};

//AT_CORE ArrayCamProtocol gArrayCamProtocol;

#endif
