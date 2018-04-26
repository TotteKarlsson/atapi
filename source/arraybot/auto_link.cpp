#pragma hdrstop
#if defined DSL_STATIC
#else
	#pragma comment(lib, "dslCommon.lib")
   	#pragma comment(lib, "dslIPC.lib")
   	#pragma comment(lib, "dslMath.lib")
#endif

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

#pragma comment(lib, "atFoundation.lib")

//Thorlabs
#pragma comment(lib, "Thorlabs.MotionControl.TDIEngineB.lib")

//Motors
#pragma comment(lib, "Thorlabs.MotionControl.TCube.StepperMotorB.lib")
#pragma comment(lib, "Thorlabs.MotionControl.IntegratedStepperMotorsB.lib")
#pragma comment(lib, "Thorlabs.MotionControl.TCube.DCServoB.lib")
#pragma comment(lib, "Thorlabs.MotionControl.TCube.BrushlessMotorB.lib")
#pragma comment(lib, "Thorlabs.MotionControl.Benchtop.StepperMotorB.lib")

