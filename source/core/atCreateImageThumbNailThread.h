#ifndef atCreateImageThumbNailThreadH
#define atCreateImageThumbNailThreadH
#include "core/atATObject.h"
#include "dslThread.h"
#include <functional>
#include "Poco/Process.h"
#include "Poco/Timespan.h"
//---------------------------------------------------------------------------

typedef boost::function<void(int, int)> Callback;

class AT_CORE CreateImageThumbNailThread : public dsl::Thread
{
    public:
								CreateImageThumbNailThread();
								~CreateImageThumbNailThread();
		void					setFFMPEGLocation(const string& loc);
		void					setInputFile(const string& f);
		void					assignCallBacks(Callback one, Callback two, Callback three);

        virtual void            run();
        string 					getInputFileName();

    protected:
    	string					mFFMPEGLocation;
        string					mInputFileName;
	    Callback 				onEnter;
	    Callback 				onProgress;
	    Callback 				onExit;
        int						parseFFMPEGOutput(const string& str);
};

#endif
