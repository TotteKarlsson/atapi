#ifndef TATDBImagesAndMoviesDataModuleH
#define TATDBImagesAndMoviesDataModuleH
#include <System.Classes.hpp>
#include "DbxDevartSQLite.hpp"
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Data.DBXMySQL.hpp>
#include <string>
#include "Poco/Mutex.h"
//---------------------------------------------------------------------------
using std::string;

class PACKAGE TImagesAndMoviesDM : public TDataModule
{
    __published:	// IDE-managed Components
        TSQLDataSet *images;
        TDataSetProvider *DataSetProvider1;
        TDataSetProvider *imagesProvider;
        TClientDataSet *imagesCDS;
        TDataSource *imagesDS;
	TDataSource *imageNotesDSource;
        TClientDataSet *imageNoteCDS;
	TSQLDataSet *sensors;
	TDataSetProvider *DataSetProvider3;
	TClientDataSet *sensorsCDS;
	TDataSource *sensorsDS;
	TIntegerField *sensorsid;
	TIntegerField *sensorsdevice_id;
	TSQLTimeStampField *sensorsdate;
	TFloatField *sensorstemperature;
	TFloatField *sensorshumidity;
	TIntegerField *sensorsCDSdevice_id;
	TSQLTimeStampField *sensorsCDSdate;
	TFloatField *sensorsCDStemperature;
	TFloatField *sensorsCDShumidity;
	TIntegerField *imagesid;
	TStringField *imagesfile_name;
	TSQLTimeStampField *imagesdate;
	TIntegerField *imagesCDSid;
	TStringField *imagesCDSfile_name;
	TSQLTimeStampField *imagesCDSdate;
	TSQLDataSet *imageNotesDS;
	TDataSource *notesDSource;
	TClientDataSet *notesCDS;
	TIntegerField *IntegerField1;
	TMemoField *MemoField1;
	TSQLTimeStampField *SQLTimeStampField1;
	TIntegerField *IntegerField2;
	TDataSetProvider *notesProvider;
	TSQLDataSet *noteDS;
	TIntegerField *imageNoteCDSid;
	TMemoField *imageNoteCDSnote;
	TSQLTimeStampField *imageNoteCDScreated_on;
	TIntegerField *imageNoteCDScreated_by;
	TIntegerField *imageNoteCDSimage_id;
	TIntegerField *imageNoteCDSnote_id;
	TIntegerField *imageNotesDSid;
	TMemoField *imageNotesDSnote;
	TSQLTimeStampField *imageNotesDScreated_on;
	TIntegerField *imageNotesDScreated_by;
	TIntegerField *imageNotesDSimage_id;
	TIntegerField *imageNotesDSnote_id;
        void __fastcall imagesCDSAfterScroll(TDataSet *DataSet);

	void __fastcall imagesCDSdateGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall notesCDScreated_onGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall notesCDSAfterScroll(TDataSet *DataSet);


	private:	// User declarations

	public:		// User declarations
				__fastcall TImagesAndMoviesDM(TComponent* Owner);

};

extern PACKAGE TImagesAndMoviesDM *ImagesAndMoviesDM;
#endif
