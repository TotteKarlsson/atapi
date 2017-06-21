#ifndef atNavitarFocusPresetH
#define atNavitarFocusPresetH
#include "atATObject.h"
#include "atPreset.h"
#include "atNavitarMotorController.h"
//---------------------------------------------------------------------------

using mtk::ObjectType;
using mtk::IniFile;

class AT_CORE NavitarFocusPreset	: public Preset<int>
{
    public:
		                                        NavitarFocusPreset(NavitarMotorController& mc, const string& name, const int& z = 0);

        				                        ~NavitarFocusPreset();

		bool	 								set();
        bool									update(const int& value);


    protected:
		NavitarMotorController&					mController;


};
#endif
