#pragma once


#ifndef GRIP_PLATFORM_WIN32
    #if defined(_WIN32) || defined(WIN32)
        #define GRIP_PLATFORM_WIN32 1
    #endif
#endif
#ifndef GRIP_PLATFORM_WIN32
    #define GRIP_PLATFORM_WIN32 0
#endif


#ifndef GRIP_PLATFORM_WIN64
    #if defined(_WIN64) || defined(WIN64)
        #define GRIP_PLATFORM_WIN64 1
    #endif
#endif
#ifndef GRIP_PLATFORM_WIN64
    #define GRIP_PLATFORM_WIN64 0
#endif


#ifndef GRIP_PLATFORM_WIN
    #if GRIP_PLATFORM_WIN32 || GRIP_PLATFORM_WIN64
        #define GRIP_PLATFORM_WIN 1
    #endif
#endif
#ifndef GRIP_PLATFORM_WIN
    #define GRIP_PLATFORM_WIN 0
#endif


#if GRIP_PLATFORM_WIN

    #ifndef STRICT
        #define STRICT
    #endif

    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif

    #if !defined(NOMINMAX) && defined(_MSC_VER)
        #define NOMINMAX
    #endif

    #include <tchar.h>
    #include <Windows.h>

#endif

