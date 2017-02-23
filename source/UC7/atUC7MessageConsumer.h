#ifndef atUC7MessageConsumerH
#define atUC7MessageConsumerH
#include "atExporter.h"
#include <string>
#include "mtkThread.h"
#include "atABObject.h"
#include "mtkConstants.h"
#include "mtkStringList.h"
#include "atUC7MessageConsumer.h"

//---------------------------------------------------------------------------
class UC7;
using mtk::gEmptyString;

//The message consumer monitors the referenced UC7 object for new
//messages. When a new message is available, the message is popped
//from the UC7 queue and propagated to the main UI, which is responsible
//to handle it.

class AT_CORE UC7MessageConsumer : public ABObject, public mtk::Thread
{
    public:
                                                    UC7MessageConsumer(UC7& list,  HWND__ *h, const string& threadName = gEmptyString);
                                                    ~UC7MessageConsumer();

                                                    // overridden from Thread
        void                                        run();
        virtual void                                worker();
        void                                        stop();
        bool                                        start(bool in_thread = true);
        void                                        pauseProcessing();
        void                                        resumeProcessing();

	protected:
		long                                        mProcessedCount;
		bool                                        mAllowProcessing;
        double										mProcessTimeDelay;
		UC7&                      					mUC7;

        											//The handle is needed for window messaging
        HWND__*										mHandle;
};

#endif
