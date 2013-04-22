/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __COMMON_DEBUG_LEVEL_H
#define __COMMON_DEBUG_LEVEL_H

namespace ExitGames
{
	namespace Common
	{
		namespace DebugLevel
		{
			enum DebugLevel
			{
				OFF = 0,
				ERRORS = 1,
				WARNINGS = 2,
				INFO = 3,
				ALL = 4
			};

			/** @file */
		}
	}
}

#endif