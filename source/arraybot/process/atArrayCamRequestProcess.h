#ifndef abArrayCamRequestH
#define abArrayCamRequestH
#include "atProcess.h"
#include "mtkXMLUtils.h"
#include "arraycam/atArrayCamProtocol.h"
//---------------------------------------------------------------------------
using namespace std;

class ArrayCamClient;
class AT_AB ArrayCamRequestProcess : public Process
{
    public:
        	   			            ArrayCamRequestProcess(ArrayCamClient& acc, const string& lbl, const string& request = "");
    	virtual			            ~ArrayCamRequestProcess(){}
        bool						setRequest(ACMessageID r);
        bool						setRequest(const string& request);
		const string 				getTypeName() const;
	    void						clear();
        virtual mtk::XMLElement*    addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);
        void						onReceivedResponse(const string& msg);

        virtual bool	            start();
        virtual bool	            stop();
        virtual bool	            isBeingProcessed();
        bool 						isProcessed();
		ACMessageID					getRequest(){return mRequest;}

        bool 						isDone();
       	bool	            		undo(){return true;}

    protected:                      //!The ArrayCamRequestProcess is a simple text command
		ACMessageID					mRequest;

        							//!The client allows us to send a request to the server
        ArrayCamClient&				mArrayCamClient;

};

#endif
