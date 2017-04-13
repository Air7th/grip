#pragma once


#include <common/compiler.hpp>
#include <common/platform.hpp>


#ifndef GRIP_API
    #if GRIP_BUILD_SHARED_LIBRARY
        #if GRIP_PLATFORM_WIN && GRIP_COMPILER_MSVC
            #define GRIP_API __declspec(dllexport)
        #endif
    #elif GRIP_USE_SHARED_LIBRARY
        #if GRIP_PLATFORM_WIN && GRIP_COMPILER_MSVC
            #define GRIP_API __declspec(dllimport)
        #endif
    #endif
#endif
#ifndef GRIP_API
    #define GRIP_API
#endif


#ifndef GRIP_APIENTRY
    # if GRIP_PLATFORM_WIN && GRIP_COMPILER_MSVC
        #define GRIP_APIENTRY __stdcall
    #endif
#endif
#ifndef GRIP_APIENTRY
    #define GRIP_APIENTRY
#endif

