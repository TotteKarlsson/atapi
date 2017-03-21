#ifndef abArduinoServerCommandH
#define abArduinoServerCommandH
#include "atExporter.h"
#include "process/atProcess.h"
//---------------------------------------------------------------------------

class ArduinoClient;

//!The switch class allow a 'switched' process to be executed
//!Arraybot can execute a Arduino command, like Activate Vacuum using an
//!Arduino server command and
class AT_CORE ArduinoServerCommand : public Process
{
    public:
        	   			                    ArduinoServerCommand(const string& lbl);
    	virtual			                    ~ArduinoServerCommand(){}
		const string 						getTypeName() const;
		virtual void		   		        init(ArrayBot& ab);

		virtual mtk::XMLElement*            addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

        virtual bool	                    isBeingProcessed();
        bool 						        isProcessed();
        virtual	bool	                    undo();

        void								setArduinoClient(ArduinoClient* c){mArduinoClient = c;}
        void								setCommand(const string& c){mCommand = c;}

        virtual bool	                    start();
        virtual bool	                    stop(){return Process::stop();}
        virtual bool 				        isDone();

    protected:
        Trigger*							mTrigger;
        string								mCommand;
        ArduinoClient*                      mArduinoClient;
};

#endif
