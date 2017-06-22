#ifndef atArrayCamMessageProcessorH
#define atArrayCamMessageProcessorH
#include <string>
#include "mtkThread.h"
#include "atCoreExporter.h"
#include "atATObject.h"
//----------------------------------------------------------------

using mtk::Thread;
using std::vector;
namespace mtk
{
	class MessageContainer;
}

using mtk::MessageContainer;
class ArrayCamClient;
typedef void (__closure *OnMessageReceivedCB)(const string& msg);

//!The ArrayCam Message processor processes messages sent from a
//!ArrayCam Server.
class AT_CORE ArrayCamMessageProcessor : public Thread, public ATObject
{

    public:
                                        ArrayCamMessageProcessor(ArrayCamClient& client);
                                        ~ArrayCamMessageProcessor();

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

		ArrayCamClient&					mClient;
};

#endif