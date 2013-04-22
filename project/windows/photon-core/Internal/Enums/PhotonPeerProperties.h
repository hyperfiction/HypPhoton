/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PHOTON_PEER_PROPERTIES_H
#define __PHOTON_PEER_PROPERTIES_H

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace PhotonPeerProperties
			{
				static const int   SENTCOUNTALLOWANCE                 =         5; // number of re-send retries before a peer is considered lost/disconnected
				static const int   SENTTIMEALLOWANCE                  =     10000; // max time interval in ms for re-send retries before a peer is considered lost/disconnected
				static const int   TIMEPINGINTERVAL                   =      2000; // ms without reliable command, before ping will be sent
				static const int   CHANNEL_COUNT_DEFAULT              =        20; // default number of channels per peer
				static const int   WINDOW_SIZE                        =    (4*32);
				static const int   DEBUG_IN_COMMANDS                  =     false;
				static const int   DEBUG_IN_QUEUE_COMMANDS            =     false;
				static const int   DEBUG_OUT_COMMANDS                 =     false;
				static const int   DEBUG_ACK_COMMANDS                 =     false;
				static const int   DEBUG_NEW_IN_COMMANDS              =     false;
				static const int   DEBUG_DISPATCH_COMMANDS            =     false;
				static const int   DEBUG_RING_COUNT                   =     false;
				static const nByte UDP_PACKAGE_HEADER_LENGTH          =        12;
				static const int   ENET_PEER_PACKET_LOSS_SCALE        = (1 << 16);
				static const int   ENET_PEER_DEFAULT_ROUND_TRIP_TIME  =       300;
				static const int   ENET_PEER_PACKET_THROTTLE_INTERVAL =      5000;
			}
		}
	}
}

#endif