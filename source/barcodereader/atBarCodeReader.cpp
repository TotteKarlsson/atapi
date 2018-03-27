#pragma hdrstop
#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atSSI.lib")
#pragma comment(lib, "dslCommon.lib")
