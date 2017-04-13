#pragma once


#ifndef GRIP_PLATFORM_ANDROID
	#if defined(ANDROID) || defined(__ANDROID__)
		#define GRIP_PLATFORM_ANDROID 1
	#endif
#endif
#ifndef GRIP_PLATFORM_ANDROID
	#define GRIP_PLATFORM_ANDROID 0
#endif

