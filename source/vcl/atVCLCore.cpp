#include <System.hpp>
#pragma hdrstop
USEFORM("frames\TPositionalTriggerFrame.cpp", PositionalTriggerFrame); /* TFrame: File Type */
USEFORM("frames\TSequenceInfoFrame.cpp", SequenceInfoFrame); /* TFrame: File Type */
USEFORM("frames\TSequencerButtonsFrame.cpp", SequencerButtonsFrame); /* TFrame: File Type */
USEFORM("frames\TParallellProcessesFrame.cpp", ParallellProcessesFrame);
USEFORM("frames\TNavitarMotorFrame.cpp", NavitarMotorFrame); /* TFrame: File Type */
USEFORM("frames\TNavitarPresetFrame.cpp", NavitarPreset); /* TFrame: File Type */
USEFORM("frames\TTimeDelayFrame.cpp", TimeDelayFrame); /* TFrame: File Type */
USEFORM("frames\TXYZPositionsFrame.cpp", XYZPositionsFrame); /* TFrame: File Type */
USEFORM("frames\TXYZUnitFrame.cpp", XYZUnitFrame); /* TFrame: File Type */
USEFORM("frames\TMotorMoveProcessFrame.cpp", MotorMoveProcessFrame); /* TFrame: File Type */
USEFORM("forms\TamFileEditor.cpp", amFileEditor);
USEFORM("forms\TProcessSequenceControlForm.cpp", ProcessSequenceControlForm);
USEFORM("forms\TSelectProcessTypeDialog.cpp", SelectProcessTypeDialog);
USEFORM("frames\TArduinoServerCommandFrame.cpp", ArduinoServerCommandFrame); /* TFrame: File Type */
USEFORM("frames\TArrayCamRequestFrame.cpp", ArrayCamRequestFrame); /* TFrame: File Type */
USEFORM("frames\TMotorFrame.cpp", MotorFrame); /* TFrame: File Type */
USEFORM("forms\TYesNoForm.cpp", YesNoForm);
USEFORM("forms\TShowFileContentForm.cpp", ShowFileContentForm);
USEFORM("forms\TStringInputDialog.cpp", StringInputDialog);
USEFORM("forms\TTextInputDialog.cpp", TextInputDialog);
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
#pragma comment(lib, "atArrayBotCore.lib")

#pragma comment(lib, "libmysqlB.lib")
#pragma comment(lib, "poco_mysql_connector-static.lib")
#pragma comment(lib, "poco_sqlite_connector-static.lib")
#pragma comment(lib, "poco_data-static.lib")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

#pragma comment(lib, "DuneComponents.bpi")



