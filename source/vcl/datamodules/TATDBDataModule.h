#ifndef TATDBDataModuleH
#define TATDBDataModuleH
#include <System.Classes.hpp>
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
	TDataSource *specimenDataSource;
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
	TSimpleDataSet *specimenIDDS;
	TSmallintField *blocksCDSstatus;
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
	TIntegerField *specimenIDDSspecimen_id;
	TIntegerField *ribbonsDScreated_by;
	TIntegerField *mRibbonCDScreated_by;
	TIntegerField *ribbonsDScoverslip_id;
	TIntegerField *mRibbonCDScoverslip_id;
	TDataSource *ROnCoverSlipsSource;
	TClientDataSet *ROnCS_CDS;
	TDataSetProvider *RibbonsOnCoverslipsProvider;
	TSQLDataSet *ribbonsOnCoverSlipsDS;
	TSQLDataSet *settingsDS;
	TDataSetProvider *settingsProvider;
	TClientDataSet *settingsCDS;
	TIntegerField *settingsCDSid;
	TMemoField *settingsCDSlabel_printer_command;
	TIntegerField *settingsDSid;
	TMemoField *settingsDSlabel_printer_command;
	TIntegerField *specimenDScase_id;
	TIntegerField *specimenDSspecimen_id;
	TIntegerField *specimenDSlims_number;
	TStringField *specimenDSvirus;
	TStringField *specimenDSage;
	TDateField *specimenDSdeath_date;
	TStringField *specimenDSbrain_region_dissection;
	TIntegerField *specimenDSentered_by;
	TIntegerField *specimenDSculture_time;
	TIntegerField *specimenCDScase_id;
	TIntegerField *specimenCDSspecimen_id;
	TIntegerField *specimenCDSlims_number;
	TStringField *specimenCDSvirus;
	TStringField *specimenCDSage;
	TDateField *specimenCDSdeath_date;
	TStringField *specimenCDSbrain_region_dissection;
	TIntegerField *specimenCDSentered_by;
	TIntegerField *specimenCDSculture_time;
	TIntegerField *blocksDSid;
	TIntegerField *blocksDSspecimen_id;
	TSQLTimeStampField *blocksDScreated;
	TSmallintField *blocksDSstatus;
	TIntegerField *blocksDScreated_by;
	TSQLTimeStampField *blocksDSmodified;
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
	TIntegerField *blocksCDSspecimen_id;
	TClientDataSet *casesCDS;
	TSQLDataSet *casesDS;
	TDataSetProvider *casesProvider;
	TIntegerField *casesCDSid;
	TStringField *casesCDSanimal_id;
	TSQLTimeStampField *casesCDSintake_date;
	TSmallintField *casesCDSspecie;
	TIntegerField *casesCDSentered_by;
	TIntegerField *casesDSid;
	TStringField *casesDSanimal_id;
	TSQLTimeStampField *casesDSintake_date;
	TSmallintField *casesDSspecie;
	TIntegerField *casesDSentered_by;
	TStringField *casesCDSLUser;
	TStringField *casesCDSLSpecie;
	TStringField *specimenCDSLEnteredBy;
	TSimpleDataSet *culturedTimePoints;
	TStringField *specimenCDSLCulturedTP;
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
	void __fastcall specimenCDSAfterClose(TDataSet *DataSet);
	void __fastcall specimenCDSAfterOpen(TDataSet *DataSet);


	private:

    protected:
    	string		                    mDataBaseUser;
    	string		                    mDataBaseUserPassword;
       	string		                    mDataBase;
        string 		                    mDBIP;

	public:
				__fastcall           	TatdbDM(TComponent* Owner);
		bool 	__fastcall           	connect(const string& ip, const string& dbUser, const string& dbPassword, const string& db);
        void    __fastcall           	afterConnect();
        void    __fastcall           	afterDisConnect();
        int		__fastcall				getCurrentBlockID();
};

extern PACKAGE TatdbDM *atdbDM;

#endif
