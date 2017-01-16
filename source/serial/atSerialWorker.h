#ifndef abSerialWorkerH
#define abSerialWorkerH
#include "mtkIPCMessageBuilder.h"
#include "mtkThread.h"
#include "atSerialPort.h"
//---------------------------------------------------------------------------

class Serial;
class AT_CORE SerialWorker : public mtk::Thread
{
	public:
                                        SerialWorker(Serial& h, SerialPort& s, char ld = '[', char rd = ']') : mTheHost(h), mSP(s), mMessageBuilder(ld, rd){}
        void			                run();
        Serial&			                mTheHost;
        SerialPort&	 	                mSP;

	private:
    	mtk::IPCMessageBuilder		  	mMessageBuilder;
        int								processReceiveBuffer(char* buffer, int size);
};

#endif
