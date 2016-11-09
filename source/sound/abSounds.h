#ifndef abSoundsH
#define abSoundsH
#include "abExporter.h"
#include <string>
//---------------------------------------------------------------------------

using std::string;
//exports
AT_CORE enum ABSound {absMotorStop = 0, absMotorWarning, absCameraShot};


AT_CORE void 			playABSound(ABSound, long flags = 0);


//Non exports
string 	                getSoundResourceName(ABSound a);
bool 	                PlayResource(const string& resName, long flags = 0);

#endif
