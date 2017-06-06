#ifndef TApplicationSoundsH
#define TApplicationSoundsH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntLabel.h"
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------

namespace mtk
{
	class IniFileProperties;
}

using mtk::IniFileProperties;

class PACKAGE TApplicationSounds : public TFrame
{
    __published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TListBox *ApplicationSoundsCB;
        TComboBox *SoundCB;
        TTrackBar *VolumeTB;
        TCheckBox *RepeatCB;
        TIntLabel *VolumeLbl;
        TBindingsList *BindingsList1;

    private:
		IniFileProperties*				mSounds;

    public:
        					__fastcall  TApplicationSounds(TComponent* Owner);
		void							populate(IniFileProperties& props);
};

extern PACKAGE TApplicationSounds *ApplicationSounds;
#endif
