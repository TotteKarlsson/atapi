#ifndef atArduinoIPCServerReceiverH
#define atArduinoIPCServerReceiverH
#include "mtkIPCReceiver.h"
#include "mtkIPCServer.h"
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
#include "atArduinoExporter.h"
//---------------------------------------------------------------------------

class AT_ARDUINO ArduinoServerIPCReceiver : public mtk::IPCReceiver, public ATObject
{
    public:
						        		ArduinoServerIPCReceiver(int portNr = -1, int socket_handle = -1, mtk::IPCServer* server = NULL);
						        		~ArduinoServerIPCReceiver();
		virtual void                    Worker();

    protected:

};

#endif
