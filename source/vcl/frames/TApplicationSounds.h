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
#include "mtkProperty.h"
#include "sound/atApplicationSound.h"
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
	TListBox *ApplicationSoundsLB;
        TComboBox *SoundCB;
        TTrackBar *VolumeTB;
        TCheckBox *RepeatCB;
        TBindingsList *BindingsList1;
	TButton *PlayBtn;
	TCheckBox *EnabledCB;
	TGroupBox *GroupBox2;
	void __fastcall ApplicationSoundsLBClick(TObject *Sender);
	void __fastcall SoundCBCloseUp(TObject *Sender);
	void __fastcall PlayBtnClick(TObject *Sender);
	void __fastcall VolumeTBChange(TObject *Sender);
	void __fastcall EnabledCBClick(TObject *Sender);

    private:
		IniFileProperties*				mSounds;
		Property<ApplicationSound>* 	getCurrentSoundProperty();
    public:
        					__fastcall  TApplicationSounds(TComponent* Owner);
		void							populate(IniFileProperties& props);
};

extern PACKAGE TApplicationSounds *ApplicationSounds;
#endif
