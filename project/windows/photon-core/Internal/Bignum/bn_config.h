#ifndef _BN_CONFIG_H
#define _BN_CONFIG_H

#include "defines.h"

#ifndef asm
#	define asm __asm__ // older gcc/mingw versions do not know "asm", when compiling without gnu extensions
#endif

#if defined __IPHONE_OS_VERSION_MIN_REQUIRED
#   define OPENSSL_NO_ASM
#endif
#if !defined __LITTLE_ENDIAN__ && (defined _EG_MARMALADE_PLATFORM || defined _EG_BLACKBERRY_PLATFORM)
#	define __LITTLE_ENDIAN__
#endif

#if !defined BN_HAS_DEBUG_BUILD
#   if defined DEBUG || defined _DEBUG
#       define BN_HAS_DEBUG_BUILD 1
#   else // DEBUG || _DEBUG
#       define BN_HAS_DEBUG_BUILD 0
#   endif // DEBUG || _DEBUG
#endif // BN_ENABLE_ASSERTIONS

#if !defined BN_ENABLE_ASSERTIONS && ! defined _EG_MARMALADE_PLATFORM
#   define BN_ENABLE_ASSERTIONS BN_HAS_DEBUG_BUILD
#endif // BN_ENABLE_ASSERTIONS

#if !defined BN_ENABLE_STATIC_ASSERTIONS
#   define BN_ENABLE_STATIC_ASSERTIONS BN_HAS_DEBUG_BUILD
#endif // BN_ENABLE_STATIC_ASSERTIONS

#if !defined BN_HAS_PRETTY_FUNCTION_MACRO
#   define BN_HAS_PRETTY_FUNCTION_MACRO 0
#endif // BN_HAS_PRETTY_FUNCTION_MACRO

#if !defined BN_HAS_FUNCTION_MACRO
#   define BN_HAS_FUNCTION_MACRO 1
#endif // BN_HAS_FUNCTION_MACRO

#if BN_HAS_PRETTY_FUNCTION_MACRO
#   define BN_FUNCTION __PRETTY_FUNCTION__
#elif BN_HAS_FUNCTION_MACRO
#   define BN_FUNCTION __FUNCTION__
#else
#   define BN_FUNCTION ""
#endif


#if !defined BN_ENABLE_CALL_STACK_PRINTING
#   define BN_ENABLE_CALL_STACK_PRINTING BN_HAS_DEBUG_BUILD
#endif // BN_ENABLE_CALL_STACK_PRINTING

#if !defined BN_CPU_HAS_LITTLE_ENDIAN
#   if defined WIN32
#       define BN_CPU_HAS_LITTLE_ENDIAN 1
#   elif defined __linux__
#       define BN_CPU_HAS_LITTLE_ENDIAN 1
#   elif defined __SYMBIAN32__
#       define BN_CPU_HAS_LITTLE_ENDIAN 1
#   elif defined __PALM__
#       define BN_CPU_HAS_LITTLE_ENDIAN 0
#   elif defined __LITTLE_ENDIAN__
#       define BN_CPU_HAS_LITTLE_ENDIAN 1
#   elif defined __BIG_ENDIAN__
#       define BN_CPU_HAS_LITTLE_ENDIAN 0
#   else
#       error Please define "BN_CPU_HAS_LITTLE_ENDIAN" macro for your platform
#   endif
#endif // BN_CPU_HAS_LITTLE_ENDIAN

#ifdef PACKED
#   undef PACKED
#endif
#if !defined BN_NEED_ATTRIBUTE_PACKED
#   if defined __GNUC__
#       define PACKED __attribute__((packed))
#   else
#       define PACKED
#   endif
#else
#   define PACKED __attribute__((packed))
#endif // BN_NEED_ATTRIBUTE_PACKED

#if !defined BN_EVENT_SERIALIZABLE
#   define BN_EVENT_SERIALIZABLE 0
#endif // BN_EVENT_SERIALIZABLE

#if !defined BN_EVENT_CLONEABLE
#   define BN_EVENT_CLONEABLE 0
#endif // BN_EVENT_CLONEABLE

#if !defined BN_NEED_SAFE_SMARTPOINTER
#   define BN_NEED_SAFE_SMARTPOINTER 0
#endif // BN_NEED_SAFE_SMARTPOINTER

#if !defined BN_THREADSAFE_EVENT_REGISTRY
#   define BN_THREADSAFE_EVENT_REGISTRY 0
#endif // BN_THREADSAFE_EVENT_REGISTRY

#if !defined BN_HAS_EVENTREGISTRY_SINGLETON
#   define BN_HAS_EVENTREGISTRY_SINGLETON 0
#endif // BN_HAS_EVENTREGISTRY_SINGLETON

#if !defined BN_EXPORT
#   if defined __SYMBIAN32__
#       define BN_EXPORT EXPORT_C
#   elif defined WIN32
#       define BN_EXPORT __declspec(dllexport)
#   else
#       define BN_EXPORT
#endif
#endif

#endif // _BN_CONFIG_H
