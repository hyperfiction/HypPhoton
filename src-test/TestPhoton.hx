package ;

import fr.hyperfiction.HypPhoton;

import flash.display.Sprite;

/**
 * ...
 * @author shoe[box]
 */

class TestPhoton extends Sprite{

	private var _photon : HypPhoton;
	private var _bRoom : Bool;

	// -------o constructor

		/**
		* constructor
		*
		* @param
		* @return	void
		*/
		public function new() {
			super( );
			trace("constructor");

			#if cpp
				#if debugger
				new hxcpp.DebugStdio( false );
				#end
			#end

			_photon = new HypPhoton( );
			_photon.onEvent = _onEvent;
			//_photon.init("osef","0.1","player"+Std.int( Math.random( ) * 1000 ) );
			_photon.connect( "137.116.225.3:5055");
			//_photon.connect( "app.exitgamescloud.com:5055");
			nme.Lib.current.stage.addEventListener( flash.events.Event.ENTER_FRAME , function( _ ){
				_photon.update( );
			});
		}

	// -------o public

	// -------o protected



		/**
		*
		*
		* @private
		* @return	void
		*/
		private function _onEvent( s : String , v : String ) : Void{
			trace("_onEvent ::: "+s+" - "+v);

			switch( s ){

				case PhotonEvents.CLIENT_ERROR:

				case PhotonEvents.CONNECT_ERROR:

				case PhotonEvents.CONNECT_SUCCESS:
					_photon.joinRandom_room( 2 );

				case PhotonEvents.CREATE_ROOM_ERROR:

				case PhotonEvents.CREATE_ROOM_SUCCESS:

				case PhotonEvents.DEBUG_RETURN:

				case PhotonEvents.DISCONNECT_RETURN:

				case PhotonEvents.GOT_QUEUE_RETURN:

				case PhotonEvents.JOINED_LOBBY_SUCCESS:

				case PhotonEvents.JOIN_RANDOM_ROOM_ERROR:
					trace("JOIN_RANDOM_ROOM_ERROR");
					trace("create room");
					_photon.createRoom( "2" , 2 );

				case PhotonEvents.JOIN_RANDOM_ROOM_SUCCESS:
					trace("JOIN_RANDOM_ROOM_SUCCESS");
					haxe.Timer.delay( function( ){
						trace("send test");
						_photon.send("testéééééé");
					},1000 );

				case PhotonEvents.JOIN_ROOM_ERROR:

				case PhotonEvents.JOIN_ROOM_SUCCESS:

				case PhotonEvents.LEAVE_ROOM_FAILED:

				case PhotonEvents.LEAVE_ROOM_SUCCESS:

				case PhotonEvents.LOBBY_LEAVE:

				case PhotonEvents.PLAYER_JOINED_ROOM:
					_bRoom = true;
					_photon.send("test");

				case PhotonEvents.PLAYER_LEAVED_ROOM:

				case PhotonEvents.SERVER_ERROR:

				case PhotonEvents.SERVER_WARNING:


			}
		}

	// -------o misc

}