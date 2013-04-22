package fr.hyperfiction;

#if flash
import exitgames.common.Logger;
import exitgames.photon.loadbalancing.Constants;
import exitgames.photon.loadbalancing.Actor;
import exitgames.photon.loadbalancing.LoadBalancingClient;
import exitgames.photon.loadbalancing.Room;
import exitgames.photon.loadbalancing.RoomInfo;
#end

/**
 * ...
 * @author shoe[box]
 */
@:build( ShortCuts.mirrors( ) )
class HypPhoton #if flash extends LoadBalancingClient #end{

	public var onStatus : String->Void;
	public var onEvent : Int->Void;

	public var server	( default , default ) : String;
	public var appId	( default , default ) : String;
	public var version	( default , default ) : String;

	private var _cb : HaxeObject;

	public static inline var AUTOJOIN_FAILED	: String = "AutoJoin_Failed";
	public static inline var JOINED_LOBBY		: String = "JoinedLobby";
	public static inline var JOINED_ROOM		: String = "Joined";

	// -------o constructor

		/**
		* constructor
		*
		* @param
		* @return	void
		*/
		public function new( server : String , appId : String , version : String , onStatus : String->Void , onEvent : Int->Void ) {
			trace("constructor");

			this.appId	= appId;
			this.onEvent	= onEvent;
			this.onStatus	= onStatus;
			this.server	= server;
			this.version	= version;

			#if android
			_cb = new HaxeObject( );
			_cb.onStatus	= _onStatus;
			_cb.onEvent	= _onEvent;
			#end

			#if flash
			super( server , appId , version );
			#end
		}

	// -------o public

		/**
		*
		*
		* @public
		* @return	void
		*/
		public function connectMe( sPlayer_name : String ) : Void {
			trace("connectMe ::: "+sPlayer_name);
			#if android
			_connect( getJavaInstance( ) , _cb , appId , version , sPlayer_name );
			#end
		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public function update( ) : Void {
			#if android
			_update( getJavaInstance( ) );
			#end
		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		#if android
		@JNI
		#end
		static public function joinRandom_room( max : Int , sName : String ) : Void {

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public function getRooms_count( ) : Int {
			trace("getRooms_count");
			#if android
			return _getRooms_count( );
			#end
		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public function getRooms_list( ) : Void {
			#if android
			_getRooms_list( getJavaInstance( ) );
			#end
		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public function createRoom( sName : String = null , bVisible : Bool = true , bOpened : Bool = true , iMax : Int = 2 ) : Void{
			#if android
			_createRoom( sName , bVisible , bOpened , iMax );
			#end
		}

	// -------o protected

		/**
		*
		*
		* @private
		* @return	void
		*/
		private function _onStatus( s : String ) : Void{
			trace("_onStatus ::: "+s+" - "+this.onStatus);

			var code : Int = Std.parseInt( s.substr( 0 , 3 ));
				trace("code ::: "+code);
			switch( code ){
				case ErrorsCode.Ok							:
					trace( "ErrorsCode.Ok");

				case ErrorsCode.OperationNotAllowedInCurrentState	:
					trace( "ErrorsCode.OperationNotAllowedInCurrentState");

				case ErrorsCode.InvalidOperationCode			:
					trace( "ErrorsCode.InvalidOperationCode");

				case ErrorsCode.InternalServerError			:
					trace( "ErrorsCode.InternalServerError");

				case ErrorsCode.InvalidAuthentication			:
					trace( "ErrorsCode.InvalidAuthentication");

				case ErrorsCode.GameIdAlreadyExists			:
					trace( "ErrorsCode.GameIdAlreadyExists");

				case ErrorsCode.GameFull						:
					trace( "ErrorsCode.GameFull");

				case ErrorsCode.GameClosed					:
					trace( "ErrorsCode.GameClosed");

				case ErrorsCode.AlreadyMatched				:
					trace( "ErrorsCode.AlreadyMatched");

				case ErrorsCode.ServerFull					:
					trace( "ErrorsCode.ServerFull");

				case ErrorsCode.UserBlocked					:
					trace( "ErrorsCode.UserBlocked");

				case ErrorsCode.NoRandomMatchFound				:
					trace( "ErrorsCode.NoRandomMatchFound");

				case ErrorsCode.GameDoesNotExist				:
					trace( "ErrorsCode.GameDoesNotExist");

			}

			if( s.substr( 0,3 ) == "-31" )
				s = AUTOJOIN_FAILED;

			this.onStatus( s );
		}

		/**
		*
		*
		* @private
		* @return	void
		*/
		private function _onEvent( i : Int ) : Void{
			this.onEvent( i );
		}

	// -------o android

		#if android

		/**
		*
		*
		* @public
		* @return	void
		*/
		@JNI( "fr.hyperfiction.HypPhoton" , "getInstance" )
		static private function getJavaInstance( ) : HypPhoton { }

		@JNI( "fr.hyperfiction.HypPhoton" , "connect" )
		private function _connect( __instance : Dynamic , cb : HaxeObject , sAppID : String , sAppVersion : String , sPlayerName : String ) : Void{ }

		@JNI( "fr.hyperfiction.HypPhoton" , "update" )
		private function _update( __instance : Dynamic ) : Void{ }

		@JNI( "fr.hyperfiction.HypPhoton" , "joinRandom_room" )
		private function _joinRandom_room( __instance : Dynamic ) : Void{ }

		@JNI( "fr.hyperfiction.HypPhoton" , "getRooms_list" )
		private function _getRooms( __instance : Dynamic ) : Void{ }

		@JNI( "fr.hyperfiction.HypPhoton" , "getRooms_count" )
		static private function _getRooms_count(  ) : Int{ }

		@JNI( "fr.hyperfiction.HypPhoton" , "createRoom" )
		static private function _createRoom( sName : String , v : Bool , o : Bool , max : Int ) : Void{ }

		@JNI( "fr.hyperfiction.HypPhoton" , "getRooms_list" )
		private function _getRooms_list( __instance : Dynamic ) : Void{ }

		#end

	// -------o misc

}

/**
* ...
* @author shoe[box]
*/
class HaxeObject{

	public var onStatus : String->Void;
	public var onEvent : Int->Void;

	// -------o constructor

		/**
		* constructor
		*
		* @param
		* @return	void
		*/
		public function new() {

		}

	// -------o public


	// -------o protected



	// -------o misc

}

/**
 * ...
 * @author shoe[box]
 */

class ErrorsCode{
	public static inline var Ok							: Int = 0;
	public static inline var OperationNotAllowedInCurrentState	: Int = -3;
	public static inline var InvalidOperationCode			: Int = -2;
	public static inline var InternalServerError				: Int = -1;
	public static inline var InvalidAuthentication			: Int = 0x7FFF;
	public static inline var GameIdAlreadyExists				: Int = 0x7FFF - 1;
	public static inline var GameFull						: Int = 0x7FFF - 2;
	public static inline var GameClosed					: Int = 0x7FFF - 3;
	public static inline var AlreadyMatched					: Int = 0x7FFF - 4;
	public static inline var ServerFull					: Int = 0x7FFF - 5;
	public static inline var UserBlocked					: Int = 0x7FFF - 6;
	public static inline var NoRandomMatchFound				: Int = 0x7FFF - 7;
	public static inline var GameDoesNotExist				: Int = 0x7FFF - 9;
}