#ifndef atUC7H
#define atUC7H
#include "atABObject.h"
#include "serial/atSerial.h"
#include "atUC7Command.h"
#include <deque>
#include "Poco/Mutex.h"
//---------------------------------------------------------------------------

using mtk::gEmptyString;
using std::deque;

class AT_CORE UC7 : public ABObject
{
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

    protected:
        string							mINIFileSection;
        int								mCOMPort;
    	Serial							mSerial;
        void							onSerialMessage(const string& msg);
        bool							sendUC7Command(const UC7CommandName& uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);

        Poco::Mutex						mBufferMutex;
        Poco::Condition					mNewMessageCondition;
        deque<UC7Command> 				mIncomingMessagesBuffer;


};

#endif
