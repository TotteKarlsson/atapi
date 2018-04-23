#ifndef atArrayBotRequestH
#define atArrayBotRequestH
#include "../atABExporter.h"
#include "core/atProcess.h"
#include "dslXMLUtils.h"
#include "core/atArrayBotProtocol.h"
#include "atProcessSequenceProject.h"

//---------------------------------------------------------------------------
using namespace std;

class ArrayBotClient;
class AT_AB ArrayBotRequestProcess : public Process
{
	friend ProcessSequenceProject;
    public:
        	   			                            ArrayBotRequestProcess(ArrayBotClient& acc, const string& lbl, const string& request = "");
    	virtual			                            ~ArrayBotRequestProcess(){}
		virtual bool 	   	                        write();
        bool						                setRequest(ABMessageID r);
        bool						                setRequest(const string& request);
		const string 				                getTypeName() const;
	    void						                clear();
        virtual dsl::XMLElement*                    addToXMLDocumentAsChild(dsl::XMLDocument& doc, dsl::XMLNode* docRoot);
        void						                onReceivedResponse(const string& msg);

        virtual bool	                            start();
        virtual bool	                            resume(){return false;}
        virtual bool	                            stop();
        virtual bool	                            isBeingProcessed();
        bool 						                isProcessed();
		ABMessageID					                getRequest(){return mRequest;}

        bool 						                isDone();
       	bool	            		                undo(){return false;}

        											//This is pretty ugly
		Property<double>&							getParameter1(){return mParameter1;}
		Property<double>&							getParameter2(){return mParameter2;}

    protected:                                      //!The ArrayBotRequestProcess is a simple text command
		ABMessageID					                mRequest;

        							                //!The client allows us to send a request to the server
        ArrayBotClient&				                mArrayBotClient;
        Property<double>							mParameter1;
        Property<double>							mParameter2;


};

#endif
