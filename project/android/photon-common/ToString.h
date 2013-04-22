/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __TO_STRING_H
#define __TO_STRING_H

namespace ExitGames
{
	namespace Common
	{
		class JString;

		/**
		 This class provides an interface for printing the payload of an instance of any
		 subclass to a string.
		 @details
		 Every subclass of this class will provide an implementation for toString() in its
		 public interface and will therefor be printable. The implementations for containerclasses
		 will include the output-strings of their elements into their own output string.
		 */
		class ToString
		{
		public:
			virtual ~ToString(void);
			virtual JString typeToString(void) const;
			virtual JString& toString(JString& retStr, bool withTypes=false) const = 0;
			JString toString(bool withTypes=false) const;
		protected:
			static const JString EG_STR_CHAR;
			static const JString EG_STR_SCHAR;
			static const JString EG_STR_UCHAR;
			static const JString EG_STR_SHORT;
			static const JString EG_STR_USHORT;
			static const JString EG_STR_INT;
			static const JString EG_STR_UINT;
			static const JString EG_STR_LONG;
			static const JString EG_STR_ULONG;
			static const JString EG_STR_LONGLONG;
			static const JString EG_STR_ULONGLONG;
			static const JString EG_STR_FLOAT;
			static const JString EG_STR_DOUBLE;
			static const JString EG_STR_LONGDOUBLE;
			static const JString EG_STR_BOOL;
		};
	}
}

#endif