#ifndef atNavitarPresetH
#define atNavitarPresetH
#include "atATObject.h"
#include "atNavitarZoomPreset.h"
#include "atNavitarFocusPreset.h"
#include "atNavitarMotorController.h"
//---------------------------------------------------------------------------

using mtk::ObjectType;
using mtk::IniFile;

class AT_CORE NavitarPreset	: public ATObject
{
    public:
		                                        NavitarPreset(NavitarMotorController& mc, const string& name, const int& z = 0, const int& f = 0);
        				                        ~NavitarPreset();

		bool	 								set();
        bool									update(const int& z, const int& f);


    protected:
		NavitarMotorController&					mController;
        NavitarZoomPreset						mZoom;
        NavitarFocusPreset						mFocus;


};
#endif
