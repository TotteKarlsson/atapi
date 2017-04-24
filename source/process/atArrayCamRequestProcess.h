#ifndef abArrayCamRequestH
#define abArrayCamRequestH
#include "atProcess.h"
#include "mtkXMLUtils.h"
#include "arraycam/atArrayCamProtocol.h"
//---------------------------------------------------------------------------
using namespace std;

class ArrayCamClient;
class AT_CORE ArrayCamRequestProcess : public Process
{
    public:
        	   			            ArrayCamRequestProcess(const string& lbl, const string& request = "");
    	virtual			            ~ArrayCamRequestProcess(){}
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

    protected:                      //!The ArrayCamRequestProcess is a simple text command
		ACRequest					mRequest;

        							//!The client allows us to send a request to the server
        ArrayCamClient*				mArrayCamClient;

};

#endif
