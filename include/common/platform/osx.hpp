#pragma once


#if defined(__APPLE_CC__)
	#include <TargetConditionals.h>
#endif


#ifndef GRIP_PLATFORM_OSX
	#if defined(__APPLE_CC__) && defined(TARGET_OS_MAC) && TARGET_OS_MAC
		#define GRIP_PLATFORM_OSX 1
	#endif
#endif
#ifndef GRIP_PLATFORM_OSX
#	define GRIP_PLATFORM_OSX 0
#endif
