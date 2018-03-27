//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
USEFORM("..\..\source\vcl\frames\TMoviesFrame.cpp", MoviesFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TMovieItemFrame.cpp", MovieItemFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TImagesFrame.cpp", ImagesFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TImageItemFrame.cpp", ImageItemFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\THDMIStreamerFrame.cpp", HDMIStreamerFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TZebraScannerFrame.cpp", ZebraScannerFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TSoundsFrame.cpp", SoundsFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TPGConnectionFrame.cpp", PGConnectionFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TNavitarPresetFrame.cpp", NavitarPresetFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TNavitarMotorFrame.cpp", NavitarMotorFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\datamodules\TPGDataModule.cpp", pgDM); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\datamodules\TPGCoverSlipDataModule.cpp", csPGDM); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\frames\TArduinoServerCommandFrame.cpp", ArduinoServerCommandFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\frames\TApplicationSoundsFrame.cpp", ApplicationSoundsFrame); /* TFrame: File Type */
USEFORM("..\..\source\vcl\forms\TTextInputDialog.cpp", TextInputDialog);
USEFORM("..\..\source\vcl\datamodules\TSensorsDataModule.cpp", SensorsDataModule); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\datamodules\TPGImagesAndMoviesDataModule.cpp", PGImagesAndMoviesDM); /* TDataModule: File Type */
USEFORM("..\..\source\vcl\forms\TStringInputDialog.cpp", StringInputDialog);
USEFORM("..\..\source\vcl\forms\TSelectProcessTypeDialog.cpp", SelectProcessTypeDialog);
USEFORM("..\..\source\vcl\forms\TYesNoForm.cpp", YesNoForm);
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
#pragma comment(lib, "dslFoundation.lib")
#pragma comment(lib, "dslVCLCommon.lib")
#pragma comment(lib, "dslVCLComponents.bpi")

#pragma comment(lib, "atFoundation.lib")
#pragma comment(lib, "atVCLCommon.lib")
#pragma comment(lib, "atComponents.bpi")

#pragma comment(lib, "DBXDevartPostgreSQLDriver250.bpi")
#pragma comment(lib, "DBXMySQLDriver.bpi")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

//Simple dataset
#pragma comment(lib, "dbxcds.bpi")

