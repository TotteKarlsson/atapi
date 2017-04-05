#ifndef abArrayBotH
#define abArrayBotH
#include "atExporter.h"
#include "atATObject.h"
#include "atXYZUnit.h"
#include "atWhiskerUnit.h"
#include "joystick/atArrayBotJoyStick.h"
#include "apt/atPairedMoves.h"
#include "joystick/atJoyStickSettings.h"
#include "process/atProcessSequencer.h"
//---------------------------------------------------------------------------

class ArduinoClient;
class AT_CORE ArrayBot : public ATObject
{
    public:
									                    ArrayBot(IniFile& ini, const string& appFolder);
									                    ~ArrayBot();

		void 						                    initialize();

		bool											enableCoverSlipUnit();
		bool											disableCoverSlipUnit();
		bool											enableWhiskerUnit();
		bool											disableWhiskerUnit();

        XYZUnit&					                    getCoverSlipUnit();
        XYZUnit&					                    getWhiskerUnit();
        bool						                    shutDown();

        ArrayBotJoyStick&			                    getJoyStick();
        JoyStickSettings&			                    getJoyStickSettings();

		bool						                    enableJoyStick();
		void						                    disableJoyStick();

        void											enableJoyStickAxes();
        void											disableJoyStickAxes();

        void						                    stopAll();

        void						                    initWorkingPosition();

        bool						                    isActive();
        bool						                    isShuttingDown();

		APTMotor*					                    getCoverSlipAngleController();
		APTMotor*					                    getCameraAngleController();

    	PairedMoves&	 			                    getLiftMoves(){return mLifts;}

        bool						                    applyJoyStickSetting(const string& settingName);
        bool						                    readINIParameters();
        bool						                    writeINIParameters();
        vector<APTMotor*>			                    getAllMotors();
        APTMotor*										getMotorWithName(const string& mn);
        APTMotor*										getMotorWithSerial(const string& serial);
        ProcessSequencer&								getProcessSequencer();

    private:
        bool						                    mIsShuttingDown;
        string						                    mAppDataFolder;
        IniFile&					                    mIniFile;
        IniFileProperties  			    				mProperties;
        Property<int>									mJoyStickID;
        ArrayBotJoyStick			                    mJoyStick;

		Property<double>								mRightJoyStickXLeftDeadZone;
        Property<double>                                mRightJoyStickXRightDeadZone;
        Property<double>                                mRightJoyStickYLeftDeadZone;
        Property<double>                                mRightJoyStickYRightDeadZone;

        Property<double>                                mLeftJoyStickXLeftDeadZone;
        Property<double>                                mLeftJoyStickXRightDeadZone;
        Property<double>                                mLeftJoyStickYLeftDeadZone;
        Property<double>                                mLeftJoyStickYRightDeadZone;

        JoyStickSettings			                    mJSSettings;

        XYZUnit						                    mCoverSlip;
        XYZUnit											mWhisker;

        							                    //!List of Lifts
        PairedMoves					                    mLifts;
   	    ProcessSequencer  								mProcessSequencer;
};

#endif
