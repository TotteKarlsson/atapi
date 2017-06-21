#ifndef atPresetH
#define atPresetH
#include "atATObject.h"
#include <string>
#include "mtkProperty.h"
#include "atPreset.h"
//---------------------------------------------------------------------------
using std::string;
using mtk::Property;
using mtk::ObjectType;
using mtk::IniFile;

template <class T>
class AT_CORE Preset : public Property<T>
{
    public:
        						                Preset(const string& name, const T& val);
		virtual	        		                ~Preset(){}

                                                //!The set member function may change hardware and is defined in
                                                //!subclases
		virtual bool			                set() = 0;

        ///////////////////////////////////////////////////////////////////////////////////////////
        string                                  getINIRecord(){return "";}
        bool                                    assignValueFromString(const string& val){ return false;}
        string                                  getLabel(){return "";}
        string                                  getValueAsString() const{ return "";}
        void*                                   getValueHandle(){return NULL;}
        ObjectType                              getPropertyType(){ return mtk::otUndefined;}
        bool                                    read(IniFile* iniFile, const string& section){ return false;}
        bool                                    write(IniFile* iniFile, const string& section){ return false;}

                                                //Copy temporary value to real value
        void                                    applyModification(){;}
		///////////////////////////////////////////////////////////////////////////////////////////

        virtual bool			                update(const T& value) = 0;
};

template<class T>
Preset<T>::Preset(const string& name, const T& val)
:
Property<T>(val, name)
{
}

#endif
