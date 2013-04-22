/* Exit Games Photon - C Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __ENET_CHANNEL_H
#define __ENET_CHANNEL_H

#include "EnetCommand.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class EnetChannel
			{
			public:
				EnetChannel(nByte channelNumber);
				~EnetChannel(void);
				EnetCommand* getReliableCommandFromQueue(int reliableSequenceNumber);
				EnetCommand* getUnreliableCommandFromQueue(int unreliableSequenceNumber);
				bool removeReliableCommandFromQueue(int reliableSequenceNumber);
				bool removeUnreliableCommandFromQueue(int unreliableSequenceNumber);
			private:
				nByte channelNumber;

				Common::JVector<EnetCommand> incomingReliableCommands;
				Common::JVector<EnetCommand> incomingUnreliableCommands;

				int incomingReliableSequenceNumber; // sequencenr of last dispatched command
				int incomingUnreliableSequenceNumber;

				Common::JVector<EnetCommand> outgoingReliableCommands;
				Common::JVector<EnetCommand> outgoingUnreliableCommands;

				int outgoingReliableSequenceNumber;
				int outgoingUnreliableSequenceNumber;

				friend class PeerBase;
				friend class EnetPeer;
			};
		}
	}
}

#endif