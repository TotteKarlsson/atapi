#ifndef TPGCoverSlipDataModuleH
#define TPGCoverSlipDataModuleH
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>

//---------------------------------------------------------------------------
class PACKAGE TcsPGDM : public TDataModule
{
    __published:	// IDE-managed Components
        TSQLDataSet *csDS;
        TSQLDataSet * csFreshBatchesDS;
        TDataSetProvider *csP;
        TClientDataSet *csCDS;
        TDataSource *csDSource;
        TSQLDataSet *csStatusDS;
        TDataSetProvider *csStatusP;
        TClientDataSet *csStatusCDS;
        TDataSource *csStatusDSource;
        TIntegerField *csStatusCDSid;
	TWideStringField *csStatusCDSstatus;
        TWideMemoField *csStatusCDSnote;
        TSQLDataSet *csTypeDS;
        TDataSetProvider *csTypeP;
        TClientDataSet *csTypeCDS;
        TDataSource *csTypeDSource;
        TIntegerField *csTypeCDSid;
	TWideStringField *csTypeCDStype;
        TWideMemoField *csTypeCDSnote;
        TIntegerField *csStatusDSid;
	TWideStringField *csStatusDSstatus;
        TWideMemoField *csStatusDSnote;
        TIntegerField *csTypeDSid;
	TWideStringField *csTypeDStype;
        TWideMemoField *csTypeDSnote;
        TIntegerField *csCDSid;
        TIntegerField *csCDSstatus;
        TIntegerField *csCDStype;
	TWideStringField *csCDSLStatus;
	TWideStringField *csCDSLType;
        TWideMemoField *csCDSnotes;
	TClientDataSet *csFreshBatchesCDS;
	TIntegerField *csFreshBatchesCDSid;
	TSQLTimeStampField *csFreshBatchesCDSdate_created;
	TIntegerField *csFreshBatchesCDScount;
	TIntegerField *csFreshBatchesCDStype;
	TWideStringField *csFreshBatchesCDSlot_number;
	TIntegerField *csCDSfreshCSBatch;
	TIntegerField *csCDScleanCSBatch;
	TIntegerField *csCDScarboncoatbatch;
	TWideStringField *csCDSfrom_lot;
	TIntegerField *csFreshBatchesCDSbox_number;
	TIntegerField *csDSid;
	TIntegerField *csDSstatus;
	TIntegerField *csDStype;
	TWideMemoField *csDSnotes;
	TIntegerField *csDSfreshCSBatch;
	TIntegerField *csDScleanCSBatch;
	TIntegerField *csDScarboncoatbatch;
	TWideStringField *csDSfrom_lot;
	TIntegerField *csDSsilanizedCSBatch;
	TSQLTimeStampField *csDSmodified;
        void __fastcall csDSBeforeOpen(TDataSet *DataSet);
        void __fastcall CDSAfterPost(TDataSet *DataSet);
        void __fastcall CDSAfterScroll(TDataSet *DataSet);
	void __fastcall csDustAsssayDSourceDataChange(TObject *Sender, TField *Field);
	void __fastcall CDSAfterDelete(TDataSet *DataSet);


        private:

        public:
			TNotifyEvent	   csDustAssayCDSOnDataChanged;
                    __fastcall TcsPGDM(TComponent* Owner);
        	void    __fastcall afterConnect();
            void    __fastcall afterDisConnect();


};

extern PACKAGE TcsPGDM *csPGDM;
#endif
