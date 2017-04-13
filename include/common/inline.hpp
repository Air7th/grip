#pragma once


#include <common/compiler.hpp>
#include <common/platform.hpp>


#if defined(GRIP_FORCEINLINE)
	#if GRIP_COMPILER_MSVC
		#define GRIP_INLINE __forceinline
		#define GRIP_NEVER_INLINE __declspec((noinline))
	#elif GRIP_COMPILER_GCC | GRIP_COMPILER_CLANG
		#define GRIP_INLINE inline __attribute__((__always_inline__))
		#define GRIP_NEVER_INLINE __attribute__((__noinline__))
	#else
		#define GRIP_INLINE inline
		#define GRIP_NEVER_INLINE
	#endif
#else
	#define GRIP_INLINE inline
	#define GRIP_NEVER_INLINE 
#endif

