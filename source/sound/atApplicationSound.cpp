#pragma hdrstop
#include "atApplicationSound.h"
//---------------------------------------------------------------------------

ApplicationSound::ApplicationSound(const string& name, long vol, bool repeats, HWND handle)
:
DirectSound(name, handle),
mName(name),
mVolume(vol),
mRepeats(repeats)
{

}
