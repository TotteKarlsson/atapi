#ifndef atApplicationSoundH
#define atApplicationSoundH
#include "mtkProperty.h"
#include "atATObject.h"
#include "atDirectSound.h"
using mtk::Property;


//!An application sound is a sound that is associated to a part of an application. Its properties are typically stored in
//!an ini file
class AT_CORE ApplicationSound : DirectSound
{
	public:
						ApplicationSound(const string& name, long vol, bool repeats, HWND handle = NULL);


    private:
    	string			mName;
        long			mVolume;
        bool			mRepeats;
};

////---------------------------------------------------------------------------
//MTK_COMMON Range<double> getRange(const string& val);
////Property stuff
//
////Double Ranges
//MTK_COMMON std::string toString(const Range<double>& lvl);
//
//template<> inline
//Range<double>::Range(double min, double max)
//:
//mMin(min),
//mMax(max)
//{}
//
//template<> inline
//std::string Property< Range<double> >::getValueAsString() const
//{
//    return mtk::toString(getValue());
//}
//
//template<> inline
//bool Property< Range<double> >::write(IniFile* iniFile, const string& section)
//{
//    if(iniFile == NULL)
//    {
//        return false;
//    }
//
//    string toWrite;
//    toWrite = mtk::toString(getValue());
//    iniFile->writeString(mKey, toWrite, "", section);
//    return true;
//}
//
//template<> inline
//bool Property< Range<double> >::read(IniFile* iniFile, const string& section)
//{
//    if(iniFile == NULL)
//    {
//        return false;
//    }
//
//    string val(iniFile->readString(mKey, section, mtk::toString(mDefaultValue)));
//
//    Range<double> tempVal = getRange(val);
//
//    mWasRead = iniFile->wasItFound();
//    setValue( mWasRead ? tempVal : mDefaultValue);
//    return mWasRead;
//}
//
//template<> inline
//bool Property< Range<double> >::assignValueFromString(const string& v)
//{
//    return false;
//}
//
//template<> inline
//string Property< Range<double> >::getTypeName() const
//{
//    return "Range";
//}


#endif
