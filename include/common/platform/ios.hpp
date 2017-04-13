#pragma once


#if defined(__APPLE_CC__)
	#include <TargetConditionals.h>
#endif


#ifndef GRIP_PLATFORM_IOS
	#if defined(__APPLE_CC__) && defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
		#define GRIP_PLATFORM_IOS 1
	#endif
#endif
#ifndef GRIP_PLATFORM_IOS
	#define GRIP_PLATFORM_IOS 0
#endif
