//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
USEFORM("..\..\source\vcl\datamodules\TSensorsDataModule.cpp", SensorsDataModule); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\datamodules\TPGImagesAndMoviesDataModule.cpp", PGImagesAndMoviesDM); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\datamodules\TPGDataModule.cpp", pgDM); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\datamodules\TPGCoverSlipDataModule.cpp", csPGDM); /* TDataModule: File Type */
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------


#pragma argsused
extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

//---------------------------------------------------------------------------
#pragma comment(lib, "dslCommon.lib")
#pragma comment(lib, "dslVCLCommon.lib")
#pragma comment(lib, "dslVCLComponents.bpi")

#pragma comment(lib, "atFoundation.lib")
#pragma comment(lib, "atVCLCommon.lib")
#pragma comment(lib, "atVCLComponents.bpi")

#pragma comment(lib, "DBXDevartPostgreSQLDriver250.bpi")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

//Simple dataset
#pragma comment(lib, "dbxcds.bpi")

