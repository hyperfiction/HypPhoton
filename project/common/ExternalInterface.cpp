#ifndef IPHONE
#define IMPLEMENT_API
#endif

#ifndef WINDOWS
#define _WINSOCKAPI_
//#define _ITERATOR_DEBUG_LEVEL 2
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include <hx/CFFI.h>
#include "HypPhoton.h"
#include <hxcpp.h>
#include <stdio.h>

#ifdef ANDROID
	#include <hx/CFFI.h>
	#include <hx/Macros.h>
	#include <jni.h>
	#define LOG_TAG "trace"
	#define printf(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#endif


AutoGCRoot *eval_onStatus = 0;
AutoGCRoot *eval_onEvent = 0;

extern "C"{

	int HypPhoton_register_prims(){
		printf("HypPhoton : register_prims()\n");
		return 0;
	}

	void onStatus( int status ){
		printf("onStatus");
		val_call1( eval_onStatus->get( )  , alloc_int( status ) );
	}

	void onEvent( const char *sName , const char *sValue ){
		val_call2( eval_onEvent->get( ) , alloc_string( sName ) , alloc_string( sValue ));
	}
}

// Common --------------------------------------------------------------------------------------

	static value HypPhoton_test( ){
		printf("test\n");
		HypPhoton::Instance( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_test , 0 );

	static value HypPhoton_connect( value sHost ){
		printf("connect\n");
		HypPhoton::Instance().connect( val_string( sHost ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_connect , 1 );

	static value HypPhoton_disconnect( ){
		printf("HypPhoton_disconnect\n");
		HypPhoton::Instance( ).disconnect( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_disconnect , 0 );

	static value HypPhoton_update( ){
		HypPhoton::Instance( ).update( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_update , 0 );

	static value HypPhoton_joinRandom_room( value iMax ){
		printf("HypPhoton_joinRandom_room %i\n",val_int( iMax));
		HypPhoton::Instance( ).joinRandom_room( val_int( iMax ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_joinRandom_room , 1 );

	static value HypPhoton_createRoom( value sName , value iMax ){
		printf("createRoom with %s %d players max\n",val_string( sName ) , val_int( iMax) );
		HypPhoton::Instance( ).createRoom( val_string( sName ) , val_int( iMax ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_createRoom , 2 );

	static value HypPhoton_send( value sText ){
		printf("HypPhoton_send %s\n",val_string(sText) );
		HypPhoton::Instance( ).send( val_string( sText ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_send , 1 );

	static value HypPhoton_setUser_name( value sName ){
		HypPhoton::Instance( ).setUser_name( val_string( sName ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_setUser_name , 1 );

	static value HypPhoton_getState( ){
		return alloc_string( HypPhoton::Instance( ).getState( ) );
	}
	DEFINE_PRIM( HypPhoton_getState , 0 );

	static value HypPhoton_hideRoom( ){
		HypPhoton::Instance( ).hideRoom( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_hideRoom , 0 );

	static value HypPhoton_joinLobby( ){
		printf("HypPhoton_joinLobby\n");
		HypPhoton::Instance( ).joinLobby( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypPhoton_joinLobby , 0 );

// Callbacks --------------------------------------------------------------------------------------

	static value HypPhoton_setStatus_callback( value cb ){
		eval_onStatus = new AutoGCRoot( cb );
		return alloc_bool( true );
	}
	DEFINE_PRIM( HypPhoton_setStatus_callback , 1 );

	static value HypPhoton_setEvent_callback( value cb ){
		eval_onEvent = new AutoGCRoot( cb );
		return alloc_bool( true );
	}
	DEFINE_PRIM( HypPhoton_setEvent_callback , 1 );