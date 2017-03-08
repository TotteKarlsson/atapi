#ifndef abSoundsH
#define abSoundsH
#include "atExporter.h"
#include "mtkThread.h"
#include <string>
#include <deque>
//---------------------------------------------------------------------------

using std::string;
using std::deque;
using mtk::Thread;

//exports
AT_CORE enum ABSound
{
	absMotorStop = 0,
    absMotorWarning,
    absCameraShot,
    absSlowSpeed,
    absMediumSpeed,
    absFastSpeed,
    absBeforeBackOff
};


AT_CORE void 			playABSound(ABSound, long flags = 0);

//Non exports
string 	                getSoundResourceName(ABSound a);
bool 			        PlayResource(const string& resName, long flags = 0);


class SoundPlayer;

class SoundWorker : public mtk::Thread
{
	public:
    						SoundWorker(deque<ABSound>& soundDeck , Poco::Mutex bufferMutex);

	private:
    	SoundPlayer&		mSoundPlayer;
};

class AT_CORE SoundPlayer
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
