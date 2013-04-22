/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __CONNECTION_STATE_H
#define __CONNECTION_STATE_H

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace ConnectionState
			{
				enum ConnectionState
				{
					DISCONNECTED             = 0,
					CONNECTING               = 1,
					ACKNOWLEDGING_CONNECT    = 2,
					CONNECTED                = 3,
					DISCONNECTING            = 4,
					ACKNOWLEDGING_DISCONNECT = 5,
					ZOMBIE                   = 6
				};

				/** @file */
			}
		}
	}
}

#endif