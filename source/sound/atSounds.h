#ifndef abSoundsH
#define abSoundsH
#include "atExporter.h"
#include "mtkThread.h"
#include <string>
#include <deque>
#include <mmsystem.h>
#include "atATObject.h"
//---------------------------------------------------------------------------

using std::string;
using std::deque;
using mtk::Thread;

//exports
AT_CORE enum ABSound
{
	absMotorStop = 0,
    absAlert1,
    absMotorWarning,
    absCameraShot,
    absSlowSpeed,
    absMediumSpeed,
    absFastSpeed,
    absBeforeBackOff,
    absButtonClick4,
    absDefaultClick
};


//!Flags are
//!SND_ASYNC SND_SYNC
//!See: https://msdn.microsoft.com/en-us/library/windows/desktop/dd743680(v=vs.85).aspx
AT_CORE void 			playABSound(ABSound, long flags = SND_ASYNC);

//Non exports
string 	                getSoundResourceName(ABSound a);
bool 			        PlayResource(const string& resName, long flags = 0);


class SoundPlayer;

class SoundWorker : public mtk::Thread, public ATObject
{
	public:
    						SoundWorker(deque<ABSound>& soundDeck , Poco::Mutex bufferMutex);

	private:
    	SoundPlayer&		mSoundPlayer;
};

class AT_CORE SoundPlayer : public ATObject
{
	public:
								SoundPlayer();

                                //!Add a sound to the soundplayer
		bool					play(ABSound aSound,int repeat, int delay);

    private:
    	deque<ABSound> 			mSounds;

        SoundWorker				mSoundWorker;
        Poco::Mutex				mSoundMutex;

};


#endif
