/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __OBJECT_TO_STRING_CONVERTER_H
#define __OBJECT_TO_STRING_CONVERTER_H

#include "JString.h"
namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Etype>
			class ObjectToStringConverter
			{
			public:
				static JString toString(Etype* data, unsigned int size, bool withTypes=false);
			};

			template<typename Etype>
			class ObjectToStringConverter<Etype*>
			{
			public:
				static JString toString(Etype** data, unsigned int size, bool withTypes=false);
			};



			/** @file */

			template<typename Etype>
			JString ObjectToStringConverter<Etype>::toString(Etype* data, unsigned int size, bool withTypes)
			{
				JString retStr = L"[";
				for(unsigned int i=0; i<size; ++i)
				{
					retStr += data[i].toString(withTypes);
					if(i < size-1)
						retStr += L", ";
				}
				retStr += L"]";
				return retStr;
			}

			template<typename Etype>
			JString ObjectToStringConverter<Etype*>::toString(Etype** data, unsigned int size, bool withTypes)
			{
				JString retStr = L"[";
				for(unsigned int i=0; i<size; ++i)
				{
					retStr += data[i]->toString(withTypes);
					if(i < size-1)
						retStr += L", ";
				}
				retStr += L"]";
				return retStr;
			}
		}
	}
}

#endif