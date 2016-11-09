#ifndef abExporterH
#define abExporterH

#if defined (_WIN32)
    #if defined(AB_STATIC)
        #define AT_CORE
    #else
        #if defined(AB_SHARED)
            #define AT_CORE __declspec(dllexport)
        #else
            #define AT_CORE __declspec(dllimport)
        #endif
    #endif
#else
    #define AT_CORE
#endif

#endif
