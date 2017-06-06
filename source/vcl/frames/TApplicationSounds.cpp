#include <vcl.h>
#pragma hdrstop
#include "TApplicationSounds.h"
#include "mtkIniFileProperties.h"
#include "mtkVCLUtils.h"
#include "sound/atSounds.h"
//---------------------------------------------------------------------------

using namespace mtk;

#pragma package(smart_init)
#pragma link "TIntLabel"
#pragma resource "*.dfm"
TApplicationSounds *ApplicationSounds;

//---------------------------------------------------------------------------
__fastcall TApplicationSounds::TApplicationSounds(TComponent* Owner)
	: TFrame(Owner)
{}

void TApplicationSounds::populate(IniFileProperties& props)
{
	mSounds = &props;
    //Populate listbox with names
    ApplicationSoundsCB->Clear();

    for(uint i = 0; i < mSounds->count(); i++)
    {
    	BaseProperty* prop = mSounds->getProperty(i);
        ApplicationSoundsCB->Items->AddObject(vclstr(prop->getLabel()), NULL);
    }

    SoundCB->Clear();
    StringList sounds = getSoundResources();
    for(uint i = 0; i < sounds.count(); i++)
    {
		SoundCB->Items->Add(vclstr(sounds[i]));
    }
}
