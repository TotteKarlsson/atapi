#ifndef abLightsArduinoH
#define abLightsArduinoH
#include "atCoreExporter.h"
#include "atArduinoDevice.h"
//---------------------------------------------------------------------------

class AT_CORE LightsArduino : public ArduinoDevice
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
