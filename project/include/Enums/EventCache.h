/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LITE_EVENT_CACHE_H
#define __LITE_EVENT_CACHE_H

namespace ExitGames
{
	namespace Lite
	{
		namespace EventCache
		{
			static const nByte DO_NOT_CACHE  = 0;
			static const nByte MERGE_CACHE   = 1;
			static const nByte REPLACE_CACHE = 2;
			static const nByte REMOVE_CACHE  = 3;
			static const nByte ADD_TO_ROOM_CACHE = 4;
			static const nByte ADD_TO_ROOM_CACHE_GLOBAL = 5; // actor will become 0 (room owned)
			static const nByte REMOVE_FROM_ROOM_CACHE = 6;
			static const nByte REMOVE_FROM_ROOM_CACHE_FOR_ACTORS_LEFT  = 7; // Removes events of players who already left the room (cleaning up)
		}

		/** @file */
	}
}

#endif