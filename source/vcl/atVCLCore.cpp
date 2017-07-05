#include <System.hpp>
#pragma hdrstop
USEFORM("forms\TYesNoForm.cpp", YesNoForm);
USEFORM("forms\TTextInputDialog.cpp", TextInputDialog);
USEFORM("frames\TArduinoServerCommandFrame.cpp", ArduinoServerCommandFrame); /* TFrame: File Type */
USEFORM("frames\TApplicationSoundsFrame.cpp", ApplicationSounds); /* TFrame: File Type */
USEFORM("forms\TStringInputDialog.cpp", StringInputDialog);
USEFORM("forms\TBlockEntryForm.cpp", BlockEntryForm);
USEFORM("forms\TATDBServerEntry.cpp", ATDBServerEntry);
USEFORM("forms\TShowFileContentForm.cpp", ShowFileContentForm);
USEFORM("forms\TSelectProcessTypeDialog.cpp", SelectProcessTypeDialog);
USEFORM("frames\TNavitarPresetFrame.cpp", NavitarPresetFrame); /* TFrame: File Type */
USEFORM("frames\TNavitarMotorFrame.cpp", NavitarMotorFrame); /* TFrame: File Type */
USEFORM("frames\TZebraScannerFrame.cpp", ZebraScannerFrame); /* TFrame: File Type */
USEFORM("frames\TSoundsFrame.cpp", SoundsFrame); /* TFrame: File Type */
USEFORM("forms\TamFileEditor.cpp", amFileEditor);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}
#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atDataBase.lib")
#pragma comment(lib, "atResources.lib")
#pragma comment(lib, "atBarcodeReader.lib")

#pragma comment(lib, "libmysqlB.lib")
#pragma comment(lib, "poco_mysql_connector-static.lib")
#pragma comment(lib, "poco_sqlite_connector-static.lib")
#pragma comment(lib, "poco_data-static.lib")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

#pragma comment(lib, "DuneComponents.bpi")



