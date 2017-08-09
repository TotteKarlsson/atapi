#ifndef atArrayCamClientH
#define atArrayCamClientH
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
#include "mtkProperty.h"
#include "mtkMessageContainer.h"
#include "atArrayCamMessageProcessor.h"
#include "mtkSocketClient.h"
#include "atArrayCamProtocol.h"

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

//!The client class connects to a server over a socket.
//!Messages are received, over the socket, by a socket receiver and placed in a message container.
//!Received messages are processed by the MessageProcessor.
class AT_CORE ArrayCamClient : public SocketClient, public ATObject
{
	friend ArrayCamMessageProcessor;
	public:
                                            ArrayCamClient();
    	virtual                             ~ArrayCamClient();
        virtual bool                        shutDown();

        virtual bool                        init(int pNumber = 50001, const string& hostname = mtk::gEmptyString, bool connectOnInit = true);
        bool                                isConnected();
        bool                                disConnect();
        bool                                connect(int pNumber = -1, const string& host = mtk::gEmptyString);

		virtual void	 					getBoardStatus(){}
		void								getServerStatus();
        bool								startVideo();
        bool								stopVideo();

        bool								setZoomAndFocus(int zoom, int focus);

        bool								takeSnapShot();
        bool								enableBarcodeScanner();
        bool								disableBarcodeScanner();

									        //!Post a custom request
        bool 		                        postRequest(const string& msg);
        bool 		                        postRequest(const string& msg, int p1, int p2);

        void		 						assignOnMessageReceivedCallBack(OnMessageReceivedCB cb);


    protected:
        ArrayCamMessageProcessor   			mMessageProcessor;
        ArrayCamProtocol					mProtocol;

};

#endif
