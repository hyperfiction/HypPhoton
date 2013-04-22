/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PHOTON_ERROR_CODE_H
#define __PHOTON_ERROR_CODE_H

namespace ExitGames
{
	namespace Photon
	{
		namespace ErrorCode
		{
			// Photon library error codes
			// can be returned as operationcode in callback, if the returncode indicates an error
			enum ErrorCodes
			{
				SUCCESS       =     0, // No error
				EFAILED       =     1, // General failure
				ENOMEMORY     =     2, // Out of memory
				EBADCLASS     =    10, // NULL class object
				EBADPARM      =    14, // Invalid parameter
				EITEMBUSY     =    32, // Context (system, interface, etc.) is busy

				NET_SUCCESS   =     0, // No network error, successful operation  
				NET_ERROR     =    -1, // Unsuccessful operation
				NET_ENETNONET = 0x216, // Network subsystem unavailable
				NET_MSGSIZE   = 0x21B, // Message too long. A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.
				NET_ENOTCONN  = 0x21C
			};

			/** @file */
		}
	}
}

#endif