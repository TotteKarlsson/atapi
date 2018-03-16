#ifndef atElloUIClientH
#define atElloUIClientH
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
#include "mtkProperty.h"
#include "mtkMessageContainer.h"
#include "atElloUIMessageProcessor.h"
#include "mtkSocketClient.h"

namespace mtk
{
	class SocketClient;
    class Thread;
}

using mtk::SocketClient;
using mtk::Thread;
using mtk::Property;
using mtk::MessageContainer;
using mtk::SocketReceiver;

//!The ElloUI (socket) client class connects to a ElloUI server over a socket.
//!Messages are received, over the socket, by a socket receiver and placed in a message container.
//!Received messages are processed by the ElloUIMessageProcessor.
class AT_CORE ElloUIClient : public SocketClient, public ATObject
{
	friend ElloUIMessageProcessor;
	public:
                                            ElloUIClient();
    	virtual                             ~ElloUIClient();
        virtual bool                        shutDown();

        virtual bool                        init(int pNumber = 50002, const string& hostname = mtk::gEmptyString, bool connectOnInit = true);
        bool                                isConnected();
        bool                                disConnect();
        bool                                connect(int pNumber = 50002, const string& host = mtk::gEmptyString);

		void								run();

									        //!Post a custom message to the message list
        virtual void                        postMessage(const string& msg);
        void		 						assignOnMessageReceivedCallBack(OnMessageReceivedCB cb);

    protected:
        ElloUIMessageProcessor   			mMessageProcessor;
};

#endif
