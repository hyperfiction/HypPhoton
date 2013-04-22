/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __BASE_CHAR_STRING_H
#define __BASE_CHAR_STRING_H

#include "Base.h"

namespace ExitGames
{
	namespace Common
	{
		class JString;

		class BaseCharString : public Base
		{
		public:
			BaseCharString();
			virtual ~BaseCharString(void);
			virtual operator const char* (void) const = 0;
			virtual operator const EG_CHAR* (void) const = 0;
			virtual operator JString (void) const = 0;

			const char* cstr(void) const;
			virtual JString JStringRepresentation(void) const = 0;
			unsigned int length(void) const;
			virtual unsigned int size(void) const = 0;
			JString& toString(JString& retStr, bool withTypes=false) const;
		protected:
			char* mBuffer;
			unsigned int mLength;
		};
	}
}

#endif