#pragma hdrstop
#include "TATDBImagesAndMoviesDataModule.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
#include "TATDBDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma link "DbxDevartSQLite"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TImagesAndMoviesDM *ImagesAndMoviesDM;
//extern bool gAppIsStartingUp;

using namespace mtk;
//---------------------------------------------------------------------------
__fastcall TImagesAndMoviesDM::TImagesAndMoviesDM(TComponent* Owner)
	: TDataModule(Owner)
{}


//---------------------------------------------------------------------------
void __fastcall TImagesAndMoviesDM::imagesCDSAfterScroll(TDataSet *DataSet)
{
    TField* field = imagesCDS->FieldByName("id");
    if(field)
    {
        String val = field->AsString;
//        imageNote->SQL->Text 	= "SELECT * from umimage_note where image_id ='" + val + "'";
//        notesQ->SQL->Text 		= "SELECT * FROM note WHERE id IN (SELECT note_id FROM umimage_note WHERE image_id = '" + val + "')";
//
//
//            imageNoteCDS->Refresh();
//            notesCDS->Refresh();
    }
//    imageNote->Active = true;
//    notesQ->Active = true;
}


void __fastcall TImagesAndMoviesDM::imagesCDSdateGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
	Text = FormatDateTime( "yy-mm-dd", Sender->AsDateTime );
}

//---------------------------------------------------------------------------
void __fastcall TImagesAndMoviesDM::notesCDScreated_onGetText(TField *Sender,
          UnicodeString &Text, bool DisplayText)
{
	if(!Sender->IsNull)
    {
		Text = FormatDateTime( "yy-mm-dd", Sender->AsDateTime );
    }
    else
    {
    	Text = "";
    }
}

//---------------------------------------------------------------------------
void __fastcall TImagesAndMoviesDM::notesCDSAfterScroll(TDataSet *DataSet)
{
	Log(lDebug3) <<"Note ID:" << notesCDS->FieldByName("id")->AsInteger;
}



