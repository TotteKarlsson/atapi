#ifndef atUC7H
#define atUC7H
#include "atABObject.h"
#include "serial/atSerial.h"
#include "atUC7Message.h"
#include <deque>
#include "Poco/Mutex.h"
//---------------------------------------------------------------------------

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
        bool							sendRawMessage(const string& msg);

        bool							startCutter();
        bool							stopCutter();
        bool							getCutterStatus();
        int								calculateCheckSum(const string& cmd);
        bool							hasMessage();

    protected:
        string							mINIFileSection;
        int								mCOMPort;
    	Serial							mSerial;
        void							onSerialMessage(const string& msg);
        bool							sendUC7Message(const UC7MessageName& uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);

        Poco::Mutex						mBufferMutex;
        Poco::Condition					mNewMessageCondition;
        deque<UC7Message> 				mIncomingMessagesBuffer;


};

#endif
