#include <vcl.h>
#pragma hdrstop
#include "TApplicationSounds.h"
#include "mtkIniFileProperties.h"
#include "mtkVCLUtils.h"
#include "sound/atSounds.h"
#include "sound/atApplicationSound.h"
#include "atVCLUtils.h"
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
    ApplicationSoundsLB->Clear();

    for(uint i = 0; i < mSounds->count(); i++)
    {
    	BaseProperty* prop = mSounds->getProperty(i);
        ApplicationSoundsLB->Items->AddObject(vclstr(prop->getLabel()), (TObject*) prop);
    }

    SoundCB->Clear();
    StringList sounds = getSoundResources();
    for(uint i = 0; i < sounds.count(); i++)
    {
		SoundCB->Items->Add(vclstr(sounds[i]));
    }

    if(ApplicationSoundsLB->Count)
    {
    	ApplicationSoundsLB->ItemIndex = 0;
		ApplicationSoundsLBClick(NULL);
    }
}

//---------------------------------------------------------------------------
void __fastcall TApplicationSounds::ApplicationSoundsLBClick(TObject *Sender)
{
	//Retrive the sound from the listbox
    int itemIndex = ApplicationSoundsLB->ItemIndex;
    if(itemIndex != -1)
    {
    	Property<ApplicationSound>* p = getCurrentSoundProperty();
        if(p)
        {
			ApplicationSound& s = p->getReference();
            VolumeTB->Position = s.getVolume();
            RepeatCB->Checked = s.repeats();
            EnabledCB->Checked = s.enabled();
            selectItem(SoundCB, s.getName());
        }
    }
}

void __fastcall TApplicationSounds::SoundCBCloseUp(TObject *Sender)
{
	//Get selected item and repopulate
    string item = getSelectedItem(SoundCB);
    int itemIndex = ApplicationSoundsLB->ItemIndex;
    if(itemIndex != -1 && item.size())
    {
    	Property<ApplicationSound>* p = getCurrentSoundProperty();
        if(p)
        {
			ApplicationSound& s = p->getReference();
            s.setName(item);
        }
    }
}

Property<ApplicationSound>* TApplicationSounds::getCurrentSoundProperty()
{
    int itemIndex = ApplicationSoundsLB->ItemIndex;
    if(itemIndex != -1)
    {
    	Property<ApplicationSound>* p = dynamic_cast< Property<ApplicationSound>* > ((BaseProperty*) ApplicationSoundsLB->Items->Objects[itemIndex]);
        return p;
    }
    return NULL;
}

void __fastcall TApplicationSounds::PlayBtnClick(TObject *Sender)
{
	Property<ApplicationSound>* p = getCurrentSoundProperty();
    if(p)
    {
    	p->getReference().play();
    }
}

//---------------------------------------------------------------------------
void __fastcall TApplicationSounds::VolumeTBChange(TObject *Sender)
{
    int itemIndex = ApplicationSoundsLB->ItemIndex;
    if(itemIndex != -1 )
    {
    	Property<ApplicationSound>* p = getCurrentSoundProperty();
        if(p)
        {
			ApplicationSound& s = p->getReference();
            s.setVolume(VolumeTB->Position);
        }
    }
}


void __fastcall TApplicationSounds::EnabledCBClick(TObject *Sender)
{
    int itemIndex = ApplicationSoundsLB->ItemIndex;
    if(itemIndex != -1 )
    {
    	Property<ApplicationSound>* p = getCurrentSoundProperty();
        if(p)
        {
			ApplicationSound& s = p->getReference();
            s.setVolume(VolumeTB->Position);
            EnabledCB->Checked ? s.enable() : s.disable();
        }
    }
}


