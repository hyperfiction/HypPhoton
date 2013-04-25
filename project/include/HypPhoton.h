#ifndef HypPhoton_H
#define HypPhoton_H

#include <stdio.h>
#include <sstream>

#include "LoadBalancingListener.h"
#include "LoadBalancingClient.h"
#include "LoadBalancingPlayer.h"
#include "PeerStates.h"

#define CLIENT_ERROR			"CLIENT_ERROR"
#define CONNECT_ERROR			"CONNECT_ERROR"
#define CONNECT_SUCCESS			"CONNECT_SUCCESS"
#define CREATE_ROOM_ERROR		"CREATE_ROOM_ERROR"
#define CREATE_ROOM_SUCCESS		"CREATE_ROOM_SUCCESS"
#define DEBUG_RETURN			"DEBUG_RETURN"
#define DISCONNECT_RETURN		"DISCONNECT_RETURN"
#define GOT_QUEUE_RETURN			"GOT_QUEUE_RETURN"
#define JOINED_LOBBY_SUCCESS		"JOINED_LOBBY_SUCCESS"
#define JOIN_RANDOM_ROOM_ERROR	"JOIN_RANDOM_ROOM_ERROR"
#define JOIN_RANDOM_ROOM_SUCCESS	"JOIN_RANDOM_ROOM_SUCCESS"
#define JOIN_ROOM_ERROR			"JOIN_ROOM_ERROR"
#define JOIN_ROOM_SUCCESS		"JOIN_ROOM_SUCCESS"
#define LEAVE_ROOM_FAILED		"LEAVE_ROOM_FAILED"
#define LEAVE_ROOM_SUCCESS		"LEAVE_ROOM_SUCCESS"
#define LOBBY_LEAVE			 	"LOBBY_LEAVE"
#define PLAYER_JOINED_ROOM		"PLAYER_JOINED_ROOM"
#define PLAYER_LEAVED_ROOM		"PLAYER_LEAVED_ROOM"
#define SERVER_ERROR			"SERVER_ERROR"
#define SERVER_WARNING			"SERVER_WARNING"
#define EVENT			 		"EVENT"

class HypPhoton : private ExitGames::LoadBalancing::Listener{

	public:
		static HypPhoton& Instance();
		void connect( const char *sHost );
		void disconnect( );
		void update( void );
		void joinRandom_room( int maxPlayers );
		void createRoom( const char *sName , int maxPlayers );
		void send( const char *sText );
		void setUser_name( const char *sUser_name );
		const char * getState( void );
		void hideRoom( void );
		void joinLobby( void );

	private:
		//HypPhoton (const HypPhoton&){}
		HypPhoton();
		~HypPhoton();
		static HypPhoton m_instance;
		const char * convert( int code );
		virtual void clientErrorReturn(int errorCode);
		virtual void connectReturn(int errorCode, const ExitGames::Common::JString& errorString);
		virtual void connectionErrorReturn(int errorCode);
		virtual void createRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
		virtual void customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Hashtable& eventContent);
		virtual void debugReturn(ExitGames::Common::DebugLevel::DebugLevel debugLevel, const ExitGames::Common::JString& string);
		virtual void debugReturn(const ExitGames::Common::JString& string);
		virtual void disconnectReturn(void);
		virtual void gotQueuedReturn(void);
		virtual void joinLobbyReturn(void);
		virtual void joinRandomRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
		virtual void joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player);
		virtual void joinRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
		virtual void leaveLobbyReturn(void);
		virtual void leaveRoomEventAction(int playerNr);
		virtual void leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString);
		virtual void serverErrorReturn(int errorCode);
		virtual void warningReturn(int warningCode);

		ExitGames::LoadBalancing::Client mLoadBalancingClient;
};
#endif
