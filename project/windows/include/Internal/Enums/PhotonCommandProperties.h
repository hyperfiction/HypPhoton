/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PHOTON_COMMAND_PROPERTIES_H
#define __PHOTON_COMMAND_PROPERTIES_H

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace PhotonCommandProperties
			{
				static const int FLAG_RELIABLE             = 1;
				static const int FLAG_UNSEQUENCED          = 2;

				static const int FV_UNRELIABLE             = 0;
				static const int FV_RELIABLE               = 1;
				static const int FV_UNRELIABLE_UNSEQUENCED = 2;

				static const int CT_NONE           =  0;
				static const int CT_ACK            =  1;
				static const int CT_CONNECT        =  2;
				static const int CT_VERIFYCONNECT  =  3;
				static const int CT_DISCONNECT     =  4;
				static const int CT_PING           =  5;
				static const int CT_SENDRELIABLE   =  6;
				static const int CT_SENDUNRELIABLE =  7;
				static const int CT_SENDFRAGMENT   =  8;
				// bandwidth limit          =  9;
				// throttle config          = 10;
				// unsequenced              = 11;
				static const int CT_EG_SERVERTIME  = 12; //immediately acknowledged (ack sent without any other commands)

				// Commands buffer max length.
				static const int COMMANDS_BUF_LEN = 20;

				static const int PHOTON_COMMAND_HEADER_LENGTH            =                                12;
				static const int PHOTON_COMMAND_UNRELIABLE_HEADER_LENGTH =                                 4;
				static const int PHOTON_COMMAND_HEADER_FRAGMENT_LENGTH   = PHOTON_COMMAND_HEADER_LENGTH + 20;
				static const int MSG_HEADER_BYTES                        =                                 2;
				static const int TCP_HEADER_LENGTH                       =                                 7;
				static const int TCP_PING_LENGTH                         =                                 9;

				static const nByte PHOTON_CODE_CLIENT_KEY     = 1;
				static const nByte PHOTON_CODE_SERVER_KEY     = 1;
				static const nByte PHOTON_KEY_INIT_ENCRYPTION = 0;
			}
		}
	}
}

#endif