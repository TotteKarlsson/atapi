#pragma hdrstop
#include "atApplicationSound.h"
#include <sstream>
//---------------------------------------------------------------------------

using namespace std;
using namespace mtk;

ApplicationSound::ApplicationSound(const string& name, long vol, bool repeats, bool enabled, HWND handle)
:
DirectSound(name, handle),
mVolume(vol),
mRepeats(repeats),
mEnabled(enabled)
{
}

ApplicationSound::ApplicationSound(const ApplicationSound& s)
:
DirectSound(s.getName(), s.getHandle()),
mVolume(s.getVolume()),
mRepeats(s.repeats()),
mEnabled(s.enabled())
{}

ApplicationSound& ApplicationSound::operator=(const ApplicationSound& rhs)
{
	if(this == &rhs)
    {
    	return *this;
    }

	this->setName(rhs.getName());
    this->setVolume(rhs.getVolume());
    this->setRepeats(rhs.repeats());
    rhs.enabled() ? this->enable() : this->disable();

    return *this;
}

void ApplicationSound::setVolume(int v)
{
	mVolume = v;
	DirectSound::setVolume(v);
}

bool ApplicationSound::play(DWORD sPos, bool loop)
{
	if(mEnabled)
    {
		DirectSound::setVolume(mVolume);
		return DirectSound::play(sPos, loop);
    }
    return true;
}

namespace mtk
{
    string	toString(const ApplicationSound& sound)
    {
        stringstream s;
        s << sound.getName()<<","<<sound.getVolume()<<","<<mtk::toString(sound.repeats())<<","<<mtk::toString(sound.enabled());
        return s.str();
    }
}
