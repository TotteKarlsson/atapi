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

typedef void __fastcall (__closure *UICallback)(void);

class AT_CORE UC7MessageConsumer : public ABObject, public mtk::Thread
{
    public:
                                                    UC7MessageConsumer(UC7& list,  const string& threadName = gEmptyString);
                                                    ~UC7MessageConsumer();
        bool                                        openDataBase(const string& db);

                                                    // overridden from Thread
        void                                        run();
        virtual void                                worker();
        void                                        stop();
        bool                                        start(bool in_thread = true);
        void                                        pauseProcessing();
        void                                        resumeProcessing();
        UICallback                                  mNotifyUI;
        //MotorCommandEnum							getLastProcessedMessage();

	protected:
		long                                        mProcessedCount;
		bool                                        mAllowProcessing;
//		MotorCommandEnum							mLastProcessedCommand;
        double										mProcessTimeDelay;
		UC7&                      					mUC7;
};

#endif
