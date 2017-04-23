#ifndef abArrayCamRequestH
#define abArrayCamRequestH
#include "atProcess.h"
#include <vector>
#include "mtkXMLUtils.h"
#include "clients/ArrayCamClient.h"
//---------------------------------------------------------------------------
using namespace std;

enum  ACRequest {acrStartVideo = 0, acrStopVideo,
				 acrTakeSnapShot, acrEnableBarcodeScanner,
                 acrDisableBarcodeScanner, acrValidateBarcode, acrUnknown};

string 	requestToString(ACRequest r);
ACRequest arrayCamRequestFromString(const string& t);

class AT_CORE ArrayCamRequest : public Process
{
    public:
        	   			            ArrayCamRequest(const string& lbl, const string& request = "");
    	virtual			            ~ArrayCamRequest(){}

        bool						setRequest(ACRequest r);
        bool						setRequest(const string& request);
		const string 				getTypeName() const;
		bool						assignArrayCamClient(ArrayCamClient* acc);
	    void						clear();

        virtual mtk::XMLElement*    addToXMLDocumentAsChildProcess(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

        virtual bool	            start();
        virtual bool	            stop();
        virtual bool	            isBeingProcessed();
        bool 						isProcessed();
		ACRequest					getRequest(){return mRequest;}


									//Check if we are at proper position(s)
        bool 						isDone();
       	bool	            		undo(){return true;}

    protected:                      //!The ArrayCamRequest is a simple text command
		ACRequest					mRequest;
        ArrayCamClient*				mArrayCamClient;

};

#endif
