#ifndef atApplicationSoundH
#define atApplicationSoundH
#include "mtkProperty.h"
#include "atATObject.h"
#include "atDirectSound.h"
#include "mtkConstants.h"
#include "mtkStringList.h"
#include "mtkUtils.h"


using mtk::Property;
using mtk::StringList;
using mtk::IniFile;
class ApplicationSound;
namespace mtk
{
AT_CORE	string	toString(const ApplicationSound& sound);
}

//!An application sound is a sound that is associated to a part of an application. Its properties are typically stored in
//!an ini file
class AT_CORE ApplicationSound : public DirectSound
{
	public:
							            ApplicationSound(const string& name = mtk::gEmptyString, long vol = 0, bool repeats = false, HWND handle = NULL);
							            ApplicationSound(const ApplicationSound& s);
		ApplicationSound&	            operator=(const ApplicationSound& rhs);

        long				            getVolume() const {return mVolume;}
        void				            setVolume(long v){mVolume = v;}

        bool				            repeats() const {return mRepeats;}
        void				            setRepeats(bool val){mRepeats = val;}

    private:
        long			                mVolume;
        bool			                mRepeats;
};

template<>
inline Property<ApplicationSound>::operator ApplicationSound() const
{
    return (*mValue);
}

//---------------------------------------------------------------------------
template<> inline
std::string Property< ApplicationSound >::getValueAsString() const
{
    return mtk::toString(getValue());
}

template<> inline
bool Property< ApplicationSound >::write(IniFile* iniFile, const string& section)
{
    if(iniFile == NULL)
    {
        return false;
    }

    string toWrite;
    toWrite = mtk::toString(getValue());
    iniFile->writeString(mKey, toWrite, "", section);
    return true;
}

template<> inline
bool Property< ApplicationSound >::read(IniFile* iniFile, const string& section)
{
    if(iniFile == NULL)
    {
        return false;
    }

    StringList val(iniFile->readString(mKey, section, ""),',');
    ApplicationSound tempVal;
    if(val.size() == 3)
    {
    	tempVal = ApplicationSound(val[0], mtk::toInt(val[1]), toBool(val[2]));
    }

    mWasRead = iniFile->wasItFound();
    setValue( mWasRead ? tempVal : mDefaultValue);
    return mWasRead;
}

template<> inline
bool Property< ApplicationSound >::assignValueFromString(const string& v)
{
    return false;
}

template<> inline
string Property< ApplicationSound >::getTypeName() const
{
    return "applicationSound";
}


#endif
