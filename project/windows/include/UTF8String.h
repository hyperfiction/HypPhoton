/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __UTF8_STRING_H
#define __UTF8_STRING_H

#include "BaseCharString.h"

namespace ExitGames
{
	namespace Common
	{
		/**
		   The UTF8String class is a container class for char* strings, encoded with UTF8.
		   @details
		   This is the UTF8 implementation of BaseCharString.
		   Please look at the doc of the abstract base class for more information.*/
		class UTF8String : public BaseCharString
		{
		public:
			UTF8String(void);
			UTF8String(const UTF8String& str);
			UTF8String(const JString& str);
			UTF8String(const char* str);
			UTF8String(const EG_CHAR* str);
			~UTF8String(void);

			UTF8String& operator=(const UTF8String& Rhs);
			UTF8String& operator=(const JString& Rhs);
			UTF8String& operator=(const char* Rhs);
			UTF8String& operator=(const EG_CHAR* Rhs);

			operator const char* (void) const;
			operator const EG_CHAR* (void) const;
			operator JString (void) const;

			JString JStringRepresentation(void) const;
			unsigned int size(void) const;

			static unsigned int size(const JString& str);
		private:
			unsigned int bytesPerChar(char c) const;
			unsigned int lenForSize(const char* str, unsigned int size) const;
			unsigned int sizeForLen(const char* str, unsigned int len) const;

			class UTF8Converter : public Base
			{
			public:
				static char* Unicode2UTF8(const EG_CHAR* wstr, unsigned int src_len, char* dst, unsigned int dst_size);
				static EG_CHAR* UTF82Unicode(const unsigned char* str, unsigned int src_size, EG_CHAR* dst, unsigned int dst_len);
				static unsigned int SizeOfWStrAsUTF8(const EG_CHAR* str, unsigned int len);
			};
		};
	}
}

#endif