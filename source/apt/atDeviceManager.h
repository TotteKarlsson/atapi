#ifndef abDeviceManagerH
#define abDeviceManagerH
#include <string>
#include <map>
#include "atAPTExporter.h"
#include "atATObject.h"
#include "mtkConstants.h"
#include "mtkStringList.h"

//---------------------------------------------------------------------------
using std::string;
using std::map;
using std::ostream;
using mtk::gEmptyString;
using mtk::StringList;

//Thorlabs device
class APTDevice;

class AT_APT DeviceManager : public ATObject
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

        AT_APT
        friend ostream&                             operator<<(ostream& os, DeviceManager& pm);

    private:
        mutable map<int, APTDevice*>              	mDevices;
        mutable map<int, APTDevice*>::iterator    	mDevicesIter;
};

#endif
