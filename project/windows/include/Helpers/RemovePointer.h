/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __REMOVE_POINTER_H
#define __REMOVE_POINTER_H

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T> struct RemovePointer
			{
				typedef T type;
			};

			template<typename T> struct RemovePointer<T*>
			{
				typedef T type;
			};

			/** @file */
		}
	}
}

#endif