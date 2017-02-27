#ifndef atUC7ComponentH
#define atUC7ComponentH
#include "atABObject.h"
#include "serial/atSerial.h"
#include "atUC7Message.h"
#include <deque>
#include "Poco/Mutex.h"
#include "atCounter.h"
#include "atUC7MessageSender.h"
#include "mtkTimer.h"

//---------------------------------------------------------------------------
//!This class is named UC7, but unit is atUC7Component as not to conflict with
//application name unit UC7

//!Observe that most "get" functions below don't return a result immediately. Instead, a request
//!is sent to the UC7 hardware, and a response is be received at a laterstage.
//!If a client is querying the UC7 object itself, specify isRequest = false when calling
//!getfunctions, the current (sw) state is returned.

using mtk::gEmptyString;
using std::deque;
class UC7MessageConsumer;

class AT_CORE UC7 : public ABObject
{
	friend UC7MessageConsumer;
	friend UC7MessageSender;

	public:
        enum EStrokeState 				{ssCutting, ssAfterCutting, ssRetracting, ssBeforeCutting, ssUndefined};

	public:
										UC7(HWND__ *h);
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

        								//!The start ribbon will cause the
                                        //!knife stage to move north,
                                        //!an also change cutrate to preset cutrate
        bool							startRibbon();

        bool							moveKnifeStageSouth(int nm, bool isRequest = true);
        bool							moveKnifeStageNorth(int nm, bool isRequest = true);

        								//!Set Feedrate in nm
        bool							setFeedRate(int feedRate, bool isRequest = true);

										//status requests
                                        //!Get all statuses
        bool							getStatus();

        								//!Get status of cutter motor, on/off
        bool							getCutterMotorStatus();

        								//!Get current feedrate in nm
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

        bool							setStrokeState(EStrokeState state);
        EStrokeState					getStrokeState(){return mStrokeState;}

        bool							setStageMoveDelay(int ms);

        bool							isActive(){return mIsActive;}
		bool							isActive(bool isIt){mIsActive = isIt;}

    									//Refrences
		bool&        					getRibbonCreatorActiveReference(){return mIsActive;}
		int&        					getSetNumberOfZeroStrokesReference(){return mSetNumberOfZeroStrokes;}

        bool							isMessageSenderRunnning(){return mMessageSender.isRunning();}
//        bool							isMessagereceiverRunnning(){return mMessageSender.isRunning();}

    protected:
        string							mINIFileSection;

        								//!When active, zero stroke and knife stage movement will
                                        //!take place when the counter reaches ribbonLength
        bool							mIsActive;

										//Serial Components
        int								mCOMPort;
    	Serial							mSerial;
        bool							sendUC7Message(const UC7MessageEnum& uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);

        deque<UC7Message> 				mIncomingMessagesBuffer;
        Poco::Mutex						mReceiveBufferMutex;
        Poco::Condition					mNewReceivedMessageCondition;

		deque<string>  					mOutgoingMessagesBuffer;
        Poco::Mutex						mSendBufferMutex;
        Poco::Condition					mNewMessageToSendCondition;

        								//!This is the most previous sent message
        UC7Message 						mUC7Message;

        								//Hardware states
                                        //!Feedrate in nm
        EStrokeState	  				mStrokeState;
		int								mFeedRate;
		int								mPresetFeedRate;
		int								mKnifeStageJogPreset;
        int								mSetNumberOfZeroStrokes;
        int								mNumberOfZeroStrokes;

        								//!When this boolean is true, UC7 commands may be sent to the leica
                                        //!when HW status is changing
        bool							mPrepareForNewRibbon;
        bool							mPrepareToCutRibbon;

        Counter							mCounter;
        UC7MessageSender				mMessageSender;

        								//!Consume UC7 messages
        UC7MessageConsumer		  		mMessageConsumer;

		mtk::Timer	   			        mCustomTimer;

        								//!Events
        void							onSerialMessage(const string& msg);
        void 							onPrepareToCutRibbon();
		void 							onPrepareForNewRibbon();
};

#endif
