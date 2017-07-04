#ifndef atStopAndResumeProcessH
#define atStopAndResumeProcessH
#include "core/atProcess.h"
#include <vector>
#include "mtkXMLUtils.h"
#include "arraybot/atABExporter.h"
//---------------------------------------------------------------------------
using namespace std;


class AT_AB StopAndResumeProcess : public Process
{
    public:
        	   			                        StopAndResumeProcess(const string& lbl);
    	virtual			                        ~StopAndResumeProcess(){}
		const string 				            getTypeName() const;
		virtual bool 	  	                    write();
	    void						            clear();

        virtual mtk::XMLElement*                addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);

		virtual void		   		            init(ArrayBot& ab);
        virtual bool	                        start();
        virtual bool	                        stop();
        virtual bool	                        isBeingProcessed();
        bool 						            isProcessed();
        bool						            resume();

									            //Check if we are at proper position(s)
        bool 						            isDone();
       	bool	            		            undo(){return true;}

    protected:                                  //!The Resume flag need to be set to true in order for
    								            //!process to finish
		bool						            mResume;
};

#endif
