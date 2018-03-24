#ifndef atArduinoClientH
#define atArduinoClientH
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
#include "dslProperty.h"
#include "dslMessageContainer.h"
#include "atArduinoMessageProcessor.h"
#include "IPC/dslSocketClient.h"

namespace dsl
{
	class SocketClient;
    class Thread;
}

using dsl::SocketClient;
using dsl::Thread;
using dsl::Property;
using dsl::MessageContainer;
using dsl::SocketReceiver;

//!The Arduino (socket) client class connects to a server over a socket.
//!Messages are received, over the socket, by a socket receiver and placed in a message container.
//!Received messages are processed by the ArduinoMessageProcessor.
class AT_ARDUINO ArduinoClient : public SocketClient, public ATObject
{
	friend ArduinoMessageProcessor;
	public:
                                            ArduinoClient();
    	virtual                             ~ArduinoClient();
        virtual bool                        shutDown();

        virtual bool                        init(int pNumber = 50010, const string& hostname = dsl::gEmptyString, bool connectOnInit = true);
        bool                                isConnected();
        bool                                disConnect();
        bool                                connect(int pNumber = -1, const string& host = dsl::gEmptyString);

		virtual void	 					getBoardStatus(){}
		void								getServerStatus();

									        //!Post a custom message to the message list
        virtual void                        postMessage(const string& msg);
        void		 						assignOnMessageReceivedCallBack(OnMessageReceivedCB cb);

    protected:
        ArduinoMessageProcessor   			mMessageProcessor;
};

#endif
