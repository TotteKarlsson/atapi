#ifndef abSensorsArduinoClientH
#define abSensorsArduinoClientH
#include "abExporter.h"
#include "abArduinoClient.h"
//---------------------------------------------------------------------------

class AT_CORE SensorsArduinoClient : public ArduinoClient
{
    public:
			   			        			SensorsArduinoClient();
		virtual			        			~SensorsArduinoClient(){}
		virtual void	 					getBoardStatus();

    protected:

};

#endif
