/* Exit Games Common - C Client Lib
 * Copyright (C) 2004-2010 by Exit Games. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __DESERIALIZER_H
#define __DESERIALIZER_H

#include "Hashtable.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class PeerBase;
		}
	}

	namespace Common
	{
		class DeSerializer
		{
		public:
			DeSerializer(const nByte* data);

			bool pop(Object& object);
			bool popType(nByte param, Object& object);
			void popByte(Object& object);
			void popByteArray(Object& object);
			void popShort(Object& object);
			void popInteger(Object& object);
			void popLong(Object& object);
			void popFloat(Object& object);
			void popDouble(Object& object);
			void popBoolean(Object& object);
			void popString(Object& object);
			void popHashTable(Object& object);
			void popDictionary(Object& dict);
			void popCustom(Object& object, nByte customType);
		protected:
			void popStringHelper(JString& str);
			void popHashTableHelper(Hashtable& hash);
			void popArrayOfDictionaries(Object& dict, short arraySize, int dimensions = 0);
			const DictionaryBase* popDictionaryHelper(nByte* pKeyTypes, nByte* pValueTypes, unsigned int* pDimensionsOfNestedValues);
			void popCustomHelper(Object& object, nByte customType, short arraySize);
			void popArray(Object& array); 
			void popObjectArray(Object& array);

			int getReadPosition() const { return mDataOffset; }

			nByte readByte();
			short readShort();
			int readInt();
			int64 readLong();
			float readFloat();
			double readDouble();
			bool readBoolean();
			void readDictionaryTypes(nByte** ppKeyTypes, nByte** ppValTypes, unsigned int** ppDimensionsOfNestedValues);
		private:
			int mDataOffset;
			nByte* mpData;

			friend class Photon::Internal::PeerBase;
		};
	}
}

#endif