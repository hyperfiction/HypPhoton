/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LOAD_BALANCING_PLAYER_H
#define __LOAD_BALANCING_PLAYER_H

#include "LoadBalancingPeer.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class MutableRoom;

		class Player : public Common::Base
		{
		public:
			using Common::ToString::toString;

			virtual ~Player(void);

			Player(const Player& toCopy);
			virtual Player& operator=(const Player& toCopy);

			int getNumber(void) const;
			const Common::JString& getName() const;
			const Common::Hashtable& getCustomProperties() const;

			bool operator==(const Player& player) const;
			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
			virtual Common::JString toString(bool withTypes, bool withCustomProperties) const;
		protected:
			Player(void);
			Player(int number, const Common::Hashtable& properties, const MutableRoom* const room);

			virtual Player& assign(const Player& toCopy);
			virtual void cacheProperties(const Common::Hashtable& properties);
			virtual Common::JString payloadToString(bool withTypes, bool withCustomProperties=false) const;

			int mNumber;
			Common::JString mName;
			Common::Hashtable mCustomProperties;
			const MutableRoom* mRoom;
		private:
			friend class MutableRoom;
		};



		class MutablePlayer : public Player
		{
		public:
			virtual ~MutablePlayer(void);

			MutablePlayer(const MutablePlayer& toCopy);
			virtual MutablePlayer& operator=(const Player& toCopy);

			void setName(const Common::JString& name);
			bool getIsMasterClient(void) const;

			void mergeCustomProperties(const Common::Hashtable& customProperties);
			template<typename ktype, typename vtype> void addCustomProperty(const ktype& key, const vtype& value);
			void addCustomProperties(const Common::Hashtable& customProperties);
			template<typename ktype> void removeCustomProperty(const ktype& key);
			template<typename ktype> void removeCustomProperties(const ktype* const keys, unsigned int count);
		protected:
			MutablePlayer(int number, const Common::Hashtable& properties, const MutableRoom* const room, Peer* peer);

			virtual MutablePlayer& assign(const Player& toCopy);
		private:
			typedef Player super;

			Peer* mLoadBalancingPeer;

			friend class MutableRoom;
			friend class Client;
		};

		template<typename ktype, typename vtype> void MutablePlayer::addCustomProperty(const ktype& key, const vtype& value)
		{
			Common::Hashtable hash;
			hash.put(key, value);
			addCustomProperties(hash);
		}

		template<typename ktype> void MutablePlayer::removeCustomProperty(const ktype& key)
		{
			removeCustomProperties(&key, 1);
		}

		template<typename ktype> void MutablePlayer::removeCustomProperties(const ktype* const keys, unsigned int count)
		{
			Common::Hashtable hash;
			for(unsigned int i=0; i<count; i++)
				hash.put(keys[i]);
			mergeCustomProperties(hash);
		}
	}
}

#endif