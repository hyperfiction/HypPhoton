/* Exit Games Common - C Client Lib
 * Copyright (C) 2004-2010 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __SERIALIZER_H
#define __SERIALIZER_H

#include "DictionaryBase.h"
#include "UTF8String.h"
#ifdef EG_PLATFORM_SUPPORTS_MOVE_SEMANTICS
#	include "Helpers/Data.h"
#endif

namespace ExitGames
{
	namespace Common
	{
		class Serializer
		{
		public:
			~Serializer();
			Serializer();

			const nByte* getData() const { return mpData; }
			int getDataOffset() const { return mDataOffset; }

			bool push(const Object* serObject, bool setType, bool initEncryption);
			void pushByteArray(nByte* byteArr, short length, bool setType);
			void pushCustom(void* data, nByte customType, bool setType);
			template<typename T> bool push(T* data, bool setType);

#ifdef EG_PLATFORM_SUPPORTS_MOVE_SEMANTICS
			Helpers::Data release();
#endif
		protected:
			void extendInternalBuffer(int size);

			template<typename T> bool write(const T& data);
			bool writeByte(nByte data);
			bool write(const JString& str);
			bool write(const Hashtable& hash);
			bool write(const DictionaryBase& dict, bool setKeyValueTypes);
			bool writeCustom(void* data, nByte customType);
			bool writeObject(const Object* obj, bool setType, bool initEncryption);
			void writeByteArray(const nByte* byteArr, short length);
			bool writeArray(const Object* obj);
			bool writeArrayHelper(const void* pData, nByte type, nByte customType, unsigned int dimensions, short* arraySizes, unsigned int recursionDepth);
			bool writeArrayType(const void* pData, nByte type, nByte customType, short i);

			int getBufferSize() const { return mBufferSize; }

			void writeInvertedData(const void* data, int size);

			template<typename T> unsigned int getTypeSize(const T* = NULL) const { return sizeof(T); }
			unsigned int getTypeSize(const Hashtable* tbl) const;
			unsigned int getTypeSize(const JString* str) const;
			unsigned int getTypeSize(const DictionaryBase* dict) const;

			unsigned int getCustomSize(const void* data, nByte customType) const;
			unsigned int getObjectSize(const Object* serObject, bool setType, bool initEncryption) const;
			unsigned int getByteArraySize(short length) const;
			bool calcArraySize(const void* pData, nByte type, nByte customType, unsigned int dimensions, short* arraySizes, unsigned int recursionDepth, unsigned int& result) const;
		private:
			int mBufferSize;
			int mDataOffset;
			nByte* mpData;
		};

		template<typename T>
		bool Serializer::push(T* data, bool setType)
		{
			extendInternalBuffer(getTypeSize(data) + (setType?getTypeSize<nByte>():0));
			if(setType)
				write(static_cast<const nByte>(Helpers::ConfirmAllowed<T>::typeName));
			return write(*data);
		}

		template<typename T>
		bool Serializer::write(const T& data)
		{
			writeInvertedData(&data, sizeof(T));
			return true;
		}
	}
}

#endif