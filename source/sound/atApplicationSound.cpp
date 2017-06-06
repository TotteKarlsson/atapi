#pragma hdrstop
#include "atApplicationSound.h"
#include <sstream>
//---------------------------------------------------------------------------

using namespace std;
using namespace mtk;

ApplicationSound::ApplicationSound(const string& name, long vol, bool repeats, HWND handle)
:
DirectSound(name, handle),
mVolume(vol),
mRepeats(repeats)
{
}

ApplicationSound::ApplicationSound(const ApplicationSound& s)
:
DirectSound(s.getName(), s.getHandle()),
mVolume(s.getVolume()),
mRepeats(s.repeats())
{

}

ApplicationSound& ApplicationSound::operator=(const ApplicationSound& rhs)
{
	if(this == &rhs)
    {
    	return *this;
    }

	this->setName(rhs.getName());
    this->setVolume(rhs.getVolume());
    this->setRepeats(rhs.repeats());

    return *this;
}
namespace mtk
{

string	toString(const ApplicationSound& sound)
{
	stringstream s;

    s << sound.getName()<<","<<sound.getVolume()<<","<<mtk::toString(sound.repeats());
    return s.str();
}

}
