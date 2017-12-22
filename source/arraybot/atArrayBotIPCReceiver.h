#ifndef atArrayBotIPCReceiverH
#define atArrayBotIPCReceiverH
#include "mtkIPCReceiver.h"
#include "mtkIPCServer.h"
#include "arraybot/atABExporter.h"
//---------------------------------------------------------------------------

using mtk::SocketWorker;
SocketWorker* AT_AB createArrayBotIPCReceiver(int portNr, int socketHandle, void* server);

class AT_AB ArrayBotIPCReceiver : public mtk::IPCReceiver
{
    public:
						        		ArrayBotIPCReceiver(int portNr = -1, int socket_handle = -1, mtk::IPCServer* server = NULL);
						        		~ArrayBotIPCReceiver();
		virtual void                    Worker();

    protected:

};

#endif
