#ifndef TPGDataModuleH
#define TPGDataModuleH
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <SimpleDS.hpp>
#include <Data.DBXMySQL.hpp>
#include "DbxDevartPostgreSQL.hpp"
#include <string>
#include "database/atDBCredentials.h"
#include "mtkStringList.h"

using mtk::StringList;
using std::string;

//!The TpgDM class encapsulate data exchange with the ATDB database
//---------------------------------------------------------------------------
class PACKAGE TpgDM : public TDataModule
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
	TDataSetProvider *ribbonsProvider;
	TClientDataSet *ribbonsCDS;
	TDataSource *ribbonsDSource;
	TIntegerField *usersDSid;
	TWideStringField *usersDSuser_name;
	TSQLTimeStampField *usersDScreated;
	TIntegerField *usersCDSid;
	TWideStringField *usersCDSuser_name;
	TSQLTimeStampField *usersCDScreated;
	TDataSetProvider *ribbonNotesProvider;
	TClientDataSet *ribbonNotesCDS;
	TDataSource *ribbonNotesDSource;
	TSQLDataSet *ribbonsDS;
	TSQLDataSet *blockNotesDS;
	TSQLDataSet *ribbonNotesDS;
	TIntegerField *ribbonNotesDSid;
	TWideMemoField *ribbonNotesDSnote;
	TSQLTimeStampField *ribbonNotesDScreated_on;
	TIntegerField *ribbonNotesDScreated_by;
	TIntegerField *ribbonNotesCDSid;
	TWideMemoField *ribbonNotesCDSnote;
	TSQLTimeStampField *ribbonNotesCDScreated_on;
	TIntegerField *ribbonNotesCDScreated_by;
	TIntegerField *blocksCDSid;
	TWideStringField *ribbonsDSid;
	TIntegerField *ribbonsDSstatus;
	TIntegerField *ribbonsDSblock_id;
	TIntegerField *ribbonsDScutting_order;
	TSmallintField *ribbonsDSnr_of_sections;
	TSQLTimeStampField *ribbonsDSmodified;
	TWideStringField *ribbonsCDSid;
	TIntegerField *ribbonsCDSstatus;
	TIntegerField *ribbonsCDSblock_id;
	TIntegerField *ribbonsCDScutting_order;
	TSmallintField *ribbonsCDSnr_of_sections;
	TSQLTimeStampField *ribbonsCDScreated_on;
	TSQLTimeStampField *ribbonsCDSmodified;
	TSQLDataSet *slicesDS;
	TDataSetProvider *slicesProvider;
	TClientDataSet *slicesCDS;
	TDataSource *slicesDataSource;
	TWideStringField *blocksCDSlabel;
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
	TSmallintField *blocksCDSstatus;
	TWideStringField *blocksCDSLBlockStatus;
	TSmallintField *blocksCDSserial;
	TWideStringField *blocksCDSCBlockLabel;
	TSmallintField *substitutionProtocolid;
	TWideStringField *substitutionProtocolprotocol;
	TIntegerField *substitutionProtocoldocument_id;
	TDateField *blocksCDSdate_embedded;
	TSmallintField *blocksCDScryoprotection_protocol;
	TSmallintField *blocksCDSfreezing_protocol;
	TSmallintField *blocksCDSsubstitution_protocol;
	TSmallintField *blocksCDSinfiltration_protocol;
	TSmallintField *blocksCDSembedding_protocol;
	TWideStringField *blocksCDSLCryoProtectionProtocol;
	TWideStringField *blocksCDSLFreezingProtocol;
	TWideStringField *blocksCDSLSubstitutionProtocol;
	TWideStringField *blocksCDSLInfiltrationProtocol;
	TWideStringField *blocksCDSLEmbeddingProtocol;
	TWideStringField *blocksCDSLUser;
	TIntegerField *ribbonsDScreated_by;
	TIntegerField *ribbonsCDScreated_by;
	TIntegerField *ribbonsDScoverslip_id;
	TIntegerField *ribbonsCDScoverslip_id;
	TDataSource *ROnCoverSlipsSource;
	TClientDataSet *ROnCS_CDS;
	TDataSetProvider *RibbonsOnCoverslipsProvider;
	TSQLDataSet *ribbonsOnCoverSlipsDS;
	TSQLDataSet *settingsDS;
	TDataSetProvider *settingsProvider;
	TClientDataSet *settingsCDS;
	TIntegerField *settingsCDSid;
	TWideMemoField *settingsCDSlabel_printer_command;
	TIntegerField *settingsDSid;
	TWideMemoField *settingsDSlabel_printer_command;
	TClientDataSet *specimenCDS;
	TSQLDataSet *specimenDS;
	TDataSetProvider *specimenProvider;
	TIntegerField *specimenCDSid;
	TWideStringField *specimenCDSanimal_id;
	TSQLTimeStampField *specimenCDSintake_date;
	TSmallintField *specimenCDSspecie;
	TIntegerField *specimenCDSentered_by;
	TIntegerField *specimenDSid;
	TWideStringField *specimenDSanimal_id;
	TSQLTimeStampField *specimenDSintake_date;
	TSmallintField *specimenDSspecie;
	TIntegerField *specimenDSentered_by;
	TWideStringField *specimenCDSLUser;
	TWideStringField *specimenCDSLSpecie;
	TSimpleDataSet *culturedTimePoints;
	TDataSource *specimenDataSource;
	TIntegerField *blocksDSid;
	TIntegerField *blocksDSslice_id;
	TSmallintField *blocksDSstatus;
	TIntegerField *blocksDSentered_by;
	TWideStringField *blocksDSlabel;
	TSmallintField *blocksDSserial;
	TDateField *blocksDSdate_embedded;
	TSmallintField *blocksDScryoprotection_protocol;
	TSmallintField *blocksDSfreezing_protocol;
	TSmallintField *blocksDSsubstitution_protocol;
	TSmallintField *blocksDSinfiltration_protocol;
	TSmallintField *blocksDSembedding_protocol;
	TWideStringField *specimenDSsummary;
	TWideStringField *specimenCDSsummary;
	TIntegerField *slicesDSid;
	TIntegerField *slicesDSspecimen_id;
	TWideStringField *slicesDSvirus;
	TWideStringField *slicesDSbrain_region_dissection;
	TIntegerField *slicesDSentered_by;
	TIntegerField *slicesDSculture_time;
	TIntegerField *slicesCDSid;
	TIntegerField *slicesCDSspecimen_id;
	TWideStringField *slicesCDSvirus;
	TWideStringField *slicesCDSbrain_region_dissection;
	TIntegerField *slicesCDSculture_time;
	TIntegerField *slicesCDSentered_by;
	TSmallintField *slicesDSpreprocess_treatment_protocol;
	TSmallintField *slicesDSfixative_protocol;
	TSmallintField *slicesDSfixation_protocol;
	TSmallintField *slicesDSpostfix_protocol;
	TIntegerField *blocksCDSslice_id;
	TIntegerField *blocksCDSentered_by;
	TSQLTimeStampField *blocksDSentered_on;
	TSQLTimeStampField *blocksCDSentered_on;
	TWideStringField *slicesDSvirus_dilution;
	TWideStringField *slicesCDSvirus_dilution;
	TSQLDataSet *blockIDsDS;
	TDataSetProvider *blockIdsProvider;
	TClientDataSet *blockIDSCDS;
	TIntegerField *IntegerField4;
	TDataSource *blockIDsDataSource;
	TIntegerField *blockIDsDSid;
	TSimpleDataSet *ribbonStatusDS;
	TWideStringField *ribbonsCDSstatusL;
	TWideStringField *slicesCDSentered_byL;
	TSmallintField *slicesCDSpreprocess_treatment_protocol;
	TWideStringField *slicesCDSpreprocess_treatment_protocolL;
	TSmallintField *slicesCDSfixative_protocol;
	TWideStringField *slicesCDSfixative_protocolL;
	TSmallintField *slicesCDSfixation_protocol;
	TWideStringField *slicesCDSfixation_protocolL;
	TSmallintField *slicesCDSpostfix_protocol;
	TWideStringField *slicesCDSpostfix_protocolL;
	TWideStringField *slicesCDSculture_timeL;
	TDataSource *DataSource1;
	TClientDataSet *ClientDataSet1;
	TIntegerField *IntegerField1;
	TIntegerField *IntegerField2;
	TIntegerField *IntegerField3;
	TSQLTimeStampField *SQLTimeStampField1;
	TWideStringField *WideStringField1;
	TSmallintField *SmallintField1;
	TWideStringField *WideStringField2;
	TSmallintField *SmallintField2;
	TWideStringField *WideStringField3;
	TDateField *DateField1;
	TSmallintField *SmallintField3;
	TSmallintField *SmallintField4;
	TSmallintField *SmallintField5;
	TSmallintField *SmallintField6;
	TSmallintField *SmallintField7;
	TWideStringField *WideStringField4;
	TWideStringField *WideStringField5;
	TWideStringField *WideStringField6;
	TWideStringField *WideStringField7;
	TWideStringField *WideStringField8;
	TWideStringField *WideStringField9;
	TDataSetProvider *DataSetProvider1;
	TSQLDataSet *AllBlocksDS;
	TIntegerField *IntegerField5;
	TIntegerField *IntegerField6;
	TSmallintField *SmallintField8;
	TIntegerField *IntegerField7;
	TWideStringField *WideStringField10;
	TSmallintField *SmallintField9;
	TDateField *DateField2;
	TSmallintField *SmallintField10;
	TSmallintField *SmallintField11;
	TSmallintField *SmallintField12;
	TSmallintField *SmallintField13;
	TSmallintField *SmallintField14;
	TSQLTimeStampField *SQLTimeStampField2;
	TIntegerField *noteDSid;
	TWideMemoField *noteDSnote;
	TSQLTimeStampField *noteDScreated_on;
	TIntegerField *noteDScreated_by;
	TIntegerField *notesCDSid;
	TWideMemoField *notesCDSnote;
	TSQLTimeStampField *notesCDScreated_on;
	TIntegerField *notesCDScreated_by;
	TIntegerField *blockNotesDSid;
	TWideMemoField *blockNotesDSnote;
	TSQLTimeStampField *blockNotesDScreated_on;
	TIntegerField *blockNotesDScreated_by;
	TIntegerField *blockNotesCDSid;
	TWideMemoField *blockNotesCDSnote;
	TSQLTimeStampField *blockNotesCDScreated_on;
	TIntegerField *blockNotesCDScreated_by;
	TSQLTimeStampField *ribbonsDScreated_on;
	void __fastcall cdsAfterPost(TDataSet *DataSet);
	void __fastcall cdsAfterDelete(TDataSet *DataSet);
	void __fastcall cdsAfterScroll(TDataSet *DataSet);
	void __fastcall cdsBeforePost(TDataSet *DataSet);
	void __fastcall ribbonsCDSCalcFields(TDataSet *DataSet);
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
	void __fastcall slicesCDSBeforeClose(TDataSet *DataSet);
	void __fastcall slicesCDSAfterClose(TDataSet *DataSet);
	void __fastcall slicesCDSAfterOpen(TDataSet *DataSet);
	void __fastcall SQLConnection1AfterDisconnect(TObject *Sender);
	void __fastcall cdsbeforeDelete(TDataSet *DataSet);

	private:

    protected:
	    DBCredentials					mCredentials;

	public:
				__fastcall           	TpgDM(TComponent* Owner);
				__fastcall           	~TpgDM();
		bool 	__fastcall           	connect(const string& host, const string& db, const string& user, const string& pwd);
		bool 	__fastcall           	connect(const DBCredentials& c);
        void    __fastcall           	afterConnect();
        void    __fastcall           	afterDisConnect();
        bool							isConnected();
        int		__fastcall				getCurrentBlockID();
        int 	__fastcall				getIDForSpecie(const string& specie);
		String __fastcall 				createBlockLabel();
        bool	__fastcall				insertBlockNote(int userID, int blockID, const string& note);
        bool	__fastcall				insertRibbonNote(int userID, const string& ribbonID, const string& note);

        StringList 						getTableNames();
		bool							addNoteForBlock(int blockID, int userID, const string& note);

};

extern PACKAGE TpgDM *pgDM;

#endif
