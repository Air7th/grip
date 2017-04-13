#pragma once


#ifndef GRIP_COMPILER_MSVC
    #if defined(_MSC_VER)
        #define GRIP_COMPILER_MSVC 1
    #endif
#endif
#ifndef GRIP_COMPILER_MSVC
    #define GRIP_COMPILER_MSVC 0
#endif
