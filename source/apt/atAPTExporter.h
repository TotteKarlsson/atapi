#ifndef atAPTExporterH
#define atAPTExporterH

#if defined (_WIN32)
    #if defined(AT_STATIC)
        #define AT_APT
    #else
        #if defined(AT_SHARED)
            #define AT_APT __declspec(dllexport)
        #else
            #define AT_APT __declspec(dllimport)
        #endif
    #endif
#else
    #define AT_APT
#endif

#endif
