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
