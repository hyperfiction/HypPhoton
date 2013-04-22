/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PEER_STATES_H
#define __PEER_STATES_H

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace PeerStates
		{
			enum PeerStates
			{
				Uninitialized,
				PeerCreated,
				Connecting,
				Connected,
				Queued,
				Authenticated,
				JoinedLobby,
				DisconnectingFromMasterserver,
				ConnectingToGameserver,
				ConnectedToGameserver,
				AuthenticatedOnGameServer,
				Joining,
				Joined,
				Leaving,
				Left,
				DisconnectingFromGameserver,
				ConnectingToMasterserver,
				ConnectedComingFromGameserver,
				QueuedComingFromGameserver,
				AuthenticatedComingFromGameserver,
				Disconnecting,
				Disconnected,
			};
			/** @file */
		}
	}
}

#endif