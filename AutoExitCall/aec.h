#ifndef __AUTO_EXIT_CALL_H__
#define __AUTO_EXIT_CALL_H__

#include <setjmp.h>

#define __CLS(a,b) a##b
#define _CLS(a,b) __CLS(a,b)
#define CLS(c) _CLS(c,__LINE__)
#define OnExitScope() \
	struct CLS(AEC){\
		int __f;\
		jmp_buf __j;\
		CLS(AEC)():__f(0){}\
		~CLS(AEC)(){\
			if( __f++ == 0 ){ longjmp(__j,1); }\
		}\
	}CLS(_AEC);\
	if(setjmp(CLS(_AEC).__j)!=0)

#endif
