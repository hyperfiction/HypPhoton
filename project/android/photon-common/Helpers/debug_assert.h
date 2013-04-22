/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __DEBUG_ASSERT_H
#define __DEBUG_ASSERT_H

#if defined EG_DEBUGGER
	#include <assert.h>
	#define DEBUG_ASSERT(__exp) {assert(__exp);}
#else
	#define DEBUG_ASSERT(__exp) {}
#endif

#endif