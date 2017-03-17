#ifndef abArduinoServerH
#define abArduinoServerH
//---------------------------------------------------------------------------
#include "atExporter.h"
#include "atABObject.h"
#include "mtkIPCServer.h"
#include "mtkSocketWorker.h"
#include "atLightsArduino.h"

#include <vector>
#include "mtkTimer.h"
using mtk::IPCServer;
using mtk::IPCMessage;
using std::vector;

mtk::SocketWorker* AT_CORE createArduinoIPCReceiver(int portNr, int socketHandle, void* parent);

typedef void (__closure *OnMessageUpdateCB)(const string& msg);

//!The Arduino server is a component that serve clients with Arduino connections over a
//tcp/ip socket. The Arduino server is designed to handle messages and data related to the
//arraybot project. The Arduino server is a descendant of the IPC server class that is implementing all
//network functionality.
//The Arduino server forwards any messages sent from the arduino board to any connected tcp/ip clients.

//There are currently one Arduino board, the 'Lights' board containing sensors and
//light controlling logic.

class AT_CORE ArduinoServer : public IPCServer
{
    public:
                                            ArduinoServer(int portNumber = 50000);
	                                        ~ArduinoServer();

                                            //!The process message is an overide from the IPCServer base class.
                                            //!Process message implements the arduino server specific processing.
                                            //!These messages are sent to the server from a client.
    	bool 					            processMessage(IPCMessage& msg);

    	LightsArduino& 			            getLightsArduino(){return mLightsArduino;}
        bool            		            shutDown();

        void								assignOnUpdateCallBack(OnMessageUpdateCB cb);
		void								onUpdateClientsTimer();
        void								broadcastStatus();

    protected:
    							            //!Container for Arduino devices
		vector<ArduinoDevice*> 	            mArduinos;

        									//We should create a mutex for each of these
                                            //devices...
    	LightsArduino 			            mLightsArduino;


        OnMessageUpdateCB					onMessageUpdateCB;


		void					            lightsArduinoMessageReceived(const string& msg);

        void								notifyClients(const string& msg);
};

#endif
