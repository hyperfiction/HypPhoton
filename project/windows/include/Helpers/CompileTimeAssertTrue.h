/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __COMPILE_TIME_ASSERT_TRUE_H
#define __COMPILE_TIME_ASSERT_TRUE_H

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<bool> struct CompileTimeAssertTrue;
			template<> struct CompileTimeAssertTrue<true> {};

			/** @file */
		}
	}
}

#undef COMPILE_TIME_ASSERT_TRUE

#define COMPILE_TIME_ASSERT_TRUE(expr) ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED
#define COMPILE_TIME_ASSERT_TRUE_MSG(expr, msg) ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED_##msg
#define COMPILE_TIME_ASSERT2_TRUE(expr) {ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED; (void)ASSERTION_FAILED;}
#define COMPILE_TIME_ASSERT2_TRUE_MSG(expr, msg) {ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED_##msg; (void)ASSERTION_FAILED_##msg;}

#endif