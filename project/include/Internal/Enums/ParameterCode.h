/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PARAMETER_CODE_H
#define __PARAMETER_CODE_H

#include "PhotonPeer.h"
#include "../../../../Photon-cpp/inc/Enums/ParameterCode.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			namespace ParameterCode
			{
				static const nByte ROOM_NAME              = Lite::ParameterCode::GAMEID;
				static const nByte PLAYERNR               = Lite::ParameterCode::ACTORNR;
				static const nByte TARGET_PLAYERNR        = Lite::ParameterCode::TARGET_ACTORNR;
				static const nByte PLAYER_LIST            = Lite::ParameterCode::ACTOR_LIST;
				static const nByte PROPERTIES             = Lite::ParameterCode::PROPERTIES;
				static const nByte BROADCAST              = Lite::ParameterCode::BROADCAST;
				static const nByte PLAYER_PROPERTIES      = Lite::ParameterCode::ACTOR_PROPERTIES;
				static const nByte ROOM_PROPERTIES        = Lite::ParameterCode::GAME_PROPERTIES;
				static const nByte DATA                   = Lite::ParameterCode::DATA;
				static const nByte CODE                   = Lite::ParameterCode::CODE;
				static const nByte CLEANUP_CACHE_ON_LEAVE = 241;
				static const nByte ADDRESS                = 230;
				static const nByte PEER_COUNT             = 229;
				static const nByte ROOM_COUNT             = 228;
				static const nByte MASTER_PEER_COUNT      = 227;
				static const nByte USER_ID                = 225;
				static const nByte APPLICATION_ID         = 224;
				static const nByte POSITION               = 223;
				static const nByte ROOM_LIST              = 222;
				static const nByte SECRET                 = 221;
				static const nByte APP_VERSION            = 220;
				static const nByte AZURE_NODE_INFO        = 210;
				static const nByte AZURE_LOCAL_NODE_ID    = 209;
				static const nByte AZURE_MASTER_NODE_ID   = 208;
			};
		}
	}
}

#endif