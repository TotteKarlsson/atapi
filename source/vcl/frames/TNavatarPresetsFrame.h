#ifndef TNavatarPresetsFrameH
#define TNavatarPresetsFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "TNavitarPreset.h"
//---------------------------------------------------------------------------

class NavitarMotorController;
class TPresetsFrame : public TFrame
{
    __published:
	TGroupBox *GroupBox1;
	TNavitarPreset *TNavitarPreset1;
	TNavitarPreset *NavitarPreset1;
	TNavitarPreset *NavitarPreset2;
    private:

	NavitarMotorController* mController;


    public:
    				__fastcall 	TPresetsFrame(TComponent* Owner);
		void					populate(NavitarMotorController& c);
};

extern PACKAGE TPresetsFrame *PresetsFrame;

#endif
