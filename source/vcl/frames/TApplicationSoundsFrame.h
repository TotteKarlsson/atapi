#ifndef TApplicationSoundsFrameH
#define TApplicationSoundsFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntLabel.h"
#include <System.Rtti.hpp>
#include <Vcl.ComCtrls.hpp>
#include "dslProperty.h"
#include "sound/atApplicationSound.h"
//---------------------------------------------------------------------------

namespace dsl
{
	class IniFileProperties;
}

using dsl::IniFileProperties;

class PACKAGE TApplicationSoundsFrame : public TFrame
{
    __published:	// IDE-managed Components
	TGroupBox *GBS;
	TListBox *ApplicationSoundsLB;
        TComboBox *SoundCB;
        TTrackBar *VolumeTB;
        TCheckBox *RepeatCB;
	TButton *PlayBtn;
	TCheckBox *EnabledCB;
	TGroupBox *SoundPropsGB;
	void __fastcall ApplicationSoundsLBClick(TObject *Sender);
	void __fastcall SoundCBCloseUp(TObject *Sender);
	void __fastcall PlayBtnClick(TObject *Sender);
	void __fastcall VolumeTBChange(TObject *Sender);
	void __fastcall EnabledCBClick(TObject *Sender);

    private:
		IniFileProperties*				mSounds;
		Property<ApplicationSound>* 	getCurrentSoundProperty();
    public:
        					__fastcall  TApplicationSoundsFrame(TComponent* Owner);
		void							populate(IniFileProperties& props);
};

extern PACKAGE TApplicationSoundsFrame *ApplicationSoundsFrame;
#endif
