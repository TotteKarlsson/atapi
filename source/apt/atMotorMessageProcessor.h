#ifndef abMotorMessageProcessorH
#define abMotorMessageProcessorH
#include "atExporter.h"
#include <string>
#include "mtkThread.h"
#include "atATObject.h"
#include "mtkConstants.h"
#include "mtkStringList.h"
#include "atMotorMessageProcessor.h"
#include "atMotorCommand.h"
//---------------------------------------------------------------------------
class MotorMessageContainer;
class APTMotor;
using mtk::StringList;

using mtk::gEmptyString;
typedef void __fastcall (__closure *UICallback)(void);

class AT_CORE MotorMessageProcessor : public mtk::Thread, public ATObject
{
    public:
                                                    MotorMessageProcessor(MotorMessageContainer& list, const string& threadName=gEmptyString);
                                                    ~MotorMessageProcessor();
        bool                                        openDataBase(const string& db);

                                                    // overridden from Thread
        void                                        run();
        virtual void                                worker();
        void                                        stop();
        bool                                        start(bool in_thread = true);
        void										assignMotor(APTMotor* motor);

        void                                        pauseProcessing();
        void                                        resumeProcessing();
        UICallback                                  mNotifyUI;
        MotorCommandEnum							getLastProcessedMessage();

	protected:
		long                                        mProcessedCount;
		bool                                        mAllowProcessing;
		MotorCommandEnum							mLastProcessedCommand;
        APTMotor*									mMotor;
        double										mProcessTimeDelay;
		MotorMessageContainer&                      mMotorMessageContainer;
};

#endif
