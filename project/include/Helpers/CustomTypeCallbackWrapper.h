/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __CUSTOM_TYPE_CALLBACK_WRAPPER_BASE_H
#define __CUSTOM_TYPE_CALLBACK_WRAPPER_BASE_H

#include "defines.h"

typedef void* (*CB_CALLOC)(short count, nByte customTypeCode);
typedef void (*CB_FREE)(const void* pData, nByte customTypeCode);
typedef unsigned int (*CB_SIZEOF)(nByte customTypeCode);

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class CustomTypeCallbackWrapper
			{
			public:
				CustomTypeCallbackWrapper();
				CustomTypeCallbackWrapper(CB_CALLOC cbCalloc, CB_FREE cbFree, CB_SIZEOF cbSizeOf);

				virtual void cleanup(void* pData);
				virtual bool compare(void* pData1, void* pData2);
				virtual void duplicate(void* pData, void* retVal);
				virtual void deserialize(nByte* pData, short length, void* retVal);
				virtual short serialize(void* pData, nByte* retVal);
				virtual int toString(void* pData, EG_CHAR* buffer);
				virtual CustomTypeCallbackWrapper* copy() const;
				void* alloc(short count, nByte customTypeCode);
				void (free)(const void* pData, nByte customTypeCode);
				unsigned int getSizeof(nByte customTypeCode);
				void reset();

			protected:
				CB_CALLOC mcbCalloc;
				CB_FREE mcbFree;
				CB_SIZEOF mcbSizeOf;
			};
		}
	}
}

#endif