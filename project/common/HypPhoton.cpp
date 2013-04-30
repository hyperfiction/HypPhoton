#include "HypPhoton.h"
#include "LoadBalancingClient.h"
#include "LoadBalancingPlayer.h"
//#include "LitePeer.h"

const unsigned char MESSAGE = 0;

#if defined _EG_MARMALADE_PLATFORM
#	if defined I3D_ARCH_X86
#		if(defined _MSC_VER && !defined __clang__ && !defined __gcc__)
#			define PLAYER_NAME L"Marmalade X86 Windows"
#		else
#			define PLAYER_NAME L"Marmalade X86 OS X"
#		endif
#	elif defined I3D_ARCH_ARM
#		define PLAYER_NAME L"Marmalade ARM"
#	else
#		define PLAYER_NAME  L"unknown Marmalade platform"
#	endif
#elif defined _EG_WINDOWS_PLATFORM
#	define PLAYER_NAME L"Win32"
#elif defined _EG_IPHONE_PLATFORM
#	define PLAYER_NAME L"iOS"
#elif defined _EG_IMAC_PLATFORM
#	define PLAYER_NAME L"OS X"
#elif defined _EG_ANDROID_PLATFORM
#	define PLAYER_NAME L"Android"
#elif defined _EG_BLACKBERRY_PLATFORM
#	define PLAYER_NAME L"Blackberry"
#elif defined _EG_PS3_PLATFORM
#	define PLAYER_NAME L"PS3"
#elif defined _EG_LINUX_PLATFORM
#	define PLAYER_NAME L"Linux"
#else
#	define PLAYER_NAME L"unknown platform"
#endif

#ifdef ANDROID
#include <android/log.h>
#define printf(fmt,args...)  __android_log_print(ANDROID_LOG_INFO ,"trace", fmt, ##args)
#endif

#if defined _EG_WIN32_PLATFORM
#	define SLEEP(ms) Sleep(ms)
#else
#	define SLEEP(ms) usleep(ms*1000)
#endif

using namespace std;

typedef void( *FunctionType)( );
extern "C"{
	void onStatus( int status );
	void onEvent( const char *sName , const char *sValue );
}

HypPhoton HypPhoton::m_instance=HypPhoton();

//public -----------------------------------------------------------------------------------------

void HypPhoton::connect( const char *sHost ){
	printf("HypPhoton::connect %s\n",sHost );
	mLoadBalancingClient.connect( sHost );
}

void HypPhoton::disconnect( ){
	printf("HypPhoton::disconnect\n");
	mLoadBalancingClient.disconnect( );
}

void HypPhoton::setUser_name( const char *sUser_name ){
	mLoadBalancingClient.getCurrentlyJoinedRoom( ).getLocalPlayer( ).setName( sUser_name );
}

void HypPhoton::start( ){
	printf("start\n");
}

void HypPhoton::update( ){
	//printf("update\n");
	mLoadBalancingClient.service();
}

void HypPhoton::addRoom_prop( const char *key , const char *val ){
	printf("addRoom_prop");
	ExitGames::Common::Hashtable 	data;
	printf("data %s\n",data );
							//data = mLoadBalancingClient.getCurrentlyJoinedRoom( ).getCustomProperties( );
							//data.put<ExitGames::Common::JString,ExitGames::Common::JString>( key , val );
}

const char* HypPhoton::getRoom_prop( const char *key ){
	return (const char *)mLoadBalancingClient.getCurrentlyJoinedRoom( ).getCustomProperties( ).getValue( key );
}

void HypPhoton::joinLobby( ){
	mLoadBalancingClient.opJoinLobby( );
}

void HypPhoton::joinRandom_room( int maxPlayers ){
	printf("joinRandom_room %i\n",maxPlayers );

	ExitGames::Common::Hashtable 	roomProperties;
    							//roomProperties.put("map", "aap");

   	mLoadBalancingClient.opJoinRandomRoom( roomProperties, maxPlayers );
}

void HypPhoton::createRoom( const char *sRoom_name , int maxPlayers ){
	printf("createRoom with %d max players\n",maxPlayers);
	//ExitGames::Common::JString tmp;
   	mLoadBalancingClient.opCreateRoom( sRoom_name , true , true , maxPlayers );
}


void HypPhoton::send( const char *sText ){
	printf("send ::: %s\n",sText );

	ExitGames::Common::Hashtable 	data;
							data.put<int, ExitGames::Common::JString>(100,sText);

	mLoadBalancingClient.opRaiseEvent(true, data, 100);
}

const char * HypPhoton::getState( void ){
	switch( mLoadBalancingClient.getState( ) ){

		case ExitGames::LoadBalancing::PeerStates::Uninitialized:
			return "Uninitialized";

		case ExitGames::LoadBalancing::PeerStates::PeerCreated:
			return "PeerCreated";

		case ExitGames::LoadBalancing::PeerStates::Connecting:
			return "Connecting";

		case ExitGames::LoadBalancing::PeerStates::Connected:
			return "Connected";

		case ExitGames::LoadBalancing::PeerStates::Queued:
			return "Queued";

		case ExitGames::LoadBalancing::PeerStates::Authenticated:
			return "Authenticated";

		case ExitGames::LoadBalancing::PeerStates::JoinedLobby:
			return "JoinedLobby";

		case ExitGames::LoadBalancing::PeerStates::DisconnectingFromMasterserver:
			return "DisconnectingFromMasterserver";

		case ExitGames::LoadBalancing::PeerStates::ConnectingToGameserver:
			return "ConnectingToGameserver";

		case ExitGames::LoadBalancing::PeerStates::ConnectedToGameserver:
			return "ConnectedToGameserver";

		case ExitGames::LoadBalancing::PeerStates::AuthenticatedOnGameServer:
			return "AuthenticatedOnGameServer";

		case ExitGames::LoadBalancing::PeerStates::Joining:
			return "Joining";

		case ExitGames::LoadBalancing::PeerStates::Joined:
			return "Joined";

		case ExitGames::LoadBalancing::PeerStates::Leaving:
			return "Leaving";

		case ExitGames::LoadBalancing::PeerStates::Left:
			return "Left";

		case ExitGames::LoadBalancing::PeerStates::DisconnectingFromGameserver:
			return "DisconnectingFromGameserver";

		case ExitGames::LoadBalancing::PeerStates::ConnectingToMasterserver:
			return "ConnectingToMasterserver";

		case ExitGames::LoadBalancing::PeerStates::ConnectedComingFromGameserver:
			return "ConnectedComingFromGameserver";

		case ExitGames::LoadBalancing::PeerStates::QueuedComingFromGameserver:
			return "QueuedComingFromGameserver";

		case ExitGames::LoadBalancing::PeerStates::AuthenticatedComingFromGameserver:
			return "AuthenticatedComingFromGameserver";

		case ExitGames::LoadBalancing::PeerStates::Disconnecting:
			return "Disconnecting";

		case ExitGames::LoadBalancing::PeerStates::Disconnected:
			return "Disconnected";


	}
	return "unknow state";
}

void HypPhoton::hideRoom( void ){
	printf("hideRoom\n");
	mLoadBalancingClient.getCurrentlyJoinedRoom( ).setIsVisible( false );
}

const char * HypPhoton::getRoom_desc( void ){
	return mLoadBalancingClient.getCurrentlyJoinedRoom( ).toString( ).UTF8Representation( );
}

const char * HypPhoton::getRoom_players( void ){
	int l = mLoadBalancingClient.getCurrentlyJoinedRoom( ).getPlayers( ).getSize();
	printf("getRoom_players %i\n", l);
	ExitGames::Common::JString res = "";
	for( unsigned int i=0 ; i < l ; i++ ){
		//printf("%i::::::::::::::: s %s\n",i,mLoadBalancingClient.getCurrentlyJoinedRoom( ).getPlayers( )[i].getName( ).cstr( ) );
		if(i != 0)
    			res = res + "|||";
  			res = res + mLoadBalancingClient.getCurrentlyJoinedRoom( ).getPlayers( )[i].getName( );//.cstr( );
	}

	return res.UTF8Representation( );
}

void HypPhoton::leaveRoom( void ){
	mLoadBalancingClient.opLeaveRoom( );
}

//constructors / destructor  -----------------------------------------------------------------------------------------

HypPhoton::HypPhoton()
#ifdef _EG_MS_COMPILER
#	pragma warning(push)
#endif
	: mLoadBalancingClient(*this, L"appid", L"1.0", PLAYER_NAME )
#ifdef _EG_MS_COMPILER
#	pragma warning(pop)
#endif
{
    	printf("constructor\n");
}

HypPhoton::~HypPhoton(){
    printf("destructor\n");
}

HypPhoton& HypPhoton::Instance(){
    return m_instance;
}

//private -----------------------------------------------------------------------------------------

void HypPhoton::clientErrorReturn(int errorCode){
	printf("HypPhoton::clientErrorReturn %i\n",errorCode);
	onEvent( CLIENT_ERROR , errorCode+"" );
}

void HypPhoton::connectReturn(int errorCode, const ExitGames::Common::JString& errorString){
	printf("HypPhoton::connectReturn\n");
	if( errorCode ){
		printf("HypPhoton::connectReturn error %ls\n",errorString.cstr( ));
		onEvent( CONNECT_ERROR , errorString.UTF8Representation( ));
		return;
	}
	printf("connected\n");
	onStatus( ExitGames::Photon::StatusCode::CONNECT );
	onEvent( CONNECT_SUCCESS , "" );
}

void HypPhoton::connectionErrorReturn(int errorCode){
	//printf("HypPhoton::connectionErrorReturn %s\n",convert( errorCode));
	onEvent( CONNECT_ERROR , convert( errorCode ) );
}

void HypPhoton::createRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString){
	printf("createRoomReturn\n");

	if( errorCode ){
		printf("createRoomReturn() failed: %s\n", errorString.cstr( ));
		//onStatus( 1050 );
		onEvent( CREATE_ROOM_ERROR , errorString.UTF8Representation( ) );
		return;
	}
	printf("game room has been successfully created\n");
	onEvent( CREATE_ROOM_SUCCESS , mLoadBalancingClient.getCurrentlyJoinedRoom().getName().UTF8Representation( ) );
}

void HypPhoton::customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Hashtable& datas){
	//datas.getValue( 0 );
	//printf("customEventAction\n");
	using ExitGames::Common::ValueObject;
	ExitGames::Common::JString value = ValueObject<ExitGames::Common::JString>(datas.getValue( 100 )).getDataCopy();
	//printf("response%s\n",value.UTF8Representation( ) );
	onEvent( EVENT , value.UTF8Representation( ));
}

void HypPhoton::debugReturn(ExitGames::Common::DebugLevel::DebugLevel debugLevel, const ExitGames::Common::JString& string){
	onEvent( DEBUG_RETURN , string.UTF8Representation( ) );
}

void HypPhoton::debugReturn(const ExitGames::Common::JString& string){
	printf("HypPhoton::debugReturn %s\n",string.cstr( ));
	onEvent( DEBUG_RETURN , string.UTF8Representation( ) );
}

void HypPhoton::disconnectReturn(void){
	printf("HypPhoton::disconnectReturn\n");
	onEvent( DISCONNECT_RETURN , "" );
}

void HypPhoton::gotQueuedReturn(void){
	printf("HypPhoton::gotQueuedReturn\n");
	onEvent( GOT_QUEUE_RETURN , "" );
}

void HypPhoton::joinLobbyReturn(void){
	printf("HypPhoton::joinLobbyReturn\n");
	onEvent( JOINED_LOBBY_SUCCESS , "" );
}

void HypPhoton::joinRandomRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString){
	printf("joinRandomRoomReturn\n");
	if( errorCode ){
		printf("opJoinRandomRoom() failed: %s\n", errorString.cstr( ));
		onEvent( JOIN_RANDOM_ROOM_ERROR , errorString.UTF8Representation( ));
		return;
	}

	onEvent( JOIN_RANDOM_ROOM_SUCCESS , mLoadBalancingClient.getCurrentlyJoinedRoom( ).getName( ).UTF8Representation( ) );
}

void HypPhoton::joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player){
	onEvent( PLAYER_JOINED_ROOM , player.getName( ).UTF8Representation( ) );
}

void HypPhoton::joinRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString){
	printf("joinRoomReturn()\n");

	if( errorCode ){
		onEvent( JOIN_ROOM_ERROR , errorString.UTF8Representation( ) );
		return;
	}
	onEvent( JOIN_ROOM_SUCCESS , mLoadBalancingClient.getCurrentlyJoinedRoom().getName().UTF8Representation( ) );
}

void HypPhoton::leaveLobbyReturn(void){
	printf("leaveLobbyReturn\n");
	onEvent( LOBBY_LEAVE , "" );
}

void HypPhoton::leaveRoomEventAction(int playerNr){
	printf("leaveRoomEventAction\n");
	onEvent( PLAYER_LEAVED_ROOM , convert( playerNr ));
}

void HypPhoton::leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString){
	printf("leaveRoomReturn\n");
	if( errorCode ){
		onEvent( LEAVE_ROOM_FAILED , errorString.UTF8Representation( ) );
		return;
	}
	onEvent( LEAVE_ROOM_SUCCESS , "");
}

void HypPhoton::serverErrorReturn(int errorCode){
	printf("serverErrorReturn\n");
	onEvent( SERVER_ERROR , convert( errorCode));
}

void HypPhoton::warningReturn(int warningCode){
	onEvent( SERVER_WARNING , convert( warningCode ) );
	printf("warningReturn\n");
}

const char * HypPhoton::convert( int value ){
	return "";
	/*
	std::stringstream 	out;
					out << value;
	return out.str( ).c_str( );
	*/
}
