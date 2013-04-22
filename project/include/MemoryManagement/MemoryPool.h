/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __MEMORY_POOL_H
#define __MEMORY_POOL_H

#include "defines.h"
#if defined _EG_APPLE_PLATFORM || defined _EG_PS3_PLATFORM
#	include <stdlib.h>
#else
#	include <malloc.h>
#endif
#include "Entry.h"
#include "RawStorage.h"

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			class MemoryPool
			{
			public:
				MemoryPool(void);
				~MemoryPool(void);
				void init(size_t blockSize, size_t initialCapacity=1, size_t capacityIncrement=0);
				Entry* alloc(void);
				void dealloc(void* p);
				size_t getBlockSize(void);
			private:
				void allocateBlocks(size_t amount);
				void increaseCapacity(void);

				Entry* mMemory;
				size_t mBlockSize;
				size_t mCapacity;
				size_t mCapacityIncrement;
				RawStorage mRaw;
#ifdef EG_DEBUGGER
				void* mLastAlloc;
				void* mLastDealloc;
#endif
			};
		}
	}
}

#endif