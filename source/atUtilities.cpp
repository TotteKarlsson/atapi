#pragma hdrstop
#include "atUtilities.h"
#include <sstream>
#include "mtkLogger.h"
#include "Thorlabs.MotionControl.IntegratedStepperMotors.h"
//---------------------------------------------------------------------------

using namespace std;
using namespace mtk;

string toString(LogicOperator o)
{
	switch(o)
    {
		case loLargerThan: 			return ">";
        case loSmallerThan:    		return "<";
        case loEqualTo:             return "=";
        case loLargerThanOrEqual:   return ">=";
        case loSmallerThanOrEqual:	return "<=";
        default: 					return "unknown";
    }
}

LogicOperator toLogicOperator(const string& o)
{
	if(o == ">")	return loLargerThan;
	if(o == "<")	return loSmallerThan;
	if(o == "=")	return loEqualTo;
   	if(o == ">=")	return loLargerThanOrEqual;
   	if(o == "<=")	return loSmallerThanOrEqual;

    return loUndefined;
}

string toString(const TLI_DeviceInfo& val)
{
	stringstream str;
    str
    <<"Device Type ID: "<<val.typeID<<"\t"
    <<"Description: "	<<val.description<<"\t"
	<<"Serial: "		<<val.serialNo<<"\t"
	<<"Is Known Type: " <<val.isKnownType<<"\t";

    return str.str();
}

string toString(ProcessType pt)
{
	switch(pt)
    {
    	case ptAbsoluteMove: 			return "absoluteMove";
    	case ptParallell: 		        return "parallellProcess";
    	case ptTimeDelay: 		        return "timeDelay";
    	case ptStopAndResumeProcess:    return "stopAndResumeProcess";
    	case ptArrayCamRequestProcess:	return "arrayCamRequestProcess";
    	case ptArduinoServerCommand: 	return "arduinoServerCommand";
        default: 				        return "unknownProcessType";
    }
}

//enum ProcessType {ptBaseType = 0, ptMaster, ptParallell, ptAbsoluteMove, ptTimeDelay, ptUnknown};

ProcessType toProcessType(const string& str)
{
	if(str == "parallellProcess")
    {
    	return ptParallell;
    }

	if(str == "absoluteMove")
    {
    	return ptAbsoluteMove;
    }

  	if(str == "arduinoServerCommand")
    {
    	return ptArduinoServerCommand;
    }

	if(str == "timeDelay")
    {
    	return ptTimeDelay;
    }

	if(str == "stopAndResumeProcess")
    {
    	return ptStopAndResumeProcess;
    }

	if(str == "arrayCamRequestProcess")
    {
    	return ptArrayCamRequestProcess;
    }

	return ptUnknown;
}

bool buildDeviceList()
{
    // Build list of connected device
    return (TLI_BuildDeviceList() == 0) ? true : false;
}

int getNumberOfConnectedDevices()
{
	return TLI_GetDeviceListSize();
}

StringList getSerialsForDeviceType(DeviceTypeID deviceID)
{
	StringList serials;

    // Build list of connected device
//    if (TLI_BuildDeviceList() == 0)
	{
        // get device list size
        short n = TLI_GetDeviceListSize();
        if(n == 0)
        {
        	Log(lInfo) << "There are no open devices available";
        }

        // get serial numbers
        char serialNos[250];
        TLI_GetDeviceListByTypeExt(serialNos, 250, deviceID);

         // output list of matching devices
		serials = StringList(serialNos ,',');
     }
	return serials;
}

DeviceTypeID getDeviceTypeID(const string& id)
{
    string sid = toUpperCase(id);
    if (sid == "UNKNOWN")  			return didUnknown;
    if (sid == "LONGTRAVELSTAGE")   return didLongTravelStage;
    if (sid == "TCUBESTEPPERMOTOR") return didTCubeStepperMotor;
    if (sid == "TCUBEDCSERVO")            return didTCubeDCServo;
    return didUnknown;
}

string toString(DeviceTypeID value)
{
	switch(value)
    {
    	case didTCubeDCServo:
        	return "TCube DC Servo";

		case didLongTravelStage:
        	return "Long Travel Stage";

		case didTCubeStepperMotor:
        	return "TCube Stepper Motor";
		default:
        	return "Device type is not defined";
    }
}

string tlError(int err)
{
	stringstream str;
    str<<"Error nr="<<err<<": ";

	switch(err)
    {
        case 0:
            str << "FT_OK - Success";
        break;
        case 1:
            str << "FT_InvalidHandle - The FTDI functions have not been initialized.";
        break;
        case 2:
            str << "FT_DeviceNotFound - The Device could not be found. \nThis can be generated if the function TLI_BuildDeviceList() has not been called.";
        break;
        case 3: 
            str << "FT_DeviceNotOpened - The Device must be opened before it can be accessed. See the appropriate Open function for your device.";
        break;                
        case 4: 
            str << "FT_IOError - An I/O Error has occured in the FTDI chip.";
        break;
        case 5: 
            str << "FT_InsufficientResources - There are Insufficient resources to run this application.";
        break;
        case 6: 
            str << "FT_InvalidParameter - An invalid parameter has been supplied to the device.";
        break;
        case 7: 
            str << "FT_DeviceNotPresent - The Device is no longer present. The device may have been disconnected since the last TLI_BuildDeviceList() call.";
        break;
        case 8: 
            str << "FT_IncorrectDevice - The device detected does not match that expected.";
        break;

        // General DLL control errors<S-Del>
        //The following errors are general errors generated by all DLLs.
        case 32: 
            str << "(0x20) TL_ALREADY_OPEN - Attempt to open a device that was already open.";
        break;
        case 33: 
            str << "(0x21) TL_NO_RESPONSE - The device has stopped responding.";
        break;
        case 34: 
            str << "(0x22) TL_NOT_IMPLEMENTED - This function has not been implemented.";
        break;
        case 35: 
            str << "(0x23) TL_FAULT_REPORTED - The device has reported a fault.";
        break;
        case 36: 
            str << "(0x24) TL_INVALID_OPERATION - The function could not be completed at this time.";
        break;
        case 40: 
            str << "(0x28) TL_DISCONNECTING - The function could not be completed because the device is disconnected.";
        break;
        case 41: 
            str << "(0x29) TL_FIRMWARE_BUG - The firmware has thrown an error";
        break;
        case 42: 
            str << "(0x2A) TL_INITIALIZATION_FAILURE - The device has failed to initialize";
        break;
        case 43: 
            str << "(0x2B) TL_INVALID_CHANNEL - An Invalid channel address was supplied";
        break;

        // Motor specific errors
        //The following errors are motor specific errors generated by the Motor DLLs.

        case 37: 
            str << "(0x25) TL_UNHOMED - The device cannot perform this function until it has been Homed.";
        break;
        case 38: 
            str << "(0x26) TL_INVALID_POSITION - The function cannot be performed as it would result in an illegal position.";
        break;
        case 39: 
            str << "(0x27) TL_INVALID_VELOCITY_PARAMETER - An invalid velocity parameter was supplied. The velocity must be greater than zero.";
        break;
        case 44: 
            str << "(0x2C) TL_CANNOT_HOME_DEVICE - This device does not support Homing. Check the Limit switch parameters are correct.";
        break;
        case 45: 
            str << "(0x2D) TL_JOG_CONTINOUS_MODE - An invalid jog mode was supplied for the jog function.";
        break;
        default:
            str<< "This error is not reckognized: "<<err;
        break;
    }
    return str.str();
}
