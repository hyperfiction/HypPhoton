/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __MEMORY_POOL_MANAGER_H
#define __MEMORY_POOL_MANAGER_H

#include <limits.h>
#include "MemoryPool.h"

#if defined _EG_MARMALADE_PLATFORM && defined EG_DEBUGGER && !defined I3D_ARCH_ARM
#	define EG_DEACTIVATE_MEMORY_MANAGER
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace MemoryManagement
		{
			class MemoryPoolManager
			{
			public:
				MemoryPoolManager(void);
				void* alloc(size_t s);
				void dealloc(void* p);
				void* resize(void* p, size_t size);

				static MemoryPoolManager& get();
#ifdef EG_DEBUGGER
				unsigned long long ctr, ctr2, ctr3;
#endif
#ifndef EG_DEACTIVATE_MEMORY_MANAGER
			private:
				static const unsigned char M_POOL_COUNT = sizeof(size_t)*CHAR_BIT;
				MemoryPool mpPool[M_POOL_COUNT];
#endif
			};
		}
	}
}

#define EG_MALLOC  ExitGames::Common::MemoryManagement::MemoryPoolManager::get().alloc
#define EG_FREE    ExitGames::Common::MemoryManagement::MemoryPoolManager::get().dealloc
#define EG_REALLOC ExitGames::Common::MemoryManagement::MemoryPoolManager::get().resize

#endif