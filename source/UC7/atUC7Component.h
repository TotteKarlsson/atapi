#ifndef atUC7ComponentH
#define atUC7ComponentH
#include "atABObject.h"
#include "serial/atSerial.h"
#include "atUC7Message.h"
#include <deque>
#include "Poco/Mutex.h"
#include "atCounter.h"
#include "atUC7MessageSender.h"
//---------------------------------------------------------------------------

//This class is named UC7, but unit is atUC7Component as not to conflict with
//application name unit UC7

//!Observe that most "get" functions don't return a result immediately. Instead, a request
//!is sent to the UC7 hardware, and a response is be received at a laterstage.
//If a client is querying the UC7 object itself, specify isRequest = false when calling
//getfunctions

using mtk::gEmptyString;
using std::deque;
class UC7MessageConsumer;


class AT_CORE UC7 : public ABObject
{
	friend UC7MessageConsumer;
	friend UC7MessageSender;
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

        bool							startRibbon();
        bool							moveKnifeStageSouth(int nm, bool isRequest = true);
        bool							moveKnifeStageNorth(int nm, bool isRequest= true);

        								//Set Feedrate in nm
        bool							setFeedRate(int feedRate, bool isRequest = true);

										//status requests
                                        //Get all statuses
        bool							getStatus();

        								//Get status of cutter motor, on or off
        bool							getCutterMotorStatus();

        								//Get current feedrate in nm
		int								getCurrentFeedRate(bool isRequest = true);

        								//Get absolute position of stage
        bool							getKnifeStagePosition();

        bool							hasMessage();
        UC7Message						getLastSentMessage();

        void							disableCounter();
        void							enableCounter();
        bool							prepareForNewRibbon(){return mPrepareForNewRibbon;}
        void							prepareForNewRibbon(bool what){mPrepareForNewRibbon = what;}

        bool							prepareToCutRibbon(){return mPrepareToCutRibbon;}
        void							prepareToCutRibbon(bool what){mPrepareToCutRibbon = what;}
        bool							setPresetFeedRate(int rate = -1);

    protected:
        string							mINIFileSection;

										//Serial details
        int								mCOMPort;
    	Serial							mSerial;
        void							onSerialMessage(const string& msg);
        bool							sendUC7Message(const UC7MessageEnum& uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);

        deque<UC7Message> 				mIncomingMessagesBuffer;
        Poco::Mutex						mReceiveBufferMutex;
        Poco::Condition					mNewReceivedMessageCondition;

		deque<string>  					mOutgoingMessagesBuffer;
        Poco::Mutex						mSendBufferMutex;
        Poco::Condition					mNewMessageToSendCondition;

        UC7Message 						mUC7Message;



        								//Hardware states

                                        //!Feedrate in nm
		int								mFeedRate;
		int								mPresetFeedRate;
		int								mKnifeStageJogPreset;
        bool							mPrepareForNewRibbon;
        bool							mPrepareToCutRibbon;

        Counter							mCounter;
        UC7MessageSender				mMessageSender;
};

#endif
