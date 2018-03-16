#ifndef atElloUIMessageProcessorH
#define atElloUIMessageProcessorH
#include <string>
#include "mtkThread.h"
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
//----------------------------------------------------------------

using mtk::Thread;

namespace mtk
{
	class MessageContainer;
}

using mtk::MessageContainer;
class ElloUIClient;
typedef void (__closure *OnMessageReceivedCB)(const string& msg);

//!The Message processor processes messages sent from a
//!Server.
class AT_CORE ElloUIMessageProcessor : public Thread, public ATObject
{

    public:
                                        ElloUIMessageProcessor(ElloUIClient& client);
                                        ~ElloUIMessageProcessor();

                                        // overridden from Thread
        void                            worker();
        void                            run();

        bool                            start(bool inThread);
        void                            stop();
        virtual void                    processMessage(const string& msg);
        void                            suspendProcessing() {mAllowProcessing = false;}
        void                            resumeProcessing()  {mAllowProcessing = true;}
		void							assignOnMessageReceivedCallBack(OnMessageReceivedCB cb);

	private:
        string                          mServerName;
        bool                            mAllowProcessing;
        MessageContainer&            	mMessageContainer;
        OnMessageReceivedCB		  		onMessageReceivedCB;
		ElloUIClient&					mClient;
};

#endif
