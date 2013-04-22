/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __CUSTOM_TYPE_BASE_H
#define __CUSTOM_TYPE_BASE_H

#include "Base.h"
#include "Helpers/CustomTypeCallbackWrapper.h"

class EGCustomTypeCallbackWrapper;

namespace ExitGames
{
	namespace Common
	{
		class CustomTypeBase : public Base
		{
		public:
			using ToString::toString;

			virtual void cleanup(void) = 0;
			virtual bool compare(const CustomTypeBase& other) const = 0;
			virtual void duplicate(CustomTypeBase* const pRetVal) const = 0;
			virtual void deserialize(const nByte* const pData, short length) = 0;
			virtual short serialize(nByte* const pRetVal) const = 0;
		private:
			static void constructClass(nByte typeCode, CB_CALLOC cbCalloc, CB_FREE cbFree, CB_SIZEOF cbSizeOf);
			static void constructClass(nByte typeCode, const Helpers::CustomTypeCallbackWrapper& wrap);
			static void deconstructClass(nByte typeCode);
			CustomTypeBase(void);
			CustomTypeBase(const CustomTypeBase& toCopy);
			~CustomTypeBase();

			static bool checkType(nByte typeCode);
			static void cleanup(void* pData, nByte typeCode);
			static bool compare(void* pData1, void* pData2, nByte typeCode);
			static void duplicate(void* pData, void* retVal, nByte typeCode);
			static void deserialize(nByte* pData, short length, void* retVal, nByte typeCode);
			static short serialize(void* pData, nByte* retVal, nByte typeCode);
			static int toString(void* pData, EG_CHAR* buffer, nByte typeCode);
			static unsigned int getSizeof(nByte typeCode);
			static void freeObject(const void* pData, nByte typeCode);
			static CustomTypeBase* allocObject(unsigned int count, nByte typeCode);

			template<nByte typeCode> friend class CustomType;
			friend class Object;
			friend class DeSerializer;
			friend class Serializer;
			friend class EGCustomTypeCallbackWrapper;
		};
	}
}

#endif