#pragma hdrstop
#include "TRibbonsDataModule.h"
#include "TATDBDataModule.h"
#include "TCoverSlipDataModule.h"
#include "mtkLogger.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
TRibbonsDataModule *RibbonsDataModule;

using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TRibbonsDataModule::TRibbonsDataModule(TComponent* Owner)
	: TDataModule(Owner)
{
}

void __fastcall TRibbonsDataModule::afterConnect()
{
	Log(lInfo) << "Initializing Ribbons datamodule";
}

void __fastcall TcsDM::afterDisConnect()
{}


