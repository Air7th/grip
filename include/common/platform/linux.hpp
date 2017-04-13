#pragma once


#ifndef GRIP_PLATFORM_LINUX
	#if defined(linux) || defined(__linux) || defined(__linux__)
		#define GRIP_PLATFORM_LINUX 1
	#endif
#endif
#ifndef GRIP_PLATFORM_LINUX
	#define GRIP_PLATFORM_LINUX 0
#endif
