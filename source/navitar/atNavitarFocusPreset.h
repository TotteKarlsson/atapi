#ifndef atNavitarFocusPresetH
#define atNavitarFocusPresetH
#include "core/atATObject.h"
#include "core/atPreset.h"
#include "atNavitarMotorController.h"
//---------------------------------------------------------------------------

using dsl::ObjectType;
using dsl::IniFile;

class AT_CORE NavitarFocusPreset	: public Preset<int>
{
    public:
		                                        NavitarFocusPreset(NavitarMotorController& mc, const string& name, const int& z = 0);
        				                        ~NavitarFocusPreset();

		bool	 								set();


    protected:
		NavitarMotorController&					mController;
};
#endif
