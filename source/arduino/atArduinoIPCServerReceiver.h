#ifndef atArduinoIPCServerReceiverH
#define atArduinoIPCServerReceiverH
#include "mtkIPCReceiver.h"
#include "mtkIPCServer.h"
#include "atCoreExporter.h"
#include "atATObject.h"
//---------------------------------------------------------------------------

class AT_CORE ArduinoServerIPCReceiver : public mtk::IPCReceiver, public ATObject
{
    public:
						        		ArduinoServerIPCReceiver(int portNr = -1, int socket_handle = -1, mtk::IPCServer* server = NULL);
						        		~ArduinoServerIPCReceiver();
		virtual void                    Worker();

    protected:

};

#endif
