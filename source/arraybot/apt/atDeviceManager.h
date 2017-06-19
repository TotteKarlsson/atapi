#ifndef atDeviceManagerH
#define atDeviceManagerH
#include <string>
#include <map>
#include "arraybot/atABExporter.h"
#include "atATObject.h"
#include "mtkConstants.h"
#include "mtkStringList.h"
#include "atAPTDevice.h"
//---------------------------------------------------------------------------
using std::string;
using std::map;
using std::ostream;
using mtk::gEmptyString;
using mtk::StringList;

//Thorlabs device
class APTDevice;
struct TLI_DeviceInfo;

AT_AB bool 			buildDeviceList();
AT_AB string 		toString(DeviceTypeID value);
AT_AB string 		toString(const TLI_DeviceInfo& val);
AT_AB int 			getNumberOfConnectedDevices();
AT_AB StringList 	getSerialsForDeviceType(DeviceTypeID deviceID);
AT_AB DeviceTypeID getDeviceTypeID(const string& id);
//AT_CORE DeviceTypeID getDeviceTypeID(const string& level);



class AT_AB DeviceManager : public ATObject
{
    public:
                                                    DeviceManager();
	    virtual                                     ~DeviceManager();
    	bool										reBuildDeviceList();

        APTDevice*                                  connectDevice(int serial);
        int                                         connectAllDevices();

        bool                                        disConnect(APTDevice* device = NULL);
        bool                                        disConnectAll();

        string                                      getInfo() const;
        StringList                                  getDeviceSerials() const;

        int                                         getNumberOfConnectableDevices() const;
        int                                         getNumberOfConnectedDevices() const;
        APTDevice*                                  getDevice(int serial);
        APTDevice*                                  getFirst() const;
        APTDevice*                                  getNext() const;
        APTDevice*                                  getPrevious() const;
        APTDevice*                                  getCurrent() const;

        AT_AB
        friend ostream&                             operator<<(ostream& os, DeviceManager& pm);

    private:
        mutable map<int, APTDevice*>              	mDevices;
        mutable map<int, APTDevice*>::iterator    	mDevicesIter;
};

#endif
