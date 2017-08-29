#ifndef abArrayCamRequestH
#define abArrayCamRequestH
#include "../atABExporter.h"
#include "core/atProcess.h"
#include "mtkXMLUtils.h"
#include "arraycam/atArrayCamProtocol.h"
#include "atProcessSequenceProject.h"

//---------------------------------------------------------------------------
using namespace std;

class ArrayCamClient;
class AT_AB ArrayCamRequestProcess : public Process
{
	friend ProcessSequenceProject;
    public:
        	   			                            ArrayCamRequestProcess(ArrayCamClient& acc, const string& lbl, const string& request = "");
    	virtual			                            ~ArrayCamRequestProcess(){}
		virtual bool 	   	                        write();
        bool						                setRequest(ACMessageID r);
        bool						                setRequest(const string& request);
		const string 				                getTypeName() const;
	    void						                clear();
        virtual mtk::XMLElement*                    addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);
        void						                onReceivedResponse(const string& msg);

        virtual bool	                            start();
        virtual bool	                            resume(){return false;}
        virtual bool	                            stop();
        virtual bool	                            isBeingProcessed();
        bool 						                isProcessed();
		ACMessageID					                getRequest(){return mRequest;}

        bool 						                isDone();
       	bool	            		                undo(){return false;}

        											//This is pretty ugly
		Property<double>&							getParameter1(){return mParameter1;}
		Property<double>&							getParameter2(){return mParameter2;}

    protected:                                      //!The ArrayCamRequestProcess is a simple text command
		ACMessageID					                mRequest;

        							                //!The client allows us to send a request to the server
        ArrayCamClient&				                mArrayCamClient;
        Property<double>							mParameter1;
        Property<double>							mParameter2;


};

#endif
