/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PHOTON_MESSAGE_TYPE_H
#define __PHOTON_MESSAGE_TYPE_H

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace MessageType
			{
				static const int INIT       = 0; // not used at the moment
				static const int INIT_RES   = 1;
				static const int OP         = 2; // operation request
				static const int OP_RES     = 3; // operation response
				static const int EV         = 4; // an event is coming in
				static const int INT_OP     = 6; // internal operation request (used for init encryption)
				static const int INT_OP_RES = 7; // internal operation response (used for init encryption)
			}
		}
	}
}

#endif