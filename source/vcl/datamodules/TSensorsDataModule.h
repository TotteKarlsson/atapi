#ifndef TSensorsDataModuleH
#define TSensorsDataModuleH
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
//---------------------------------------------------------------------------


class PACKAGE TSensorsDataModule : public TDataModule
{
    __published:
        TSQLDataSet *SensorDataDS;
        TDataSetProvider *SensorDataProvider;
        TClientDataSet *SensorDataCDS;

	private:

    public:
                        __fastcall 	TSensorsDataModule(TComponent* Owner);
        bool 						insertSensorData(int sensorID, double val1, double val2);
};


extern PACKAGE TSensorsDataModule *sensorsDM;
#endif