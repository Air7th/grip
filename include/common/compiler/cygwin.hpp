#pragma once


#ifndef GRIP_COMPILER_CYGWIN
	#if defined(__CYGWIN__)
		#define GRIP_COMPILER_CYGWIN 1
	#endif
#endif
#ifndef GRIP_COMPILER_CYGWIN
	#define GRIP_COMPILER_CYGWIN 0
#endif

