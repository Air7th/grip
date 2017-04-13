#pragma once


#ifndef GRIP_COMPILER_GCC
	#if defined(__GNUC__)
		#define GRIP_COMPILER_GCC 1
	#endif
#endif
#ifndef GRIP_COMPILER_GCC
	#define GRIP_COMPILER_GCC 0
#endif

