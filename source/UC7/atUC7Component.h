#ifndef atUC7ComponentH
#define atUC7ComponentH
#include "atATObject.h"
#include "serial/atSerial.h"
#include "atUC7Message.h"
#include <deque>
#include "Poco/Mutex.h"
#include "atCounter.h"
#include "atUC7MessageSender.h"
#include "atUC7MessageReceiver.h"
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
class UC7MessageReceiver;

class AT_CORE UC7 : public ATObject
{
	friend UC7MessageReceiver;
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

        Counter&						getSectionCounter(){return mSectionCounter;}
        Counter&						getRibbonOrderCounter(){return mRibbonOrderCounter;}
        bool							sendRawMessage(const string& msg);

        bool							startCutter();
        bool							stopCutter();

        								//!The start ribbon will cause the
                                        //!knife stage to move north,
                                        //!an also change cutrate to preset cutrate
        bool							startRibbon();

        bool							moveKnifeStageSouth(int nm, bool isRequest = true);
        bool							moveKnifeStageNorth(int nm, bool isRequest = true);

        								//!Prevent user from bumping in knife into specimen
		bool 							setNorthLimitPosition(int limit);

        								//!Set Feedrate in nm
        bool							setFeedRate(int feedRate, bool isRequest = true);

		bool							setNorthSouthStageAbsolutePosition(int pos, bool isRequest = true);

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

        bool							setFeedRatePreset(int rate = -1);
        bool							setKnifeStageJogStepPreset(int rate = -1);

        bool							setStrokeState(EStrokeState state);
        EStrokeState					getStrokeState(){return mStrokeState;}

        bool							setStageMoveDelay(int ms);

        bool							isActive(){return mIsActive;}
		void							isActive(bool isIt){mIsActive = isIt;}

    									//References
		bool&        					getRibbonCreatorActiveReference(){return mIsActive;}
		int&        					getNumberOfZeroStrokesReference(){return mSetNumberOfZeroStrokes;}

        bool							isSerialMessageSenderRunnning(){return mUC7MessageSender.isRunning();}
        bool							isSerialMessageReceiverRunnning(){return mUC7MessageReceiver.isRunning();}
        int								getLastNumberOfSections(){return mSectionCounter.getLastCount();}

    protected:
        string							mINIFileSection;
        int								mLastNrOfSections;

        								//!When active, zero stroke and knife stage movement will
                                        //!take place when the counter reaches ribbonLength
        bool							mIsActive;

										//Serial Components
        int								mCOMPort;
    	Serial							mSerial;
        bool							sendUC7Message(const UC7MessageEnum& uc, const string& data1 = gEmptyString, const string& data2 = gEmptyString);

        								//!Receive UC7 messages
        UC7MessageReceiver		  		mUC7MessageReceiver;
        deque<UC7Message> 				mIncomingMessagesBuffer;
        Poco::Mutex						mReceiveBufferMutex;
        Poco::Condition					mNewReceivedMessageCondition;

        								//!Send UC7 messages
        UC7MessageSender				mUC7MessageSender;
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
        int								mNorthSouthStagePosition;
        int								mNorthLimitPosition;

        								//!When this boolean is true, UC7 commands may be sent to the leica
                                        //!when HW status is changing
        bool							mPrepareForNewRibbon;

                                        //!This boolean controls the Cut ribbon process
        bool							mPrepareToCutRibbon;

        Counter							mSectionCounter;
        Counter							mRibbonOrderCounter;

		mtk::Timer	   			        mCustomTimer;

        								//!Events
        void							onSerialMessage(const string& msg);
        void 							onPrepareToCutRibbon();
		void 							onPrepareForNewRibbon();
};

#endif
