#ifndef atCameraServiceThreadH
#define atCameraServiceThreadH
#include "mtkThread.h"
#include "atATObject.h"

class Cuc480;
using mtk::Thread;

namespace System
{
	class TObject;
}
typedef void __fastcall (__closure *ThreadCallBack)(System::TObject*);


//The thread can only execute one function at one time..
enum DoFunction {dfOpen, dfClose};

//---------------------------------------------------------------------------
class CameraServiceThread : public Thread, public ATObject
{
	public:
								CameraServiceThread(Cuc480& camera, int id, HWND handle);

		ThreadCallBack			onCameraOpen;
		ThreadCallBack			onCameraClose;



        void					openCamera();
        void					closeCamera();
        void					run();


    private:
    	Cuc480&					mCamera;
        int						mCameraID;
        HWND					mWindowHandle;
        						//Before executing run, set what the thread should do
        DoFunction				mDoFunction;
};

//A camera service thread performs camera specific functions that need to be
//performed in an isolated thread, as suggested by the UC480 API document

#endif
