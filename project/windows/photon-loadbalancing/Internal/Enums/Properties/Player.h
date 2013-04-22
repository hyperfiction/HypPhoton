/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PLAYER_H
#define __PLAYER_H

#include "PhotonPeer.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			// Photon properties, internally set by LoadBalancing (LoadBalancing builtin properties)
			namespace Properties
			{
				namespace Player
				{
					static const nByte PLAYERNAME =  255;
				};
			}
		}
	}
}

#endif