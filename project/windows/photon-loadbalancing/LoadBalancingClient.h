/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LOAD_BALANCING_CLIENT_H
#define __LOAD_BALANCING_CLIENT_H

#include "LoadBalancingRoom.h"
#include "LoadBalancingListener.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Client : public Peer, public Photon::PhotonListener
		{
		public:
			Client(LoadBalancing::Listener& listener, const Common::JString& applicationID, const Common::JString& appVersion, const Common::JString& username, bool useTcp=false);
			virtual ~Client(void);

			virtual bool connect(void);
			virtual bool connect(const Common::JString& masterServerAddress);
			virtual void disconnect(void);

			virtual bool opJoinLobby(void);
			virtual bool opLeaveLobby(void);
			virtual bool opCreateRoom(const Common::JString& gameID, bool isVisible=true, bool isOpen=true, nByte maxPlayers=0, const Common::Hashtable& customRoomProperties=Common::Hashtable(), const Common::Hashtable& customLocalPlayerProperties=Common::Hashtable(), const Common::JVector<Common::JString>& propsListedInLobby=Common::JVector<Common::JString>());
			virtual bool opJoinRoom(const Common::JString& gameID, const Common::Hashtable& customLocalPlayerProperties=Common::Hashtable());
			virtual bool opJoinRandomRoom(const Common::Hashtable& customRoomProperties=Common::Hashtable(), nByte maxPlayers=0, const Common::Hashtable& customLocalPlayerProperties=Common::Hashtable());
			virtual bool opLeaveRoom(void);

			PeerStates::PeerStates getState(void) const;
			const Common::JString& getMasterserverAddress(void) const;
			int getCountPlayersIngame(void) const;
			int getCountGamesRunning(void) const;
			int getCountPlayersOnline(void) const;
			int getQueuePosition(void) const;
			MutableRoom& getCurrentlyJoinedRoom(void);
			const Common::JVector<Room>& getRoomList(void) const;
			const Common::JVector<Common::JString>& getRoomNameList(void) const;
			bool getIsInRoom(void) const;
			bool getIsInGameRoom(void) const;
			bool getIsInLobby(void) const;
			bool getAutoJoinLobby(void) const;
			void setAutoJoinLobby(bool onConnect);
		protected:
			virtual bool opAuthenticate(const Common::JString& appID, const Common::JString& appVersion, bool encrypted);
			virtual bool opSetPropertiesOfPlayer(int playerNr, const Common::Hashtable& properties);
			virtual bool opSetPropertiesOfRoom(const Common::Hashtable& properties);

			//From Photon::Listener
			virtual void onOperationResponse(const Photon::OperationResponse& operationResponse);
			virtual void onStatusChanged(int statusCode);
			virtual void onEvent(const Photon::EventData& eventData);
			virtual void debugReturn(Common::DebugLevel::DebugLevel debugLevel, const Common::JString& string);
		private:
			void readoutProperties(Common::Hashtable& roomProperties, Common::Hashtable& playerProperties, bool multiplePlayers, int targetPlayerNr);
			void handleConnectionFlowError(PeerStates::PeerStates oldState, int errorCode, const Common::JString& errorString);
			void onConnectToMasterFinished(bool comingFromGameserver);

			bool getIsOnGameServer(void) const;

			typedef Peer super;

			Listener& mListener;
			Common::JString mGameserver;
			Common::JString mAppVersion;
			Common::JString mRoomName;
			Common::JString mAppID;
			int mPeerCount;
			int mRoomCount;
			int mMasterPeerCount;
			nByte mLastJoinType;
			int mQueuePosition;
			MutableRoom mCurrentlyJoinedRoom;
			Common::JVector<Room> mRoomList;
			Common::JVector<Common::JString> mRoomNameList;
			int mSenttime;
			int mCachedErrorCodeFromGameServer;
			Common::JString mCachedErrorStringFromGameServer;
			bool mUseTcp;
			Common::JString mMasterserver;
			bool mAutoJoinLobby;

			PeerStates::PeerStates mState;
		};
	}
}

#endif