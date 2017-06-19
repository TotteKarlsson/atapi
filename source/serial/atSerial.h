#ifndef abSerialH
#define abSerialH
#include "atCoreExporter.h"
#include "atATObject.h"
#include "mtkStringList.h"
#include "Poco/Mutex.h"
#include "Poco/Condition.h"
#include "atSerialPort.h"
#include "atSerialWorker.h"

using Poco::Mutex;
using Poco::Condition;

using mtk::StringList;
using mtk::IPCMessageBuilder;

typedef void (*SerialMessageReceivedCallBackC)(const string& msg);
typedef void (__closure *SerialMessageReceivedCallBack)(const string& msg);

class AT_CORE Serial : public ATObject
{
	friend SerialWorker;
    public:
                                            //Initialize Serial communication with the given COM port
                                            Serial(int portNr, int rate = 9600, char ld = '[', char rd = ']', SerialPort::EHandshake handShake = SerialPort::EHandshake::EHandshakeOff);
                                            ~Serial();
        bool					            connect(int portNr, int baudRate);

        					                //Check if we are actually connected
        bool 				                isConnected();

                                            //Close the connection
        bool					            disConnect();

        									//!Client checks for messages
		bool					            hasMessage();

        									//!Retrieve message from internal queue
        string					            popMessage();

        									//!Post message to internal output queue
		bool								send(const string& msg);
		bool								send(const unsigned char b);

        void								assignMessageReceivedCallBackC(SerialMessageReceivedCallBackC cb);
        void								assignMessageReceivedCallBack(SerialMessageReceivedCallBack cb);

    private:
        									//!Messages are stored in a list of strings and consumed
                                            //by clients
        StringList				            mReceivedMessages;

		bool								mOverLappedIO;
        						            //Messages from an arduino
		Mutex					            mReceivedMessagesMutex;
		int									mReceiveBufferSize;
		int									mSendBufferSize;

        									//CSerial is doing the underlying serial port work
		SerialPort							mSP;
        SerialPort::EHandshake 				mHandShake;

        									//The serial worker reads data on the serial port
                                            //in a thread. Incoming messages are placed in the mMessages
                                            //list
        SerialWorker						mSerialWorker;
        bool								setupAndOpenSerialPort(int pNr, int baudRate, SerialPort::EHandshake handShake);

        SerialMessageReceivedCallBack	 	mReceivedCB;
        SerialMessageReceivedCallBackC	 	mReceivedCB_C;
        Poco::Condition                     mGotMessage;
};

#endif