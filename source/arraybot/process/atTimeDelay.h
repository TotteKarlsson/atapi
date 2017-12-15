#ifndef atTimeDelayH
#define atTimeDelayH
#include "core/atProcess.h"
#include <vector>
#include "mtkXMLUtils.h"
#include "arraybot/atABExporter.h"
//---------------------------------------------------------------------------
using namespace std;


class AT_AB TimeDelay : public Process
{
    public:
        	   			                    TimeDelay(const string& lbl, Poco::Timespan ts = Poco::Timespan(1000*Poco::Timespan::MILLISECONDS));
    	virtual			                    ~TimeDelay(){}
        bool						        setTimeDelay(long delay){mTimeDelay = delay; return true;}
		const string 				        getTypeName() const;
		virtual bool 			            write();
	    void						        clear();

        virtual mtk::XMLElement*            addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

        virtual bool	                    start();
        virtual bool	                    resume(){return false;}
        virtual bool	                    stop();
        virtual bool	                    isBeingProcessed();
        bool 						        isProcessed();
		Poco::Timespan				        getTimeDelay(){return mTimeDelay;}

									        //Check if we are at proper position(s)
        bool 						        isDone();
       	bool	            		        undo(){return true;}

    protected:                              //!The TimeDelay is represented with a Poco Timespan
		Poco::Timespan				        mTimeDelay;
};

#endif
