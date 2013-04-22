package fr.hyperfiction;

/**
 * ...
 * @author shoe[box]
 */
@:build( ShortCuts.mirrors( ) )
class HypPhoton{

	public var onStatus	( default , default ) : Int->Void;
	public var onEvent	( default , default) : String->String->Void;

	private var _cb : HaxeObject;

	// -------o constructor

		/**
		* constructor
		*
		* @param
		* @return	void
		*/
		public function new( ) {
			trace("constructor");
			_cb = new HaxeObject( );
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
		@CPP("HypPhoton","HypPhoton_connect")
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
		@CPP("HypPhoton","HypPhoton_test")
		public function test( ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		@CPP("HypPhoton","HypPhoton_update")
		public function update( ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		@CPP("HypPhoton","HypPhoton_joinRandom_room")
		public function joinRandom_room( iMax_players : Int ) : Void{

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		@CPP("HypPhoton","HypPhoton_createRoom")
		public function createRoom( max : Int ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		@CPP("HypPhoton","HypPhoton_send")
		public function send( s : String ) : Void {

		}

	// -------o private

		/**
		*
		*
		* @public
		* @return	void
		*/
		@CPP("HypPhoton","HypPhoton_setStatus_callback")
		private function _setStatus_callback( f : Int->Void ) : Void {

		}

		/**
		*
		*
		* @private
		* @return	void
		*/
		@CPP("HypPhoton","HypPhoton_setEvent_callback")
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

		#if android

		@JNI( "fr.hyperfiction.HypPhoton" , "getInstance" )
		static private function getJava_instance( ) : HypPhoton { }

		@JNI( "fr.hyperfiction.HypPhoton" , "connect" )
		private function _connect( instance : Dynamic , sHost : String , sApp_name : String , cb : HaxeObject ) : Void { }

		#end
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

class HaxeObject{
	public var onStatus : String->Void;
	public var onEvent : Int->Void;

	public function new( ){

	}
}