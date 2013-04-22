/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __EVENT_CODE_H
#define __EVENT_CODE_H

#include "PhotonPeer.h"
#include "../../../../Photon-cpp/inc/Enums/EventCode.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			namespace EventCode
			{
				static const nByte JOIN               = Lite::EventCode::JOIN;
				static const nByte LEAVE              = Lite::EventCode::LEAVE;
				static const nByte PROPERTIES_CHANGED = Lite::EventCode::PROPERTIES_CHANGED;
				static const nByte ROOM_LIST          = 230;
				static const nByte ROOM_LIST_UPDATE   = 229;
				static const nByte QUEUE_STATE        = 228;
				static const nByte APP_STATS          = 226;
				static const nByte AZURE_NODE_INFO    = 210;
			};
		}
	}
}

#endif