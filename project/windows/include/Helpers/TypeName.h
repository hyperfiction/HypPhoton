/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __TYPE_NAME_H
#define __TYPE_NAME_H

#include "JString.h"
#include <typeinfo>
#if !defined _EG_WINDOWS_PLATFORM && !defined _EG_MARMALADE_PLATFORM && !defined _EG_ANDROID_PLATFORM && !defined _EG_BLACKBERRY_PLATFORM && !defined _EG_PS3_PLATFORM
#	include <cxxabi.h>
#elif defined _EG_MARMALADE_PLATFORM && defined __GNUC__ || defined _EG_BLACKBERRY_PLATFORM
	namespace abi
	{ 
		extern "C" char* __cxa_demangle(const char* mangled_name, char* buf, size_t* n, int* status); 
	} 
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			namespace TypeName
			{
				template<typename Etype> JString get(void);
				template<typename Etype> JString get(Etype& arg);
				template<typename Etype> JString get(Etype* pArg);
				JString cut(const char* rawTypeName);
			}

			template<typename Etype>
			JString TypeName::get(void)
			{
				return cut(typeid(Etype).name());
			}

			template<typename Etype>
			JString TypeName::get(Etype& arg)
			{
				return cut(typeid(arg).name());
			}
	
			template<typename Etype>
			JString TypeName::get(Etype* pArg)
			{
				return cut(typeid(*pArg).name());
			}
		}
	}
}

#endif
