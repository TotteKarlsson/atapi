#ifndef atUC7ComponentH
#define atUC7ComponentH
#include "atABObject.h"
#include "serial/atSerial.h"
#include "atUC7Message.h"
#include <deque>
#include "Poco/Mutex.h"
#include "atCounter.h"
//---------------------------------------------------------------------------

//This class is named UC7, but unit is atUC7Component as not to conflict with
//application name unit UC7

//!Observe that most "get" functions don't return a result immediately. Instead, a request
//!is sent to the UC7 hardware, and a response is be received at a laterstage. I.e. this
//!code can be said to be event driven
using mtk::gEmptyString;
using std::deque;
class UC7MessageConsumer;

class AT_CORE UC7 : public ABObject
{
	friend UC7MessageConsumer;
	public:
										UC7();
										~UC7();

		bool							connect(int comPort);
        bool							disConnect();
        bool							isConnected();
        bool							getVersion();

        Counter&						getCounter(){return mCounter;}
        bool							sendRawMessage(const string& msg);
        bool							sendByte(const unsigned char b);

        bool							startCutter();
        bool							stopCutter();

        								//Set Feedrate in nm
        bool							setFeedRate(int feedRate);

										//status requests
                                        //Get all statuses
        bool							getStatus();

        								//Get status of cutter motor, on or off
        bool							getCutterMotorStatus();

        								//Get current feedrate in nm
		bool							getCurrentFeedRate();

        								//Get absolute position of stage
        bool							getKnifeStagePosition();

        bool							hasMessage();
        UC7Message						getLastSentMessage();


    protected:
        string							mINIFileSection;
        int								mCOMPort;
    	Serial							mSerial;
        void							onSerialMessage(const string& msg);
        bool							sendUC7Message(const UC7MessageEnum& uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);

        Poco::Mutex						mBufferMutex;
        Poco::Condition					mNewMessageCondition;
        UC7Message 						mUC7Message;
        deque<UC7Message> 				mIncomingMessagesBuffer;
        Counter							mCounter;
};

#endif
