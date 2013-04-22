/* Exit Games Photon - C Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __ENET_PEER_H
#define __ENET_PEER_H

#include "PeerBase.h"
#include "EnetChannel.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class EnetPeer: public PeerBase
			{
			public:
				EnetPeer(PhotonListener& listener, const Common::Logger& logger);
				~EnetPeer(void);
			private:
				typedef PeerBase super;

				void cleanupNonHierarchical(void);
				void cleanup(void);
				void reset(void);
				bool connect(const EG_CHAR* ipAddr, const nByte appID[32]);
				bool startConnection(const char* ipAddr);
				void disconnect(void);
				void stopConnection(void);
				void sendOutgoingCommands(void);
				void copyCommandToBuffer(nByte* pDst, const nByte* pSrc, int& size);
				bool dispatchIncomingCommands(void);
				void fetchServerTimestamp(void);
				void onConnectCallback(int nError);
				void onReceiveDataCallback(nByte* pBuf, int iCount, int nError);

				int getIncomingReliableCommandsCount(void);
				int getQueuedIncomingCommands(void);
				int getQueuedOutgoingCommands(void);

				void send(nByte cType, nByte* payload, unsigned int payloadSize, nByte channelId);
				bool sendInFragments(nByte* payload, unsigned int payloadSize, nByte channelId);
				void queueOutgoingReliableCommand(EnetCommand& command);
				void queueOutgoingUnreliableCommand(EnetCommand& command);
				void queueOutgoingAcknowledgement(const EnetCommand& command);
				bool queueIncomingCommand(const EnetCommand& command);
				void queueSentReliableCommand(const EnetCommand& command);
				int serializeToBuffer(ExitGames::Common::JVector<EnetCommand>& ev);
				void execute(const EnetCommand& command);
				bool removeSentReliableCommand(int ackReceivedReliableSequenceNumber,  int ackReceivedChannel, EnetCommand& pCommand);
				void sortLastElementInQueue(ExitGames::Common::JVector<EnetCommand>& argQueue, bool sortByReliableSequenceNumber);
				void clearAllQueues(void);

				ExitGames::Common::JVector<EnetCommand> outgoingAcknowledgements;
				ExitGames::Common::JVector<EnetCommand> sentReliableCommands;
				EnetChannel** channels;						
				int windowSize;  
				int* unsequencedWindow;
				int outgoingUnsequencedGroupNumber;
				int incomingUnsequencedGroupNumber;
				nByte commandCount;
				nByte* buffer;
				int bufferIndex;
				int commandSize;

				friend void EnetCommand::init(EnetPeer* const  pEnetPeer, nByte cType, const nByte* const payload, int payloadLen);
			};
		}
	}
}

#endif