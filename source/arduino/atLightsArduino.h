#ifndef atLightsArduinoH
#define atLightsArduinoH
#include "core/atCoreExporter.h"
#include "atArduinoDevice.h"
//---------------------------------------------------------------------------

class AT_ARDUINO LightsArduino : public ArduinoDevice
{
    public:
                                			LightsArduino(int portNr, int baudRate = 9600);
			                                ~LightsArduino(){}

		bool								toggleLED();
        bool								turnLEDLightsOn();
        bool								turnLEDLightsOff();
        bool								getStatus();

    protected:
        									//!ArduinoLines
		int 								mLEDLightONLine;
		int									mLEDLightOFFLine;

};
#endif
