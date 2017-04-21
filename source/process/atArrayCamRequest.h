#ifndef abArrayCamRequestH
#define abArrayCamRequestH
#include "atProcess.h"
#include <vector>
#include "mtkXMLUtils.h"
#include "clients/ArrayCamClient.h"
//---------------------------------------------------------------------------
using namespace std;


class AT_CORE ArrayCamRequest : public Process
{
    public:
        	   			            ArrayCamRequest(const string& lbl, const string& request = "");
    	virtual			            ~ArrayCamRequest(){}
        bool						setArrayCamRequest(const string& request){mArrayCamRequest = request; return true;}
		const string 				getTypeName() const;

	    void						clear();

        virtual mtk::XMLElement*    addToXMLDocumentAsChildProcess(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

        virtual bool	            start();
        virtual bool	            stop();
        virtual bool	            isBeingProcessed();
        bool 						isProcessed();
		string						getArrayCamRequest(){return mArrayCamRequest;}

									//Check if we are at proper position(s)
        bool 						isDone();
       	bool	            		undo(){return true;}

    protected:                      //!The ArrayCamRequest is a simple text command
		string						mArrayCamRequest;
        ArrayCamClient&				mAClient;
};

#endif
