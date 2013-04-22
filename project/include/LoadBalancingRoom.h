/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LOAD_BALANCING_ROOM_H
#define __LOAD_BALANCING_ROOM_H

#include "LoadBalancingPlayer.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Peer;

		class Room : public Common::Base
		{
		public:
			using Common::ToString::toString;

			virtual ~Room(void);

			Room(const Room& toCopy);
			virtual Room& operator=(const Room& toCopy);

			const Common::JString& getName(void) const;
			nByte getPlayerCount(void) const;
			nByte getMaxPlayers(void) const;
			bool getIsOpen(void) const;
			const Common::Hashtable& getCustomProperties(void) const;

			bool operator==(const Room& room) const;
			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
			virtual Common::JString toString(bool withTypes, bool withCustomProperties) const;
		protected:
			Room(const Common::JString& name, const Common::Hashtable& properties);

			virtual Room& assign(const Room& toCopy);
			virtual void cacheProperties(const Common::Hashtable& properties);
			virtual Common::JString payloadToString(bool withTypes=false, bool withCustomProperties=false) const;

			Common::JString mName;
			nByte mPlayerCount;
			nByte mMaxPlayers;
			bool mIsOpen;
			Common::Hashtable mCustomProperties;
		private:
			Room(void);

			friend class Client;
		};



		class MutableRoom : public Room
		{
		public:
			virtual ~MutableRoom(void);

			MutableRoom(const MutableRoom& toCopy);
			virtual MutableRoom& operator=(const Room& toCopy);

			void setMaxPlayers(nByte maxPlayers);
			void setIsOpen(bool isOpen);
			bool getIsVisible(void) const;
			void setIsVisible(bool isVisible);
			const Common::JVector<Player>& getPlayers(void) const;
			const Player* getPlayerForNumber(int playerNumber) const;
			MutablePlayer& getLocalPlayer(void);
			int getMasterClientID(void) const;
			const Common::JVector<Common::JString>& getPropsListedInLobby(void) const;
			void setPropsListedInLobby(const Common::JVector<Common::JString>& propsListedInLobby);

			void mergeCustomProperties(const Common::Hashtable& customProperties);
			template<typename ktype, typename vtype> void addCustomProperty(const ktype& key, const vtype& value);
			void addCustomProperties(const Common::Hashtable& customProperties);
			template<typename ktype> void removeCustomProperty(const ktype& key);
			template<typename ktype> void removeCustomProperties(const ktype* const keys, unsigned int count);
			virtual Common::JString toString(bool withTypes=false, bool withCustomProperties=false, bool withLocalPlayer=false, bool withPlayers=false) const;
		protected:
			MutableRoom(const Common::JString& ID, const Common::Hashtable& properties, Peer* peer, const Common::JVector<Common::JString>& propsListedInLobby=Common::JVector<Common::JString>());

			virtual MutableRoom& assign(const Room& toCopy);
			virtual void cacheProperties(const Common::Hashtable& properties);
			template<typename Etype> void setRoomProperty(nByte key, Etype val);

			void setPlayers(const Common::JVector<Player>& players);
			void setPlayerForNumber(int playerNumber, const Player& player);
			void setPlayerForNumber(int playerNumber, const Common::Hashtable& properties);
			void removeAllPlayers(void);
			void addPlayer(const Player& player);
			void addPlayer(int number, const Common::Hashtable& properties);
			bool removePlayer(const Player& player);
			bool removePlayer(int number);
			void setLocalPlayer(const MutablePlayer& player);
			void setLocalPlayer(int number, const Common::Hashtable& properties);
			virtual Player createPlayer(int number, const Common::Hashtable& properties) const;
			virtual MutablePlayer createMutablePlayer(int number, const Common::Hashtable& properties) const;
			virtual Common::JString payloadToString(bool withCustomProperties=false, bool withTypes=false, bool withLocalPlayer=false, bool withPlayers=false) const;
		private:
			typedef Room super;

			Peer* mLoadBalancingPeer;
			bool mIsVisible;
			Common::JVector<Player> mPlayers;
			MutablePlayer mLocalPlayer;
			int mMasterClientID;
			Common::JVector<Common::JString> mPropsListedInLobby;

			friend class Client;
		};

		template<typename ktype, typename vtype>
		void MutableRoom::addCustomProperty(const ktype& key, const vtype& value)
		{
			Common::Hashtable hash;
			hash.put(key, value);
			addCustomProperties(hash);
		}

		template<typename ktype>
		void MutableRoom::removeCustomProperty(const ktype& key)
		{
			removeCustomProperties(&key, 1);
		}

		template<typename ktype>
		void MutableRoom::removeCustomProperties(const ktype* const keys, unsigned int count)
		{
			Common::Hashtable hash;
			for(unsigned int i=0; i<count; i++)
				hash.put(keys[i]);
			mergeCustomProperties(hash);
		}
	}
}

#endif