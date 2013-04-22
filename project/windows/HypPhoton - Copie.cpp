#include "HypPhoton.h"
#include "limits.h"
#include "LitePeer.h"

typedef void( *FunctionType)( );
extern "C"{
	void onStatus( int status );
}

HypPhoton HypPhoton::m_instance=HypPhoton();

//public -----------------------------------------------------------------------------------------

void HypPhoton::connect( const char *sHost ){
	printf("connect %s\n",sHost );
	mLitePeer->connect(sHost);
}

void HypPhoton::update( ){
	mLitePeer->service();
}

void HypPhoton::join( const char *sName_room ){
	printf("join %s\n",sName_room );
	mLitePeer->opJoin( sName_room );
}

//constructors / destructor  -----------------------------------------------------------------------------------------

HypPhoton::HypPhoton(){
    	printf("constructor\n");
    	mLitePeer = new ExitGames::Lite::LitePeer(*this);
	mLitePeer->setDebugOutputLevel(ExitGames::Common::DebugLevel::INFO);
}

HypPhoton::~HypPhoton(){
    printf("destructor\n");
}

HypPhoton& HypPhoton::Instance(){
    return m_instance;
}

//private -----------------------------------------------------------------------------------------

void HypPhoton::onOperationResponse(const ExitGames::Photon::OperationResponse& operationResponse){
	printf("onOperationResponse%s\n",operationResponse);
}

void HypPhoton::onStatusChanged(int code){
	printf("onStatusChanged\n");
	onStatus( code );
}

void HypPhoton::onEvent(const ExitGames::Photon::EventData& eventData){
	printf("onEvent%s\n",eventData);
}

void HypPhoton::debugReturn(ExitGames::Common::DebugLevel::DebugLevel /*debugLevel*/, const ExitGames::Common::JString& string){
	printf("debugReturn\n");
}

