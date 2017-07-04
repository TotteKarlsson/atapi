#ifndef abSoundPlayerH
#define abSoundPlayerH
#include "core/atCoreExporter.h"
#include "core/atATObject.h"
#include "atDirectSound.h"
#include "mtkTimer.h"

using mtk::Timer;
//---------------------------------------------------------------------------

//class AT_CORE SoundPlayer : public ATObject
//{
//    public:
//						        SoundPlayer(const string& snd, int nrOfTimes = 1, int delay=500);
//						        ~SoundPlayer();
//		bool					create(HWND hWnd = NULL);
//		bool					play(int nrTimes = 0, int msDelay = 0);
//        bool					stop();
//
//    protected:
//        int						mDelay;
//        int 					mNrOfReps;
//        int 					mNrOfTimesPlayed;
//        string					mSoundResourceName;
//		DirectSound				mTheSound;
//
//
//		Timer					mPlayingTimer;
//        void					onTimer();
//
//};
#endif
