#pragma once

/*

	Written by Ben McChesney of Helios Interactive
	I needed a way to send large images over a localHost
	I figured by creating modular sections of a texture and submitting them in parallel then drawing them next to each other
*/

#include "ofMain.h"
#include "ofxNetwork.h"
#define MAX_FRAGMENT_SIZE 46875

class ofxUDPTileStreamer
{
	public : 
		ofxUDPTileStreamer( ) { } 
		ofxUDPTileStreamer( bool bStreaming , int _width , int _height , string _address , int _port , ofColor _debugColor   )
		{
			setup ( bStreaming , _width , _height , _address , _port , _debugColor ) ; 
		} 

		~ofxUDPTileStreamer( ) { }

		int tileWidth , tileHeight ; 
		ofTexture texture ; 

		void setup ( bool bStreaming , int _width , int _height , string _address , int _port , ofColor _debugColor ) ; 
		void draw ( float x , float y ) ; 
		void sendData( ) ;
		void recieveData( ) ; 
		void recieveMessage( char udpMessage[100000] ) ; 
		void generateNoise( ) ; 
		string address ; 
		int port ; 

		ofxUDPManager udpConnection ;
		int messageSentStatus ;
		int messageRecievedStatus ; 

		ofColor debugColor ;

};