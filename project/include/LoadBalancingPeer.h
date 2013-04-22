/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LOAD_BALANCING_PEER_H
#define __LOAD_BALANCING_PEER_H

#include "PhotonPeer.h"
#include "Enums/ErrorCode.h"
#include "Enums/PeerStates.h"
#include "Enums/ReceiverGroup.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Peer : public Photon::PhotonPeer
		{
		public:
			Peer(Photon::PhotonListener& listener, bool useTcp=false);
			virtual ~Peer(void);

			virtual bool opJoinLobby(void);
			virtual bool opLeaveLobby(void);
			virtual bool opCreateRoom(const Common::JString& gameID, bool isVisible=true, bool isOpen=true, nByte maxPlayers=0, const Common::Hashtable& customRoomProperties=Common::Hashtable(), const Common::Hashtable& customLocalPlayerProperties=Common::Hashtable(), const Common::JVector<Common::JString>& propsListedInLobby=Common::JVector<Common::JString>());
			virtual bool opJoinRoom(const Common::JString& gameID, const Common::Hashtable& customLocalPlayerProperties=Common::Hashtable());
			virtual bool opJoinRandomRoom(const Common::Hashtable& customRoomProperties=Common::Hashtable(), nByte maxPlayers=0);
			virtual bool opLeaveRoom(void);
			virtual bool opRaiseEvent(bool reliable, const Common::Hashtable& parameters, nByte eventCode, nByte channelID=0, int* targetPlayers=NULL, short numTargetPlayers=0);
			virtual bool opRaiseEvent(bool sendReliable, const Common::Hashtable& evData, nByte eventCode, nByte channelID, nByte eventCaching, nByte receiverGroup=Lite::ReceiverGroup::OTHERS);
			virtual bool opAuthenticate(const Common::JString& appID, const Common::JString& appVersion, bool encrypted);
		protected:
			virtual bool opSetPropertiesOfPlayer(int playerNr, const Common::Hashtable& properties);
			virtual bool opSetPropertiesOfRoom(const Common::Hashtable& properties);
			static Common::Hashtable stripToCustomProperties(const Common::Hashtable& properties);
			static Common::Hashtable stripKeysWithNullValues(const Common::Hashtable& orig);
			Photon::OperationRequestParameters opCreateRoomImplementation(const Common::JString& gameID, bool isVisible, bool isOpen, nByte maxPlayers, const Common::Hashtable& customRoomProperties, const Common::Hashtable& customLocalPlayerProperties, const Common::JVector<Common::JString>& propsListedInLobby=Common::JVector<Common::JString>());
			Photon::OperationRequestParameters opJoinRoomImplementation(const Common::JString& gameID, const Common::Hashtable& customLocalPlayerProperties);
		private:
			bool opRaiseEventImplementation(bool reliable, const Common::Hashtable& parameters, nByte eventCode, nByte channelID, int* targetPlayers, short numTargetPlayers, nByte eventCaching, nByte receiverGroup);

			typedef PhotonPeer super;
			friend class Player;
			friend class Room;
			friend class MutablePlayer;
			friend class MutableRoom;
		};
	}
}

#endif