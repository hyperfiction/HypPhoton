package fr.hyperfiction;

import java.util.Hashtable;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

import de.exitgames.client.photon.*;
import de.exitgames.client.photon.enums.*;

import android.app.Service;
import android.content.Intent;
import android.graphics.Color;
import android.os.Binder;
import android.os.Handler;
import android.os.IBinder;
import android.util.Log;

import org.haxe.nme.HaxeObject;

/**
* ...
* @author shoe[box]
*/
class HypPhoton implements IPhotonPeerListener{

	private LitePeer peer;
	private HaxeObject cb;

	// -------o constructor

		/**
		* constructor
		*
		* @param
		* @return	void
		*/
		public HypPhoton( ){
			trace("constructor");
			peer = new LitePeer( this , true );
		}

	// -------o public

		/**
		*
		*
		* @public
		* @return	void
		*/
		public void connect( String sHost , String sApp_name , HaxeObject cb ){
			trace("connect ::: "+sHost+" - "+sApp_name+" - "+cb);
			this.cb = cb;
			peer.connect( sHost , sApp_name );
		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public void debugReturn( DebugLevel level , String message ){

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public void onEvent( EventData ev ){

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public void onOperationResponse( OperationResponse response ){

		}

		/**
		*
		*
		* @public
		* @return	void
		*/
		public void onStatusChanged( StatusCode statusCode ){

		}

	// -------o protected

	// -------o misc

		/**
		*
		*
		* @public
		* @return	void
		*/
		public static HypPhoton getInstance( ){

			if( __instance == null )
				__instance = new HypPhoton( );

			return __instance;
		}
		private static HypPhoton __instance = null;

		/**
		*
		*
		* @private
		* @return	void
		*/
		public static void trace( String s ){
			Log.w( TAG, "[Java] HypPhoton ::: "+s );
		}

		private static final String TAG = "trace";
}