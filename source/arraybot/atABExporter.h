#ifndef atExporterH
#define atExporterH

#if defined (_WIN32)
    #if defined(AT_STATIC)
        #define AT_CORE
    #else
        #if defined(AT_SHARED)
            #define AT_CORE __declspec(dllexport)
        #else
            #define AT_CORE __declspec(dllimport)
        #endif
    #endif
#else
    #define AT_CORE
#endif

#endif
