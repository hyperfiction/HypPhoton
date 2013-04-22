/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PHOTON_PEER_H
#define __PHOTON_PEER_H

#include "Internal/PeerBase.h"
#include "Enums/ErrorCode.h"
#include "Enums/NetworkPort.h"
#include "Enums/StatusCode.h"

namespace ExitGames
{
	namespace Photon
	{
		class PhotonPeer
		{
		public:
			PhotonPeer(PhotonListener& listener, bool useTcp=false);
			virtual ~PhotonPeer(void);

			virtual bool connect(const Common::JString& ipAddr, const nByte appID[Internal::InternalProperties::APP_NAME_LENGTH]=NULL);
			virtual void disconnect(void);
			virtual void service(bool dispatchIncomingCommands=true);
			virtual void serviceBasic(void);
			virtual bool opCustom(const OperationRequest& operationRequest, bool sendReliable, nByte channelID=0, bool encrypt=false);
			virtual void sendOutgoingCommands(void);
			virtual bool dispatchIncomingCommands(void);
			virtual bool establishEncryption(void);
			virtual void fetchServerTimestamp(void);

			const PhotonListener* getListener(void) const;
			int getServerTimeOffset(void) const;
			int getServerTime(void) const;
			int getBytesOut(void) const;
			int getBytesIn(void) const;
			PeerState::PeerState getPeerState(void) const;
			int getSentCountAllowance(void) const;
			void setSentCountAllowance(int setSentCountAllowance);
			int getTimePingInterval(void) const;
			void setTimePingInterval(int setTimePingInterval);
			int getRoundTripTime(void) const;
			int getRoundTripTimeVariance(void) const;
			Common::DebugLevel::DebugLevel getDebugOutputLevel(void) const;
			bool setDebugOutputLevel(Common::DebugLevel::DebugLevel debugLevel);
			int getIncomingReliableCommandsCount(void) const;
			short getPeerId(void) const;
			int getSentTimeAllowance(void) const;
			void setSentTimeAllowance(int setSentTimeAllowance);
			int getQueuedIncomingCommands(void) const;
			int getQueuedOutgoingCommands(void) const;
			Common::JString getServerAddress(void) const;
			bool getIsEncryptionAvailable(void) const;
			static short getPeerCount(void);

		protected:
			Internal::PeerBase* mpPhotonPeer;
			Common::Logger mLogger;
		};
	}
}

#endif