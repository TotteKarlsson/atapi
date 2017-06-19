#ifndef abAPTDeviceH
#define abAPTDeviceH
#include "arraybot/atABExporter.h"
#include "atATObject.h"
#include "mtkProperties.h"
#include "atUtilities.h"
#include "mtkINIFileProperties.h"
#include "mtkIniFile.h"

using namespace mtk;
struct HardwareInformation;

///Enum holding Thorlab Device Type IDS
enum DeviceTypeID
{
	didUnknown				= 0,
    didLongTravelStage 		= 45,
    didTCubeStepperMotor 	= 80,
    didTCubeDCServo 		= 83
};


//---------------------------------------------------------------------------
class AT_AB APTDevice : public ATObject
{
	public:
    							                //Every APTDevice need to be created with a serial number
    					                        APTDevice(int serial);
		virtual                                 ~APTDevice();
        bool					                isConnected();
        virtual bool			                connect() = 0;
        virtual bool			                disconnect() = 0;
        virtual bool   	                        identify() = 0;
        virtual HardwareInformation         	getHWInfo() = 0;

                                                //Enable/Disable functions simply sets boolean to
                                                //true or false.
        virtual bool	                    	enable() = 0;
        virtual bool	                    	disable() = 0;

        string					                getSerial();
        string 									getName();
        void									setName(const string& name);

        bool									loadProperties(IniFile& iniFile);
        bool									writeProperties(IniFile& iniFile);

    protected:
		IniFileProperties	  					mProperties;
        virtual bool							applyProperties() = 0;
    	Property<string>                        mSerial;
    	Property<string>						mName;

								                //DeviceTypeID enum
		DeviceTypeID		 	                mDeviceTypeID;

        						                //True if connection with hardware device is
                                                //established
        bool					                mIsConnected;

};


//template<> inline
//std::string Property< DeviceTypeID >::getValueAsString() const
//{
//    return mtk::toString(getValue());
//}
//
//template<> inline
//bool Property<DeviceTypeID>::write(IniFile* iniFile, const string& section)
//{
//    if(iniFile == NULL)
//    {
//        return false;
//    }
//
//    string toWrite;
//    toWrite = mtk::toString(getValue());
//    iniFile->writeString(mKey, toWrite, "", section);
//    return true;
//}
//
//template<> inline
//bool Property<DeviceTypeID>::read(IniFile* iniFile, const string& section)
//{
//    if(iniFile == NULL)
//    {
//        return false;
//    }
//
//    string val(iniFile->readString(mKey, section, mtk::toString(mDefaultValue)));
//
//    DeviceTypeID tempVal = getDeviceTypeID(val);
//    mWasRead = iniFile->wasItFound();
//    setValue( mWasRead ? tempVal : mDefaultValue);
//    return mWasRead;
//}
//
//template<> inline
//bool Property<DeviceTypeID>::assignValueFromString(const string& v)
//{
//    return false;
//}
//
//template<> inline
//string Property<DeviceTypeID>::getTypeName() const
//{
//    return "DeviceTypeID";
//}


#endif
