#ifndef atNavitarZoomPresetH
#define atNavitarZoomPresetH
#include "core/atATObject.h"
#include "core/atPreset.h"
#include "atNavitarMotorController.h"
//---------------------------------------------------------------------------

using dsl::ObjectType;
using dsl::IniFile;

class AT_CORE NavitarZoomPreset	: public Preset<int>
{
    public:
		                                        NavitarZoomPreset(NavitarMotorController& mc, const string& name, const int& z = 0);
        				                        ~NavitarZoomPreset();
		bool	 								set();

    protected:
		NavitarMotorController&					mController;


};
#endif
