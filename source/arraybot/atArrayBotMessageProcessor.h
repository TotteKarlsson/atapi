#ifndef atArrayBotMessageProcessorH
#define atArrayBotMessageProcessorH
#include <string>
#include "mtkThread.h"
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
//----------------------------------------------------------------

using mtk::Thread;
using std::vector;
namespace mtk
{
	class MessageContainer;
}

using mtk::MessageContainer;
class ArrayBotClient;
typedef void (__closure *OnMessageReceivedCB)(const string& msg);

//!The ArrayBot Message processor processes messages sent from a
//!ArrayBot Server.
class AT_CORE ArrayBotMessageProcessor : public Thread, public ATObject
{

    public:
                                        ArrayBotMessageProcessor(ArrayBotClient& client);
                                        ~ArrayBotMessageProcessor();

                                        // overridden from Thread
        void                            worker();
        void                            run();

        bool                            start(bool inThread);
        void                            stop();
        virtual void                    processMessage(const string& msg);
        void                            suspendProcessing() {mAllowProcessing = false;}
        void                            resumeProcessing()  {mAllowProcessing = true;}

        								//Might be nicer to setup a proper subject/observer mechanism
		void							assignOnMessageReceivedCallBack(OnMessageReceivedCB cb);


	private:
        string                          mServerName;
        bool                            mAllowProcessing;
        MessageContainer&            	mMessageContainer;
        vector<OnMessageReceivedCB>		onMessageReceivedCallbacks;

		ArrayBotClient&					mClient;
};

#endif
