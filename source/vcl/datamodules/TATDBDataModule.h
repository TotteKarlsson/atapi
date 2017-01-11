#ifndef TATDBDataModuleH
#define TATDBDataModuleH
#include <System.Classes.hpp>
#include "DbxDevartSQLite.hpp"
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <SimpleDS.hpp>
#include <Data.DBXMySQL.hpp>
#include <string>

using std::string;
//!The TatDM class encapsulate data exchange with the ATDB database
//---------------------------------------------------------------------------
class TatdbDM : public TDataModule
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TDataSource *blocksDataSource;
	TClientDataSet *blocksCDS;
	TDataSetProvider *blocksProvider;
	TSQLDataSet *blocksDS;
	TSQLDataSet *usersDS;
	TDataSetProvider *usersProvider;
	TClientDataSet *usersCDS;
	TDataSource *usersDataSource;
	TDataSource *blockNotesDSource;
	TDataSetProvider *blockNotesProvider;
	TClientDataSet *blockNotesCDS;
	TSQLDataSet *noteDS;
	TDataSetProvider *notesProvider;
	TClientDataSet *notesCDS;
	TDataSource *notesDSource;
	TDataSetProvider *mRibbonProvider;
	TClientDataSet *mRibbonCDS;
	TDataSource *mRibbonDSource;
	TIntegerField *usersDSid;
	TStringField *usersDSuser_name;
	TSQLTimeStampField *usersDScreated;
	TIntegerField *usersCDSid;
	TStringField *usersCDSuser_name;
	TSQLTimeStampField *usersCDScreated;
	TIntegerField *blockNotesCDSid;
	TMemoField *blockNotesCDSnote;
	TSQLTimeStampField *blockNotesCDScreated_on;
	TIntegerField *blockNotesCDScreated_by;
	TIntegerField *notesCDSid;
	TMemoField *notesCDSnote;
	TSQLTimeStampField *notesCDScreated_on;
	TIntegerField *notesCDScreated_by;
	TDataSetProvider *ribbonNotesProvider;
	TClientDataSet *ribbonNotesCDS;
	TDataSource *ribbonNotesDSource;
	TSQLDataSet *ribbonsDS;
	TSQLDataSet *blockNotesDS;
	TIntegerField *blockNotesDSid;
	TMemoField *blockNotesDSnote;
	TSQLTimeStampField *blockNotesDScreated_on;
	TIntegerField *blockNotesDScreated_by;
	TSQLDataSet *ribbonNotesDS;
	TIntegerField *ribbonNotesDSid;
	TMemoField *ribbonNotesDSnote;
	TSQLTimeStampField *ribbonNotesDScreated_on;
	TIntegerField *ribbonNotesDScreated_by;
	TIntegerField *ribbonNotesCDSid;
	TMemoField *ribbonNotesCDSnote;
	TSQLTimeStampField *ribbonNotesCDScreated_on;
	TIntegerField *ribbonNotesCDScreated_by;
	TIntegerField *blocksCDSid;
	TSQLTimeStampField *blocksCDScreated;
	TIntegerField *blocksCDScreated_by;
	TSQLTimeStampField *blocksCDSmodified;
	TStringField *ribbonsDSid;
	TIntegerField *ribbonsDSstatus;
	TIntegerField *ribbonsDSblock_id;
	TIntegerField *ribbonsDScutting_order;
	TSmallintField *ribbonsDSnr_of_sections;
	TSQLTimeStampField *ribbonsDScreated;
	TSQLTimeStampField *ribbonsDSmodified;
	TStringField *mRibbonCDSid;
	TIntegerField *mRibbonCDSstatus;
	TIntegerField *mRibbonCDSblock_id;
	TIntegerField *mRibbonCDScutting_order;
	TSmallintField *mRibbonCDSnr_of_sections;
	TSQLTimeStampField *mRibbonCDScreated;
	TSQLTimeStampField *mRibbonCDSmodified;
	TSQLDataSet *specimenDS;
	TDataSetProvider *specimenProvider;
	TClientDataSet *specimenCDS;
	TDataSource *specimenDSrc;
	TStringField *specimenCDSspeciment_id;
	TStringField *specimenCDSLspecie;
	TStringField *specimenCDSadditional_identifier;
	TStringField *specimenCDSage;
	TIntegerField *specimenCDSlims_number;
	TDateField *specimenCDSdeath_date;
	TStringField *specimenCDSbrain_region_dissection;
	TDateField *specimenCDSdate_received;
	TStringField *blocksCDSlabel;
	TSimpleDataSet *fixativeTBL;
	TSimpleDataSet *speciesDS;
	TSimpleDataSet *preprocesstreatmentDS;
	TSimpleDataSet *fixationMethodDS;
	TSimpleDataSet *postfix;
	TSimpleDataSet *cryoprotectionDS;
	TSimpleDataSet *freezeprotocolDS;
	TSimpleDataSet *substitutionProtocol;
	TSimpleDataSet *infiltrationProtocolDS;
	TSimpleDataSet *embeddingProtocolDS;
	TSimpleDataSet *blockstatusDS;
	TIntegerField *blocksCDSprocess_id;
	TIntegerField *specimenCDSprocess_id;
	TSimpleDataSet *processIDDS;
	TIntegerField *blocksCDSLprocess_id;
	TSmallintField *blocksCDSstatus;
	TIntegerField *specimenDSprocess_id;
	TStringField *specimenDSspecimen_id;
	TSmallintField *specimenDSspecie;
	TStringField *specimenDSadditional_identifier;
	TStringField *specimenDSage;
	TIntegerField *specimenDSlims_number;
	TDateField *specimenDSdeath_date;
	TStringField *specimenDSbrain_region_dissection;
	TDateField *specimenDSdate_received;
	TStringField *blocksCDSLBlockStatus;
	TSmallintField *blocksCDSserial;
	TStringField *blocksCDSCBlockLabel;
	TSQLDataSet *documentsDS;
	TDataSetProvider *documentsProvider;
	TClientDataSet *documentsCDS;
	TDataSource *documentsDSource;
	TIntegerField *documentsDSid;
	TBlobField *documentsDSdocument;
	TStringField *documentsDStype;
	TStringField *documentsDSdocument_name;
	TIntegerField *documentsCDSid;
	TStringField *documentsCDSdocument_name;
	TBlobField *documentsCDSdocument;
	TStringField *documentsCDStype;
	TSmallintField *substitutionProtocolid;
	TStringField *substitutionProtocolprotocol;
	TIntegerField *substitutionProtocoldocument_id;
	TStringField *substitutionProtocolLDocument;
	TIntegerField *blocksDSid;
	TIntegerField *blocksDSprocess_id;
	TSQLTimeStampField *blocksDScreated;
	TIntegerField *blocksDScreated_by;
	TSQLTimeStampField *blocksDSmodified;
	TSmallintField *blocksDSstatus;
	TStringField *blocksDSlabel;
	TSmallintField *blocksDSserial;
	TDateField *blocksDSdate_embedded;
	TSmallintField *blocksDSpreprocess_treatment_protocol;
	TSmallintField *blocksDSfixative_protocol;
	TSmallintField *blocksDSfixation_protocol;
	TSmallintField *blocksDSpostfix_protocol;
	TSmallintField *blocksDScryoprotection_protocol;
	TSmallintField *blocksDSfreezing_protocol;
	TSmallintField *blocksDSsubstitution_protocol;
	TSmallintField *blocksDSinfiltration_protocol;
	TSmallintField *blocksDSembedding_protocol;
	TDateField *blocksCDSdate_embedded;
	TSmallintField *blocksCDSpreprocess_treatment_protocol;
	TSmallintField *blocksCDSfixative_protocol;
	TSmallintField *blocksCDSfixation_protocol;
	TSmallintField *blocksCDSpostfix_protocol;
	TSmallintField *blocksCDScryoprotection_protocol;
	TSmallintField *blocksCDSfreezing_protocol;
	TSmallintField *blocksCDSsubstitution_protocol;
	TSmallintField *blocksCDSinfiltration_protocol;
	TSmallintField *blocksCDSembedding_protocol;
	TStringField *blocksCDSLPreprocessTreatmentProtocol;
	TStringField *blocksCDSLFixativeProtocol;
	TStringField *blocksCDSLFixationProtocol;
	TStringField *blocksCDSLPostFixProtocol;
	TStringField *blocksCDSLCryoProtectionProtocol;
	TStringField *blocksCDSLFreezingProtocol;
	TStringField *blocksCDSLSubstitutionProtocol;
	TStringField *blocksCDSLInfiltrationProtocol;
	TStringField *blocksCDSLEmbeddingProtocol;
	TStringField *blocksCDSLUser;
	void __fastcall cdsAfterPost(TDataSet *DataSet);
	void __fastcall cdsAfterDelete(TDataSet *DataSet);
	void __fastcall cdsAfterScroll(TDataSet *DataSet);
	void __fastcall cdsBeforePost(TDataSet *DataSet);
	void __fastcall mRibbonCDSCalcFields(TDataSet *DataSet);
	void __fastcall SQLConnection1AfterConnect(TObject *Sender);

	void __fastcall SQLConnection1BeforeConnect(TObject *Sender);
	void __fastcall cdsAfterRefresh(TDataSet *DataSet);
 	void __fastcall fixativeTBLAfterPost(TDataSet *DataSet);
	void __fastcall blocksCDSCalcFields(TDataSet *DataSet);
	void __fastcall blocksCDSblockLabelGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall TimeStampGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall cdsBeforeRefresh(TDataSet *DataSet);
	void __fastcall specimenCDSBeforeClose(TDataSet *DataSet);

	private:	// User declarations
    protected:
    	string		mDataBaseUser;
    	string		mDataBaseUserPassword;
       	string		mDataBase;
        string 		mDBIP;

	public:
				__fastcall TatdbDM(TComponent* Owner);

		bool 	__fastcall connect(const string& ip, const string& dbUser, const string& dbPassword, const string& db);
        void    __fastcall afterConnect();
        void    __fastcall afterDisConnect();
};

extern PACKAGE TatdbDM *atdbDM;

#endif
