/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __OBJECT_H
#define __OBJECT_H

#include "Base.h"

class EGUtilsHelper;

namespace ExitGames
{
	namespace Common
	{
		/**
		   Container class designed to hold all types of objects that are supported by the library.
		   @details
		   Object is the common base for the template classes KeyObject
		   and ValueObject, that provide a more convenient
		   interface for handling Objects.
	   
		   @remarks
		   We do recommend to use KeyObject and ValueObject instead whenever possible,
		   as they provide a more type-safe and more convenient interface for
		   dealing with Objects. However in situations where an array or a container class
		   holding multiple Objects of different types is absolutely needed, using the Object
		   interface can be the only option.
		   @sa
		   KeyObject, ValueObject */
		class Object : public Base
		{
		public:
			using ToString::toString;

			Object(void);
			virtual ~Object(void);

			Object(const Object& toCopy);
			virtual Object& operator=(const Object& toCopy);

			bool operator==(const Object& toCompare) const;
			bool operator!=(const Object& toCompare) const;

			nByte getType(void) const;
			nByte getCustomType(void) const;
			const short* getSizes(void) const;
			unsigned int getDimensions(void) const;
			JString& toString(JString& retStr, bool withTypes=false) const;
		protected:
			Object(void* data, nByte type, nByte customType, bool makeCopy);
			Object(void* data, nByte type, nByte customType, short size, bool makeCopy);
			Object(void* data, nByte type, nByte customType, unsigned int dimensions, const short* const sizes, bool makeCopy);

			const void* getData(void) const;
			const void* const* getDataPointer(void) const;
			virtual Object& assign(const Object& toCopy);
		private:
			union Data
			{
				nByte byteData;
				short shortData;
				int intData;
				int64 int64Data;
				float floatData;
				double doubleData;
				bool boolData;
			};

			void setSizes(const short* const sizes, unsigned int dimensions=1);
			void setDimensions(unsigned int dimensions);
			void setData(const void* data);
			void setDataNoCopy(void* data);
			void setType(nByte type);
			void setCustomType(nByte customType);
			void set(const void* data, nByte type, nByte customType, bool makeCopy);
			void set(const void* data, nByte type, nByte customType, short size, bool makeCopy);
			void set(const void* data, nByte type, nByte customType, unsigned int dimensions, const short* sizes, bool makeCopy);
			void setWithoutCleanup(const void* data, nByte type, nByte customType, bool makeCopy);
			void setWithoutCleanup(const void* data, nByte type, nByte customType, short size, bool makeCopy);
			void setWithoutCleanup(const void* data, nByte type, nByte customType, unsigned int dimensions, const short* sizes, bool makeCopy);
			void cleanup(const void* pData=0, unsigned int recursionDepth=0);
			void copyArray(const void* pDataIn, void** pDataOut, unsigned int recursionDepth=0) const;
			bool equalsArray(const void* pData1, const void* pData2, unsigned int recursionDepth=0) const;
			static JString& toStringHelper(const Object& object, JString& retStr, bool withTypes=false, unsigned int recursionDepth=0);
			JString payloadTypeToString(void) const;
			bool compareHelper(const void* pData1, const void* pData2, nByte type, nByte customType, unsigned int dimensions, const short* arraySizes, unsigned int recursionDepth) const;
			static Data constructDataInstance(nByte payload);
			static Data constructDataInstance(short payload);
			static Data constructDataInstance(int payload);
			static Data constructDataInstance(int64 payload);
			static Data constructDataInstance(float payload);
			static Data constructDataInstance(double payload);
			static Data constructDataInstance(bool payload);

			Data mData;
			void* mpData;
			short mSize;
			short* mpSizes;
			nByte mType;
			nByte mCustomType;
			unsigned int mDimensions;

			friend class Hashtable;
			friend class Serializer;
			friend class DeSerializer;
			friend class EGUtilsHelper;
		};
	}
}

#endif