#ifndef atArduinoIPCServerReceiverH
#define atArduinoIPCServerReceiverH
#include "dslIPCReceiver.h"
#include "dslIPCServer.h"
#include "core/atATObject.h"
#include "atArduinoExporter.h"
//---------------------------------------------------------------------------

class AT_ARDUINO ArduinoServerIPCReceiver : public dsl::IPCReceiver, public ATObject
{
    public:
						        		ArduinoServerIPCReceiver(int portNr = -1, int socket_handle = -1, dsl::IPCServer* server = NULL);
						        		~ArduinoServerIPCReceiver();
		virtual void                    Worker();

    protected:

};

#endif
