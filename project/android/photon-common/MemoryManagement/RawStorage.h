/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __RAW_STORAGE_H
#define __RAW_STORAGE_H

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			struct RawStorage
			{
				RawStorage* mpNext;
			};
		}
	}
}

#endif