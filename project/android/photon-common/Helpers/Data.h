/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __DATA_H
#define __DATA_H

#include "Base.h"

#ifdef EG_PLATFORM_SUPPORTS_MOVE_SEMANTICS

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class Data
			{
			public:
				Data(unsigned char* buffer, int size);
				~Data(void);

				Data(Data&& rhs);
				void operator=(Data&& rhs);

				int getSize() const;
				nByte* getBuffer() const;
			private:
				Data(const Data& rhs);
				void operator = (const Data& rhs);

				void clear(void);
				void reset(void);

				int mSize;
				nByte* mpBuffer;
			};
		}
	}
}

#endif

#endif