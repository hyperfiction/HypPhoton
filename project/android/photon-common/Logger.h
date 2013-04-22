/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __LOGGER_H
#define __LOGGER_H

#include "BaseListener.h"

namespace ExitGames
{
	namespace Common
	{
		class Logger
		{
		public:
			Logger(void);
			void log(DebugLevel::DebugLevel debugLevel, const EG_CHAR* const file, const EG_CHAR* const function, bool  printBrackets, unsigned int line, const EG_CHAR* const dbgMsg, ...) const;
			void log(DebugLevel::DebugLevel debugLevel, const EG_CHAR* const file, const EG_CHAR* const function, bool  printBrackets, unsigned int line, const EG_CHAR* dbgMsg, va_list args) const;
			DebugLevel::DebugLevel getDebugOutputLevel(void) const;
			bool setDebugOutputLevel(DebugLevel::DebugLevel debugLevel);
			void setListener(const BaseListener& listener);
		private:
			DebugLevel::DebugLevel mDebugLevel;
			BaseListener* mpListener;
		};
	}
}

// public debugging API
#ifdef EG_DEBUGGER
#	ifdef __OBJC__
#		define EGLOG(debugLevel, ...) mLogger.log(debugLevel, __WFILE__, __WFUNCTION__, false, __LINE__, __VA_ARGS__)
#	else
#		define EGLOG(debugLevel, ...) mLogger.log(debugLevel, __WFILE__, __WFUNCTION__, true, __LINE__, __VA_ARGS__)
#	endif
#else
#	define EGLOG(debugLevel, ...) ((void)0)
#endif

#endif