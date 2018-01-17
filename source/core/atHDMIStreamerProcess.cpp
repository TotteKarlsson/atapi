#pragma hdrstop
#include "atHDMIStreamerProcess.h"
#include "mtkFileUtils.h"
//---------------------------------------------------------------------------

HDMIStreamerProcess::HDMIStreamerProcess(const string& bmExecutable, const string& pipeName)
:
mBMStreamerExecutable(bmExecutable),
mStreamPipeName(pipeName),
//mStreamProcHandle(NULL),
mProcessMessages(mOutPipe)
{

}

bool HDMIStreamerProcess::setOutputFileFolder(const string& folder)
{
	mOutputFileFolder = folder;
    return folderExists(mOutputFileFolder);
}

bool HDMIStreamerProcess::setOutputFileName(const string& fName)
{
    mOutputFileName = fName;
    return true;
}

bool HDMIStreamerProcess::startStreamingg()
{

	return false;
}

bool HDMIStreamerProcess::stopStreaming()
{
	return false;
}


bool HDMIStreamerProcess::startRecording(const string& fName)
{
	return false;
}

bool HDMIStreamerProcess::stopRecording(const string& fName)
{
	return false;
}

