#ifndef abLightsArduinoClientH
#define abLightsArduinoClientH
#include "abExporter.h"
#include "abArduinoClient.h"
//---------------------------------------------------------------------------

class AT_CORE LightsArduinoClient : public ArduinoClient
{
    public:
			   			        			LightsArduinoClient();
		virtual			        			~LightsArduinoClient(){}

		void								toggleLED();
		void								toggleCoax();
		virtual void	 					getBoardStatus();

    protected:

};

#endif
