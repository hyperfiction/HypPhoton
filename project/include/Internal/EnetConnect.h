/* Exit Games Photon - C Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __ENET_CONNECT_H
#define __ENET_CONNECT_H

#include "EnetPeer.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class EnetConnect : public PhotonConnect
			{
			public:
				EnetConnect(EnetPeer* pPeer);
				~EnetConnect(void);
			private:
				typedef PhotonConnect super;

				int socket(void);
				unsigned short getDefaultPort(void);
				bool checkConnection(void);
				int recvBuffer(nByte** ppBuff, int* pBytesRead);
			};
		}
	}
}

#endif