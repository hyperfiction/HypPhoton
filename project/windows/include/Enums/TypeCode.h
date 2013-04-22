/* Exit Games Photon Common - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __COMMON_TYPE_CODE_H
#define __COMMON_TYPE_CODE_H

namespace ExitGames
{
	namespace Common
	{
		namespace TypeCode
		{
			static const nByte BYTE               = 'b';
			static const nByte SHORT              = 'k';
			static const nByte INTEGER            = 'i';
			static const nByte LONG               = 'l';
			static const nByte FLOAT              = 'f';
			static const nByte DOUBLE             = 'd';
			static const nByte BOOLEAN            = 'o';
			static const nByte STRING             = 's';
			static const nByte HASHTABLE          = 'h';
			static const nByte DICTIONARY         = 'D';
			static const nByte OBJECT             = 'z'; // for EG_Object (C) / Object (C++) / NSObject (objC), only allowed for arrays!
			static const nByte ARRAY              = 'y'; // internal only
			static const nByte INTERNAL_BYTEARRAY = 'x'; // internal only
			static const nByte GPOPERATION        = 'g'; // This is internally used for gp operations.
			static const nByte PHOTON_COMMAND     = 'p'; // This is internally used for photon commands.
			static const nByte EG_NULL            = '*'; // internal only, for adding NULL as a value to a HashTable
			static const nByte CUSTOM             = 'c'; // internal only, for custom data, (de-)serialized by callbacks, implemented by the application
			static const nByte UNKNOWN            = 0  ; // internal only, used instead of EG_OBJECT for values inside an EG_DICTIONARY
		}

		/** @file */
	}
}

#endif