#ifndef abSensorsArduinoH
#define abSensorsArduinoH
#include "atCoreExporter.h"
#include "atArduinoDevice.h"
//---------------------------------------------------------------------------

class AT_CORE SensorsArduino : public ArduinoDevice
{
    public:
                                			SensorsArduino(int portNr, int baudRate = 9600);
			                                ~SensorsArduino(){}
        bool								getStatus();


    protected:


};
#endif
