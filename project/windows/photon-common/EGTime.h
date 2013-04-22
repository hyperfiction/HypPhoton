/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __EGTIME_H
#define __EGTIME_H

#include "Base.h"

namespace ExitGames
{
	namespace Common
	{
		class EGTime : public Base
		{
		public:
			EGTime(int time);
			~EGTime(void);

			EGTime(const EGTime& toCopy);
			EGTime& operator=(const EGTime& toCopy);

			EGTime& operator=(const int &time);
			const EGTime& operator+=(const EGTime &time);
			const EGTime& operator-=(const EGTime &time);
			EGTime operator+(const EGTime &time);
			EGTime operator-(const EGTime &time);

			bool operator>(const EGTime &time) const;
			bool operator<(const EGTime &time) const;
			bool operator>=(const EGTime &time) const;
			bool operator<=(const EGTime &time) const;
			bool operator==(const EGTime &time) const;
			bool operator!=(const EGTime &time) const;

			bool overflowed(const EGTime &time) const;
			JString& toString(JString& retStr, bool withTypes=false) const;
		private:
			int t;
		};
	}
}

#endif