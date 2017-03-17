#ifndef abSensorsArduinoClientH
#define abSensorsArduinoClientH
#include "atExporter.h"
#include "atArduinoClient.h"
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
