/* Exit Games Photon - C++ Client Lib
* Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
* http://www.exitgames.com
* mailto:developer@exitgames.com
*/

#ifndef __OPERATION_RESPONSE_H
#define __OPERATION_RESPONSE_H

#include "Common.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class PeerBase;
		}

		class OperationResponse
		{
		public:
			~OperationResponse(void);

			OperationResponse(const OperationResponse& toCopy);
			OperationResponse& operator=(const OperationResponse& toCopy);

			const Common::Object& operator[](unsigned int index) const;

			Common::JString toString(bool withDebugMessage=false, bool withParameters=false, bool withParameterTypes=false) const;
			Common::Object getParameterForCode(nByte parameterCode) const;

			nByte getOperationCode(void) const;
			short getReturnCode(void) const;
			const Common::JString& getDebugMessage(void) const;
			const Common::Hashtable& getParameters(void) const;

		private:
			friend class Internal::PeerBase;

			OperationResponse(nByte operationCode, short returnCode);
			void setDebugMessage(const EG_CHAR* msg);
			void addParameter(nByte parameterCode, const Common::Object& par);

			nByte mOperationCode;
			short mReturnCode;
			Common::JString mDebugMessage;
			Common::Hashtable mParameters;
		};
	}
}

#endif