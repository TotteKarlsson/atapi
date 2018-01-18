#pragma hdrstop
#include "atHDMIStreamerProcess.h"
#include "mtkFileUtils.h"
#include "mtkLogger.h"
#include "Poco/File.h"
using namespace mtk;
using namespace Poco;

//---------------------------------------------------------------------------
HDMIStreamerProcess::HDMIStreamerProcess(const string& bmExecutable, const string& pipeName)
:
mBMStreamerExecutable(bmExecutable),
mStartStreamingRequest(false),
mStopStreamingRequest(false),
mIsStreaming(false),
mOutStream(NULL),
mBitRate(20000)
{}


HDMIStreamerProcess::~HDMIStreamerProcess()
{
	delete mOutStream;
}

void HDMIStreamerProcess::assignCallBacks(Callback one, Callback two, Callback three)
{
	onEnter 	= one;
    onProgress 	= two;
    onExit 		= three;
}

void HDMIStreamerProcess::exit()
{
	this->stopStreaming();
    mtk::Thread::stop();
}

bool HDMIStreamerProcess::startStreaming()
{
	if(!this->isRunning())
    {
    	mtk::Thread::run();
    }

	return false;
}

bool HDMIStreamerProcess::stopStreaming()
{
	if(mOutStream)
    {
    	(*mOutStream) << std::string(1, 'q');
    	(*mOutStream) << endl;
    }

    //Quit thread
    mIsTimeToDie = true;
	return false;
}

bool HDMIStreamerProcess::startRecording(const string& fName, int bitRate)
{
	//Change file name
    mOutputFileName = fName;
    mBitRate = bitRate;
	startStreaming();
	return false;
}

bool HDMIStreamerProcess::stopRecording()
{
	stopStreaming();
	return false;
}

void HDMIStreamerProcess::run()
{
	mIsStarted = true;
    if(onEnter)
    {
    	onEnter(0,0);
    }

	mIsRunning = true;

	try
    {
        //Setup arguments
        StringList args;
        args.append("-a");		//Start recording immediately
        args.append("-b" + mtk::toString(mBitRate));
        args.append("-f" + mOutputFileName );

        //Capture output
        Pipe outPipe;

        //Tell process to start/stop stuff
        Pipe inPipe;

		//Capture stdout and stderr to outPipe
        ProcessHandle ph = Process::launch(mBMStreamerExecutable, args, &inPipe, &outPipe, &outPipe);

        //Use stream objects to read and write to the pipes
        PipeInputStream istr(outPipe);
		mOutStream = new PipeOutputStream(inPipe);

        string s;
		int progress(0);
        int c = istr.get();
        bool exitRequested(false);

        while(!exitRequested)
        {
            s += (char) c;
            if(c == '\n' || c == '\r')
            {
            	progress = parseOutput(s);
                Log(lDebug5) << s;
                s.clear();

                if(onProgress)
                {
        		    Poco::File aFile(mOutputFileName);
                    if(aFile.exists())
                    {
		            	long sz = aFile.getSize();
		                onProgress(sz, 0);
                    }
                }
            }

//            if(istr.peek() != EOF)
            {
            	c = istr.get();
            }
//            else
//            {
//            	c = 0;
//            }

			if(mIsTimeToDie)
            {
				exitRequested = true;
            }
        }

        //Thread is exiting
        //Waith for managed process to exit
        int ec = ph.wait();
        Log(lInfo) <<"Process exit code: "<<ec;
    }
    catch(...)
    {
		Log(lError) << "Unhandled exception..";
    }

	Log(lInfo) << "Exiting thread..";

    if(onExit)
    {
    	onExit(0,0);
    }

	mIsRunning = false;
	mIsFinished = true;
}

int HDMIStreamerProcess::parseOutput(const string& s)
{
    Log(lDebug5) << "Parsing string: "<<s;
    //Check and parse string
   	return (s.size()) ? 0 : 1;
}
