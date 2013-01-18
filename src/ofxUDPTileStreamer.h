#pragma once

/*

	Written by Ben McChesney of Helios Interactive
	I needed a way to send large images over a localHost
	I figured by creating modular sections of a texture and submitting them in parallel then drawing them next to each other
*/

#include "ofMain.h"
#include "ofxNetwork.h"

class ofxUDPTileStreamer
{
	public : 
		ofxUDPTileStreamer( ) { } 
		~ofxUDPTileStreamer( ) { }

		int tileWidth , tileHeight ; 
		ofTexture texture ; 

		void setupStreamer ( int _width , int _height , string _address , int _port , ofColor _debugColor ) ; 
		void setupListener ( int _width , int _height , string _address , int _port , ofColor _debugColor ) ; 
		void draw ( float x , float y ) ; 
		void sendData( ) ;
		void recieveData( ) ; 
		void generateNoise( ) ; 
		string address ; 
		int port ; 

		ofxUDPManager udpConnection ;
		int messageSentStatus ;

		ofColor debugColor ;

};