/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __ENTRY_H
#define __ENTRY_H

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			class MemoryPool;

			struct Entry
			{
				Entry* mNext;
				MemoryPool* mpPool;
			};
		}
	}
}

#endif