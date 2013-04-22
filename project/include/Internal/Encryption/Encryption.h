#ifndef __ENCRYPTION_H
#define __ENCRYPTION_H

#ifdef _EG_UNIX_PLATFORM
#include "arpa/inet.h"
#ifdef _EG_MARMALADE_PLATFORM
#define INADDR_NONE -1 // should be defined by platform's BSD-socket implementation, but for some reason it isn't for Marmalade-platform
#endif
#endif

#include "Common.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			namespace Encryption
			{
				void calculateSHA256Hash(const nByte* inputData, int length, nByte* hashedChars);
				int encrypt(const nByte* plainData, int plainDataSize, const nByte* key, nByte** encodedData, int* encodedDataSize);
				int decrypt(const nByte* encodedData, int encodedDataSize, const nByte* key, nByte** plainData, int* plainDataSize);
			}
		}
	}
}

#endif // __ENCRYPTION_H__