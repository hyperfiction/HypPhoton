/* Exit Games Photon - C Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PEER_BASE_H
#define __PEER_BASE_H

#include "porting.h"
#include "EnetCommand.h"
#include "PhotonConnect.h"
#include "OperationRequest.h"
#include "PhotonListener.h"
#include "Enums/PeerState.h"
#include "Enums/ConnectionState.h"
#include "Internal/Enums/InternalProperties.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class PeerBase
			{
			public:
				PeerBase(PhotonListener& listener, const Common::Logger& logger);
				virtual ~PeerBase(void);

				virtual bool connect(const EG_CHAR* ipAddr, const nByte appID[32]) = 0;
				virtual bool startConnection(const char* ipAddr) = 0;
				virtual void disconnect(void) = 0;
				virtual void stopConnection(void) = 0;
				virtual void service(bool dispatch);
				virtual void serviceBasic(void);
				virtual void sendOutgoingCommands(void) = 0;
				virtual bool dispatchIncomingCommands(void) = 0;
				virtual bool opCustom(const OperationRequest* operationRequest, bool sendReliable, nByte channelId, bool encrypt, nByte msgType);
				virtual void fetchServerTimestamp(void) = 0;
				virtual bool establishEncryption(void);

				virtual int getServerTimeOffset(void);
				virtual int getServerTime(void);
				virtual int getBytesOut(void);
				virtual int getBytesIn(void);
				virtual PeerState::PeerState getPeerState(void);
				virtual int getSentCountAllowance(void);
				virtual void setSentCountAllowance(int setSentCountAllowance);
				virtual int getTimePingInterval(void);
				virtual void setTimePingInterval(int setTimePingInterval);
				virtual int getRoundTripTime(void);
				virtual int getRoundTripTimeVariance(void);
				virtual int getIncomingReliableCommandsCount(void) = 0;
				virtual short getPeerID(void);
				virtual int getSentTimeAllowance(void);
				virtual void setSentTimeAllowance(int sentTimetAllowance);
				virtual int getQueuedIncomingCommands(void) = 0;
				virtual int getQueuedOutgoingCommands(void) = 0;
				virtual const char* getServerAdress(void);
				virtual bool getIsEncryptionAvailable(void);
				static unsigned short getPeerCount(void);

				virtual void onConnectCallback(int nError) = 0;
				virtual void onReceiveDataCallback(nByte* pBuf, int iCount, int nError) = 0;
				virtual void onSendCommands(int nError);
				
				const PhotonListener* getListener(void) const;
			protected:
				virtual void cleanup(void);
				virtual void reset(void);
				virtual void onDisconnected(void);
				virtual void send(nByte cType, nByte* payload, unsigned int payloadSize, nByte channelId) = 0;
				virtual bool serializeOperation(const OperationRequest* pOperationRequest, nByte** buffer,  int* buffSize, bool encrypt, nByte msgType);
				virtual bool deserializeOperation(nByte* inBuff, int inBuffLength);
				virtual void deserializeOperationResponse(nByte* inBuff, bool isEncrypted, int waitForBytes, nByte msgType);
				virtual void deserializeEvent(nByte* inBuff, bool isEncrypted, int waitForBytes);
				virtual void updateRoundTripTimeAndVariance(int time);
				virtual void clearAllQueues(void) = 0;
				virtual bool opExchangeKeysForEncryption(void);
				virtual void deriveSharedKey(const OperationResponse* operationResponse);
				virtual void initCallback(void);

				static unsigned short peerCount;

				short peerID;
				int challenge;
				Common::ANSIString peerIpAddr;
				ConnectionState::ConnectionState connectionState;
				nByte channelCountUserChannels; // this is the number of user-channels. There is an additional exclusive channel for system messages.
				nByte initBytes[InternalProperties::INIT_BYTES_LENGTH];
				PhotonConnect* rt;
				int timeBase;
				int timeInt;
				int timeoutInt;
				int sentTimeAllowance;
				int timeLastReceive;
				int sentCountAllowance;
				int timePingInterval;
				int packetsLost;
				int packetLoss;
				int packetsSent;
				int packetLossEpoch;
				int packetLossVariance;
				int packetThrottleEpoch;
				int serverTimeOffset;
				bool serverTimeOffsetIsAvailable;
				int serverSentTime;
				int roundTripTime;
				int roundTripTimeVariance;
				int lastRoundTripTime;
				int lowestRoundTripTime;
				int lastRoundTripTimeVariance;
				int highestRoundTripTimeVariance;
				int packetThrottleInterval;
				bool isSendingCommand; //Indicates if sending command is in progress
				nByte* secretKey; // Client private key
				nByte* sharedKeyHash; // Shared key hash, used as key for encrypting messages
				int secretKeySize; // Client private key size
				int  publicKeySize; // Client public key size
				bool isEncryptionAvailable;
				unsigned short warningTresholdQueueOutgoingReliable;
				unsigned short warningTresholdQueueOutgoingUnreliable;
				unsigned short warningTresholdQueueOutgoingAcks;
				unsigned short warningTresholdQueueIncomingReliable;
				unsigned short warningTresholdQueueIncomingUnreliable;
				unsigned short warningTresholdQueueSent;
				bool applicationIsInitialized;
				bool shouldScheduleDisconnectCB;
				bool debugUseShortcut;
			#if defined _EG_MARMALADE_PLATFORM && !defined I3D_ARCH_ARM && defined EG_DEBUGGER
				bool firedMetricsWarning;
			#endif
				PhotonListener& mListener;
				const Common::Logger& mLogger;
			private:
				void cleanupNonHierarchical(void);

				friend EnetCommand::EnetCommand(EnetPeer* const pEnetPeer, nByte* pBuffer, unsigned int bufferSize, int* nRead, int sentTime);
				friend void EnetCommand::init(EnetPeer* const  pEnetPeer, nByte cType, const nByte* const payload, int payloadLen);
				friend void PhotonConnect::service(void);
				friend int PhotonConnect::sendPackage(const nByte* src, int count);
			};
		}
	}
}

#endif