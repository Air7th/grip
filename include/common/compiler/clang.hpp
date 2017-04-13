#pragma once


#ifndef GRIP_COMPILER_CLANG
	#if defined(__clang__)
		#define GRIP_COMPILER_CLANG 1
	#endif
#endif
#ifndef GRIP_COMPILER_CLANG
	#define GRIP_COMPILER_CLANG 0
#endif
