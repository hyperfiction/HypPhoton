/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LOAD_BALANCING_LISTENER_H
#define __LOAD_BALANCING_LISTENER_H

#include "PhotonPeer.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Player;

		class Listener: public Common::BaseListener
		{
		public:
			virtual ~Listener(void){}

			// receive and print out PhotonLoadBalancing debug out here
			virtual void debugReturn(Common::DebugLevel::DebugLevel debugLevel, const Common::JString& string) = 0;

			// implement your error-handling here
			virtual void connectionErrorReturn(int errorCode) = 0;
			virtual void clientErrorReturn(int errorCode) = 0;
			virtual void warningReturn(int warningCode) = 0;
			virtual void serverErrorReturn(int errorCode) = 0;

			// events, triggered by certain operations of all players in the same room
			virtual void joinRoomEventAction(int playerNr, const Common::JVector<int>& playernrs, const Player& player) = 0;
			virtual void leaveRoomEventAction(int playerNr) = 0;
			virtual void customEventAction(int playerNr, nByte eventCode, const Common::Hashtable& eventContent) = 0;

			// callbacks for operations on PhotonLoadBalancing server
			virtual void connectReturn(int errorCode, const Common::JString& errorString) = 0;
			virtual void disconnectReturn(void) = 0;
			virtual void createRoomReturn(int localPlayerNr, const Common::Hashtable& roomProperties, const Common::Hashtable& playerProperties, int errorCode, const Common::JString& errorString) = 0;
			virtual void joinRoomReturn(int localPlayerNr, const Common::Hashtable& roomProperties, const Common::Hashtable& playerProperties, int errorCode, const Common::JString& errorString) = 0;
			virtual void joinRandomRoomReturn(int localPlayerNr, const Common::Hashtable& roomProperties, const Common::Hashtable& playerProperties, int errorCode, const Common::JString& errorString) = 0;
			virtual void leaveRoomReturn(int errorCode, const Common::JString& errorString) = 0;
			virtual void gotQueuedReturn(void) = 0;
			virtual void joinLobbyReturn(void) = 0;
			virtual void leaveLobbyReturn(void) = 0;
		};
		/** @file */
	}
}

#endif