/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __IS_DERIVED_FROM_H
#define __IS_DERIVED_FROM_H

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Derived, typename Base>
			class IsDerivedFrom
			{
			private:
				class No
				{
				};

				class Yes
				{
					No no[3];
				};

				static Yes Test(Base*); // not defined
				static No Test(...); // not defined

				static void Constraints(Derived* p)
				{
					Base* pb = p;
					pb = p;
				}

			public:
				enum
				{
					Is = sizeof(Test(static_cast<Derived*>(0))) == sizeof(Yes)
				};

				IsDerivedFrom()
				{
					void(*p)(Derived*) = Constraints;
				}
			};

			/** @file */
		}
	}
}

#endif