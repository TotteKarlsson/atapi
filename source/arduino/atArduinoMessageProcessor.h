#ifndef atArduinoMessageProcessorH
#define atArduinoMessageProcessorH
#include <string>
#include "mtkThread.h"
#include "atCoreExporter.h"
#include "atATObject.h"
//----------------------------------------------------------------

using mtk::Thread;

namespace mtk
{
	class MessageContainer;
}

using mtk::MessageContainer;
class ArduinoClient;
typedef void (__closure *OnMessageReceivedCB)(const string& msg);

//!The Arduino Message processor processes messages sent from a
//!Arduino Server.
class AT_CORE ArduinoMessageProcessor : public Thread, public ATObject
{

    public:
                                        ArduinoMessageProcessor(ArduinoClient& client);
                                        ~ArduinoMessageProcessor();

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
		ArduinoClient&					mClient;
};

#endif
