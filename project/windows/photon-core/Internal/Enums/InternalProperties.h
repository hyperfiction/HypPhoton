/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PHOTON_INTERNAL_PROPERTIES_H
#define __PHOTON_INTERNAL_PROPERTIES_H

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace InternalProperties
			{
				static const int IN_BUFF_HEADER_LENGTH = 2;
				static const int INIT_BYTES_HEADER_LENGTH = IN_BUFF_HEADER_LENGTH+7;
				static const int APP_NAME_LENGTH = 32;
				static const int INIT_BYTES_LENGTH = INIT_BYTES_HEADER_LENGTH+APP_NAME_LENGTH;
				static const int EG_OPT_MTU_SIZE = 1200;

				// Lite - Flags for "types of properties", being used as filter in OpGetProperties.
				static const int PROP_NONE = 0x00;
				static const int PROP_GAME = 0x01;
				static const int PROP_ACTOR = 0x02;
				static const int PROP_GAME_AND_ACTOR = PROP_GAME|PROP_ACTOR;

				static const int WARNING_THRESHOLD_QUEUE_OUTGOING_RELIABLE_DEFAULT   = 100;
				static const int WARNING_THRESHOLD_QUEUE_OUTGOING_UNRELIABLE_DEFAULT = 100;
				static const int WARNING_THRESHOLD_QUEUE_OUTGOING_ACKS_DEFAULT       = 100;
				static const int WARNING_THRESHOLD_QUEUE_INCOMING_RELIABLE_DEFAULT   = 100;
				static const int WARNING_THRESHOLD_QUEUE_INCOMING_UNRELIABLE_DEFAULT = 100;
				static const int WARNING_THRESHOLD_QUEUE_SENT_DEFAULT                = 100;

				// To print out the callbacks, requests and other server interaction use EG_DEBUGGER.
				//#define EG_DEBUGGER
			}
		}
	}
}

#endif