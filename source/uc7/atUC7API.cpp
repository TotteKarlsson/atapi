#pragma hdrstop
#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "poco_foundation-static.lib")

#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atSerialAPI.lib")
