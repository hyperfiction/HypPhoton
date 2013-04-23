package fr.hyperfiction;

/**
 * ...
 * @author shoe[box]
 */
@:build( ShortCuts.mirrors( ) )
class HypPhoton{

	public var onStatus	( default , default ) : Int->Void;
	public var onEvent	( default , default) : String->String->Void;

	// -------o constructor

		/**
		* constructor
		*
		* @param
		* @return	void
		*/
		public function new( ) {
			trace("constructor");
			_setStatus_callback( _onStatus );
			_setEvent_callback( _onEvent );
		}

	// -------o public

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_setUser_name")
		#end
		public function setUser_name( setUser_name : String ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_connect")
		#end
		public function connect( sHost : String ) : Void {
			trace("connect");
			#if cpp
			_connect( );
			#end
		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_disconnect")
		#end
		public function disconnect( ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_test")
		#end
		public function test( ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_update")
		#end
		public function update( ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_joinRandom_room")
		#end
		public function joinRandom_room( iMax_players : Int ) : Void{

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_createRoom")
		#end
		public function createRoom( max : Int ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_send")
		#end
		public function send( s : String ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_getState")
		#end
		public function getState( ) : Int {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_hideRoom")
		#end
		public function hideRoom( ) : Void {

		}

	// -------o private

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_setStatus_callback")
		#end
		private function _setStatus_callback( f : Int->Void ) : Void {

		}

		/**
		*
		*
		* @private
		* @return	void
		*/
		#if cpp
		@CPP("HypPhoton","HypPhoton_setEvent_callback")
		#end
		private function _setEvent_callback( f : String->String->Void ) : Void{

		}

		/**
		*
		*
		* @private
		* @return	void
		*/
		private function _onStatus( i : Int ) : Void{
			trace("onStatus ::: "+i);
			//onStatus( i );
		}

		/**
		*
		*
		* @private
		* @return	void
		*/
		private function _onEvent( s : String , v : String ) : Void{
			//trace("_onEvent ::: "+s+" - "+v);
			onEvent( s , v );
		}

	// -------o misc

	// -------o android

}

class PhotonEvents{
	public static inline var CLIENT_ERROR			: String = "CLIENT_ERROR";
	public static inline var CONNECT_ERROR			: String = "CONNECT_ERROR";
	public static inline var CONNECT_SUCCESS		: String = "CONNECT_SUCCESS";
	public static inline var CREATE_ROOM_ERROR		: String = "CREATE_ROOM_ERROR";
	public static inline var CREATE_ROOM_SUCCESS		: String = "CREATE_ROOM_SUCCESS";
	public static inline var DEBUG_RETURN			: String = "DEBUG_RETURN";
	public static inline var DISCONNECT_RETURN		: String = "DISCONNECT_RETURN";
	public static inline var GOT_QUEUE_RETURN		: String = "GOT_QUEUE_RETURN";
	public static inline var JOINED_LOBBY_SUCCESS	: String = "JOINED_LOBBY_SUCCESS";
	public static inline var JOIN_RANDOM_ROOM_ERROR	: String = "JOIN_RANDOM_ROOM_ERROR";
	public static inline var JOIN_RANDOM_ROOM_SUCCESS	: String = "JOIN_RANDOM_ROOM_SUCCESS";
	public static inline var JOIN_ROOM_ERROR		: String = "JOIN_ROOM_ERROR";
	public static inline var JOIN_ROOM_SUCCESS		: String = "JOIN_ROOM_SUCCESS";
	public static inline var LEAVE_ROOM_FAILED		: String = "LEAVE_ROOM_FAILED";
	public static inline var LEAVE_ROOM_SUCCESS		: String = "LEAVE_ROOM_SUCCESS";
	public static inline var LOBBY_LEAVE			: String = "LOBBY_LEAVE";
	public static inline var PLAYER_JOINED_ROOM		: String = "PLAYER_JOINED_ROOM";
	public static inline var PLAYER_LEAVED_ROOM		: String = "PLAYER_LEAVED_ROOM";
	public static inline var SERVER_ERROR			: String = "SERVER_ERROR";
	public static inline var SERVER_WARNING			: String = "SERVER_WARNING";
	public static inline var EVENT				: String = "EVENT";
}

class PhotonState{

	public static inline var DISCONNECTED             : Int = 0; // The peer is disconnected and can't call Operations. Call PhotonPeer_connect().
	public static inline var CONNECTING               : Int = 1; // The peer is establishing the connection: opening a socket, exchanging packages with Photon.
	public static inline var INITIALIZING_APPLICATION : Int = 2; // The connection is established and now sends the application name to Photon. You set the "application name" by calling PhotonPeer_connect().
	public static inline var CONNECTED                : Int = 3; // The peer is connected and initialized (selected an application). You can now use operations.
	public static inline var DISCONNECTING            : Int = 4; // The peer is disconnecting. It sent a disconnect to the server, which will acknowledge closing the connection.

}
