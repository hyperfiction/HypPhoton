/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __CONFIRM_ALLOWED_KEY_H
#define __CONFIRM_ALLOWED_KEY_H

#include "CompileTimeAssertTrue.h"
#include "Object.h"
#include "Enums/TypeCode.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			using namespace TypeCode;

			template<typename CType, unsigned int N=0> struct ConfirmAllowedKey
			{
				COMPILE_TIME_ASSERT_TRUE_MSG(N-N, ERROR_UNSUPPORTED_KEY_TYPE); // N-N instead of false delays the assert to actual instantiation
			};
			template<> struct ConfirmAllowedKey<nByte>
			{
				typedef nByte type;
				static const nByte typeName = BYTE;
			};
			template<> struct ConfirmAllowedKey<short>
			{
				typedef short type;
				static const nByte typeName = SHORT;
			};
			template<> struct ConfirmAllowedKey<int>
			{
				typedef int type;
				static const nByte typeName = INTEGER;
			};
			template<> struct ConfirmAllowedKey<int64>
			{
				typedef int64 type;
				static const nByte typeName = LONG;
			};
			template<> struct ConfirmAllowedKey<JString>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<> struct ConfirmAllowedKey<char*>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<> struct ConfirmAllowedKey<const char*>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<char[N]>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<const char[N]>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<> struct ConfirmAllowedKey<wchar_t*>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<> struct ConfirmAllowedKey<const wchar_t*>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<wchar_t[N]>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<const wchar_t[N]>
			{
				typedef JString type;
				static const nByte typeName = STRING;
			};
			template<> struct ConfirmAllowedKey<Object>
			{
				typedef Object type;
				typedef Object scalarType;
				static const unsigned int dimensions;
				static const nByte typeName = OBJECT;
				static const nByte customTypeName = 0;
			};

			/** @file */
		}
	}
}

#endif