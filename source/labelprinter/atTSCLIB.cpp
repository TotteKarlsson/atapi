#pragma hdrstop
#include "atTSCLIB.h"
#include "mtkUtils.h"
#include "mtkLogger.h"
using namespace mtk;

//---------------------------------------------------------------------------

TSCLIB::TSCLIB()
:
mDLLHandle(NULL)
{}

TSCLIB::~TSCLIB()
{
	unload();
}

bool TSCLIB::printFreshBatchLabel(const string& content, int copies)
{
	if(!mDLLHandle)
    {
    	Log(lError) << "Printer DLL is not loaded. Can't print anything";
        return false;
    }

    openport("USB");

    //Centered
//DIRECTION 1,0
//CLS
//SIZE 0.965,0.2874
//TEXT 25, 55, "3", 0, 1, 1,1, "16NOV2901"
//DMATRIX 215, 35, 0, 0, x3,"16NOV2901"
//PRINT 1,1
//CLS
    stringstream tc;
    tc 	  	<< "DIRECTION 1,0\n"
            << "CLS\n"
            << "SIZE "<<0.965<<","<<0.2874<<"\n"
            << "TEXT 25, 55, \"3\", 0, 1, 1,1, \""<<content<<"\"\n"
            << "DMATRIX 215, 35, 0, 0, x2,\""<<content<<"\"\n"
            << "PRINT 1,"<<copies<<"\n";


    int ret = sendcommand(tc.str().c_str());
    Log(lDebug) << "Printer Command: "<< tc.str();
    Log(lInfo) 	<< "Printer Result: "<< ret;
    closeport();
    return (bool) ret;
}

bool TSCLIB::printCoverSlipLabel(const string& content, int copies)
{
	if(!mDLLHandle)
    {
    	Log(lError) << "Printer DLL is not loaded. Can't print anything";
        return false;
    }

    openport("USB");

    //Centered
	//Do this
//    DIRECTION 1,1
//DIRECTION 1,0
//CLS
//SIZE 0.965,0.2874
//TEXT 15, 55, "1", 0, 1, 1,1, "B54C30C15"
//TEXT 200, 55, "3", 0, 1, 1,1, "1234"
//DMATRIX 145,35, 15, 15, x2, 43,43,"B54C30C15-1234"
//PRINT 1,1
//CLS

	StringList c(content,'-');
    if(c.count() != 2)
    {
    	Log(lError) << "Can't print this label: "<<content;
        return false;
    }

    stringstream tc;
    tc      << "DIRECTION 1,0\n"
    		<< "SIZE "<<0.965<<","<<0.2874<<"\n"
            << "CLS\n"
			<< "TEXT 15, 55, \"1\", 0, 1, 1,1, \""<<c[0]<<"\"\n"
			<< "TEXT 200, 55, \"3\", 0, 1, 1,1, \""<<c[1]<<"\"\n"
            << "DMATRIX 145,35, 15, 15, x2, 43,43, \""<<content<<"\"\n"
            << "PRINT 1,"<<copies<<"\n";


    int ret = sendcommand(tc.str().c_str());
    Log(lDebug) << "Printer Command: "<< tc.str();
    Log(lInfo) 	<< "Printer result: "<< ret;
    closeport();
    return (bool) ret;
}

bool TSCLIB::load(const string& dllPath)
{
	if(fileExists(dllPath))
    {
    	Log(lInfo) << "Loading DLL: " << getFileNameNoPath(dllPath);
	  	mDLLHandle = LoadLibraryA(dllPath.c_str());
    }

    if(!mDLLHandle)
    {
    	Log(lError) << "Failed to load DLL: "<< getFileNameNoPath(dllPath);
        return false;
    }

    //Assinging function s is part of the load process..
    return assignFunctions();
}

bool TSCLIB::assignFunctions()
{
    //Load functions
    mAboutFunc = (f_int_void) GetProcAddress(mDLLHandle, "about");
    if(!mAboutFunc)
    {
    	Log(lError) <<"Failed to import function \"about\"";
    }

    mOpenPort       = (f_int_cchar)      GetProcAddress(mDLLHandle, "openport");
    if(!mOpenPort)
    {
    	Log(lError) <<"Failed to import function \"OpenPort\"";
    }

    mBarCode        = (f_BarCode)       GetProcAddress(mDLLHandle, "barcode");
    if(!mBarCode)
    {
    	Log(lError) <<"Failed to import function \"BarCode\"";
    }

    mClearBuffer    = (f_int_void)      GetProcAddress(mDLLHandle, "clearbuffer");
    if(!mClearBuffer)
    {
    	Log(lError) <<"Failed to import function \"ClearBuffer\"";
    }

    mClosePort      = (f_int_void)      GetProcAddress(mDLLHandle, "closeport");
    if(!mClosePort)
    {
    	Log(lError) <<"Failed to import function \"ClosePort\"";
    }

    mDownLoadPCX    = (f_int_cchar_cchar) GetProcAddress(mDLLHandle, "downloadpcx");
    if(!mDownLoadPCX)
    {
    	Log(lError) <<"Failed to import function \"DownloadPCX\"";
    }

    mFormFeed       = (f_int_void)      GetProcAddress(mDLLHandle, "formfeed");
    if(!mFormFeed)
    {
    	Log(lError) <<"Failed to import function \"FormFeed\"";
    }

    mNoBackFeed     = (f_int_void)      GetProcAddress(mDLLHandle, "nobackfeed");
    if(!mNoBackFeed)
    {
    	Log(lError) <<"Failed to import function \"NoBackFeed\"";
    }

    mPrinterFont    = (f_PrinterFont)   GetProcAddress(mDLLHandle, "printerfont");
    if(!mPrinterFont)
    {
    	Log(lError) <<"Failed to import function \"PrinterFont\"";
    }

    mPrintLabel     = (f_int_cchar_cchar) GetProcAddress(mDLLHandle, "printlabel");
    if(!mPrintLabel)
    {
    	Log(lError) <<"Failed to import function \"PrintLabel\"";
    }

    mSendCommand    = (f_int_cchar)      GetProcAddress(mDLLHandle, "sendcommand");
    if(!mSendCommand)
    {
    	Log(lError) <<"Failed to import function \"SendCommand\"";
    }

    mSetup          = (f_Setup)         GetProcAddress(mDLLHandle, "setup");
    if(!mSetup)
    {
    	Log(lError) <<"Failed to import function \"Setup\"";
    }

    mWindowsFont    = (f_WinFont)       GetProcAddress(mDLLHandle, "windowsfont");
    if(!mWindowsFont)
    {
    	Log(lError) <<"Failed to import function \"WindowsFont\"";
    }

    return true;
}

bool TSCLIB::isLoaded()
{
	return mDLLHandle != NULL ? true : false;
}

bool TSCLIB::unload()
{
	if(FreeLibrary(mDLLHandle))
    {
    	mDLLHandle = NULL;
    }
	
    return mDLLHandle == NULL ? true : false;
}

int TSCLIB::about()
{
    return mAboutFunc ? mAboutFunc() : -1;
}

int TSCLIB::openport(const char* printername)
{
	return mOpenPort ? mOpenPort(printername) : -1;
}

int TSCLIB::barcode(const char *x, const char *y, const char *type, const char *height, const char *readable, const char *rotation, const char *narrow, const char *wide, const char *code)
{
    return mBarCode ? mBarCode(x, y, type, height,	readable, rotation, narrow,	wide, code) : -1;
}

int TSCLIB::clearbuffer()
{
    return mClearBuffer ? mClearBuffer() : -1;
}

int TSCLIB::closeport()
{
    return mClosePort ? mClosePort() : -1;
}

int TSCLIB::downloadpcx(const char *filename,const char *image_name)
{
    return mDownLoadPCX ? mDownLoadPCX(filename, image_name) : -1;
}

int TSCLIB::formfeed()
{
    return mFormFeed ? mFormFeed() : -1;
}

int TSCLIB::nobackfeed()
{
    return mNoBackFeed ? mNoBackFeed() : -1;
}

int TSCLIB::printerfont(const char *x, const char *y, const char *fonttype, const char *rotation, const char *xmul, const char *ymul, const char *text)
{
    return mPrinterFont ? mPrinterFont(x, y, fonttype, rotation, xmul, ymul, text) : -1;
}

int TSCLIB::printlabel(const char *set, const char *copy)
{
    return mPrintLabel ? mPrintLabel(set, copy) : -1;
}

int TSCLIB::sendcommand(const char *printercommand)
{
    return mSendCommand ? mSendCommand(printercommand) : -1;
}

int TSCLIB::setup(const char *width, const char *height, const char *speed, const char *density, const char *sensor, const char *vertical, const char *offset)
{
    return mSetup ? mSetup(width, height, speed, density, sensor, vertical, offset) : -1;
}

int TSCLIB::windowsfont(int x, int y, int fontheight, int rotation, int fontstyle, int fontunderline, const char *szFaceName, const char *content)
{
    return mWindowsFont ? mWindowsFont(x, y, fontheight, rotation, fontstyle, fontunderline, szFaceName, content) : -1;
}
