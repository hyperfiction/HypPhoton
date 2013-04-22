/*******************************************************************************
*
*   Cross-platform ASSERT macro definition
*
*******************************************************************************/
#ifndef _BN_ASSERT_H_
#define _BN_ASSERT_H_

#include "Internal/Bignum/bn_config.h"

//comment it to prevent redefinition warning
/*
#if BN_ENABLE_STATIC_ASSERTIONS
#   define COMPILE_TIME_ASSERT_TRUE(name, condition)                                       \
#        const int name[(int)(condition) ? 1 : -1] = { 0 }
#else
#   define COMPILE_TIME_ASSERT_TRUE(name, condition)
#endif
*/

#if BN_ENABLE_ASSERTIONS
#   if defined WIN32 && !defined _WIN32_WCE
#       include <windows.h>
#       define CP_ASSERT(cond)                                                  \
	do									\
        {                                                                       \
            WCHAR buffer[512];                                                  \
            wsprintfW(buffer, L"Cond: %S  File: %S\r\nLine: %d\r\nFunction: %S",\
                #cond,__FILE__, __LINE__, __FUNCTION__);                        \
                                                                                \
            if (!(cond))                                                        \
            {                                                                   \
                MessageBoxW(NULL, buffer, L"Assertion failed", MB_OK);          \
                TerminateProcess(GetCurrentProcess(), 0);                       \
            }                                                                   \
	}while(0)

#   elif defined UNDER_CE
#       define CP_ASSERT(cond)                                                  \
        do                                                                      \
        {                                                                       \
            WCHAR buffer[512];                                                  \
            wsprintfW(buffer, L"File: %S\r\nLine: %d", __FILE__, __LINE__);     \
                                                                                \
            if (!(cond))                                                        \
            {                                                                   \
                MessageBoxW(NULL, buffer, L"Assertion failed", MB_OK);          \
                TerminateProcess(GetCurrentProcess(), 0);                       \
            }                                                                   \
        }                                                                       \
        while (0)
#   elif defined __PALM__
#       define CP_ASSERT(cond)                                                  \
        do                                                                      \
        {                                                                       \
            char* buffer = (char*) MemPtrNew(512);                                      \
            StrPrintF(buffer,                                                   \
                     "Assertion failed File: %s Line: %d Function: %s",         \
                      __FILE__, __LINE__, __FUNCTION__);                        \
                                                                                \
            if (!(cond))                                                        \
            {                                                                   \
                SysFatalAlert(buffer);                                          \
            }                                                                   \
            MemPtrFree((MemPtr) buffer);                                                  \
        }                                                                       \
        while (0)
#   elif defined __SYMBIAN32__
#       include <assert.h>
#       define CP_ASSERT(cond) assert(cond)
#   elif defined __linux__
#       include <stdlib.h>
#       define CP_ASSERT(cond)                                                  \
        if (!(cond))                                                            \
        {                                                                       \
            char buffer[512];                                                   \
            sprintf(buffer, "xmessage \'Cond: %s\nFile: %s\nLine:"              \
                              " %d\nFunction: %s\'",                            \
                #cond, __FILE__, __LINE__, __FUNCTION__);                       \
            system(buffer);                                                     \
            exit(1);                                                            \
        }
#   elif defined SN_TARGET_PS3
#       include <stdlib.h>
#       define CP_ASSERT(cond)                                                  \
        if (!(cond))                                                            \
        {                                                                       \
            char buffer[1024];                                                  \
            sprintf(buffer, "xmessage \'Cond: %s\nFile: %s\nLine:"              \
                              " %d\nFunction: %s\'",                            \
                #cond, __FILE__, __LINE__, __FUNCTION__);                       \
            printf(buffer);                                                     \
            exit(1);                                                            \
        }
#   else
#       error Please define "CP_ASSERT" macro for your platform
#   endif
#else  // BN_ENABLE_ASSERTIONS
#   define CP_ASSERT(cond)
#endif // BN_ENABLE_ASSERTIONS

#endif // _BN_ASSERT_H_
