#ifndef abCoverSlipAngleControllerH
#define abCoverSlipAngleControllerH
#include "atExporter.h"
#include "atATObject.h"
#include "mtkIniFile.h"
#include "mtkProperties.h"
#include "mtkINIFileProperties.h"
#include "atDeviceManager.h"
#include <string>
//---------------------------------------------------------------------------

using std::string;
using mtk::IniFile;
using mtk::IniFileProperties;
using mtk::Property;
class APTMotor;

class AT_CORE CoverSlipAngleController : public ABObject
{
	public:
      							            CoverSlipAngleController(const string& name, IniFile& iniFile);
     							            ~CoverSlipAngleController();

		bool				                initialize();
		bool 					            isActive();
		void 					            shutDown();
		string					            getName() const;
        void					            setAngle(double a);
        double					            getAngle();
		void					            stop();
		APTMotor*				            getMotor();

        Property<int>		                mMotorSerial;
        Property<double>  	                mAngle;
        Property<string>   	                mName;
    	DeviceManager	                    mDeviceManager;

    private:
    	APTMotor*				            mAngleMotor;
        IniFile&			                mIniFile;
        IniFileProperties	                mProperties;
        int									mAngleOffset;
};

#endif
