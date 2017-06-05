#ifndef abDirectSoundH
#define abDirectSoundH
#include "atATObject.h"

#include <windows.h>
#include <mmreg.h>
#include <dsound.h>

class AT_CORE DirectSound : public ATObject
{
    public:
							        DirectSound(const string& resName, HWND hWnd = NULL);        virtual 					~DirectSound();
        bool						create(const string& resName, HWND hWnd = NULL);

        bool			            isValid() const;
        bool			            play(DWORD dwStartPosition = 0, bool bLoop = FALSE);
		void						setVolume(int volume);
        bool			            stop();
        bool			            pause();
        bool			            continuePlay();
        bool						purge();

    protected:
                                    // Alternativly you can specify the sound by yourself
                                    // Note that the class does not copy the entire data ! Instead
                                    // a pointer to the given data will be stored !
                                    // You can load an entire WAV file into memory and then call this
                                    // Create() method.
        bool						create(LPVOID pSoundData, HWND hWnd =  NULL);

        bool                        setSoundData(LPVOID pSoundData, DWORD dwSoundSize);
        bool                        createSoundBuffer(WAVEFORMATEX * pcmwf);
        bool                        getWaveData(void * pRes, WAVEFORMATEX * & pWaveHeader, void * & pbWaveData, DWORD & cbWaveSize);


    private:
    	HWND						mHandle;
        LPVOID 						mTheSound;
        DWORD 						mTheSoundBytes;
        LPDIRECTSOUNDBUFFER 		mDirectSoundBuffer;
        LPDIRECTSOUND 				mDirectSoundStructure;
        static DWORD 				mNrOfInstances;
        string						mResourceName;
};

//#pragma message("linking with Microsoft's DirectSound library ...")
#pragma comment(lib, "dsound.lib")
#endif
