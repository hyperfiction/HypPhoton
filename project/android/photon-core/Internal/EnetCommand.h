/* Exit Games Photon - C Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __ENET_COMMAND_H
#define __ENET_COMMAND_H

#include "Common.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class EnetPeer;

			class EnetCommand
			{
			public:
				EnetCommand(EnetPeer* const pEnetPeer, nByte cType, const nByte* const payload, int payloadSize);
				EnetCommand(EnetPeer* const pEnetPeer, nByte* pBuffer, unsigned int bufferSize, int* nRead, int sentTime);
				~EnetCommand(void);

				EnetCommand(const EnetCommand& toCopy);
				EnetCommand& operator=(const EnetCommand& toCopy);

				Common::JString toString(bool withTypes) const;

				void init(void);
				void init(EnetPeer* const pEnetPeer, nByte cType, const nByte* const payload, int payloadLen);

				EnetCommand createAck(void);
				void serialize(nByte** buf, int* size);
			//private:
				EnetCommand(void);
				EnetCommand(EnetPeer* const pEnetPeer, nByte cType, const nByte* const payload, int payloadSize, nByte commandChannelID);

				EnetPeer* mpEnetPeer;

				nByte mCommandFlags;
				nByte mCommandType;

				//variables from CommandHeader
				nByte mCommandChannelID;

				//variables for fragments (not used otherwise)
				int mStartSequenceNumber;
				int mFragmentCount;
				int mFragmentNumber;
				int mTotalLength;
				int mFragmentOffset;
				int mFragmentsRemaining;

				int mReliableSequenceNumber;
				int mUnreliableSequenceNumber;
				int mUnsequencedGroupNumber;
				nByte mReservedByte;

				nByte* mCommandPayload; // replaces "Packet"
				int mCommandPayloadLen;
				int mCommandSentTime; //last time the command was sent
				int mCommandOriginalSentTime; //first time the command was sent
				nByte mCommandSentCount; //counts the number of retries (before calling it a loss)
				int mAckReceivedReliableSequenceNumber; //for ACK commands
				int mAckReceivedSentTime; //for ACK commands
				int mRoundTripTimeout; // milliseconds until the command is resent
			};
		}
	}
}

#endif