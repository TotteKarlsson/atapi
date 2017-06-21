#ifndef atNavitarZoomPresetH
#define atNavitarZoomPresetH
#include "atATObject.h"
#include "atPreset.h"
#include "atNavitarMotorController.h"
//---------------------------------------------------------------------------

using mtk::ObjectType;
using mtk::IniFile;

class AT_CORE NavitarZoomPreset	: public Preset<int>
{
    public:
		                                        NavitarZoomPreset(NavitarMotorController& mc, const string& name, const int& z = 0);

        				                        ~NavitarZoomPreset();

		bool	 								set();
        bool									update(const int& value);


    protected:
		NavitarMotorController&					mController;


};
#endif
