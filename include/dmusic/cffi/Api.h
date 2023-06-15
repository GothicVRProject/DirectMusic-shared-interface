#pragma once

#ifdef __cplusplus
    #define DMSC_EXTERN extern "C"
#else
    #include <stdbool.h>
    #define DMSC_EXTERN
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef DMSC_EXPORTS
        #ifdef __GNUC__
            #define DMSC_API DMSC_EXTERN __attribute__((dllexport))
        #else
            #define DMSC_API DMSC_EXTERN __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define DMSC_API DMSC_EXTERN __attribute__((dllimport))
        #else
            #define DMSC_API DMSC_EXTERN __declspec(dllimport)
        #endif
    #endif
    #define DMSC_INTERNAL
#else
    #define DMSC_API DMSC_EXTERN __attribute__((visibility("default")))
    #define DMSC_INTERNAL DMSC_EXTERN __attribute__((visibility("hidden")))
#endif
