#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//we run at 60 fps!
	ofSetVerticalSync(true);
	ofSetFrameRate(30);

	/*
    //create the socket and bind to port 11999
	udpConnection.Create();
	udpConnection.Bind(11999);
	udpConnection.SetNonBlocking(true);
	*/

	ofSetBackgroundAuto(false);
	ofBackground(255, 255, 255);

	string address = "127.0.0.1" ; 
	int port = 11999 ; 
	int numTiles = 4 ; 
	vector<ofColor> debugColors ; 
	for ( int c = 0 ; c < numTiles ; c++ ) 
	{
		debugColors.push_back( ofColor( ofRandom( 255 ) , ofRandom( 255 ) , ofRandom( 255 ) ) ) ; 
	}
	for ( int i = 0 ; i < numTiles; i++ ) 
	{
		tiles.push_back( new ofxUDPTileStreamer( false , 125 , 125 , address , port + i , debugColors[i]) ) ; 
	}
	//bFirstContact = false ; 
	//connectionsRecieved = 0 ; 
	//tileStreamer.setup( false , 125 , 125 , "127.0.0.1" , 11999 , ofColor( 255 , 0 , 255 ) ) ; 
	//tileStreamer2.setup( false , 125 , 125 , "127.0.0.1" , 11998 , ofColor( 0 , 255 , 125 ) ) ; 
}

//--------------------------------------------------------------
void testApp::update(){


	char udpMessage[ MAX_FRAGMENT_SIZE ];
	
	for ( int i = 0 ; i < tiles.size() ; i++ ) 
	{
		tiles[i]->udpConnection.Receive(udpMessage, MAX_FRAGMENT_SIZE );
		tiles[i]->recieveMessage( udpMessage ) ;
	}
	/*
	tileStreamer.udpConnection.Receive(udpMessage, MAX_FRAGMENT_SIZE );
	string message = udpMessage;

	tileStreamer.recieveMessage( udpMessage ) ;


	tileStreamer2.udpConnection.Receive(udpMessage, MAX_FRAGMENT_SIZE );

	tileStreamer2.recieveMessage( udpMessage ) ; 
	*/
}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
	ofDrawBitmapStringHighlight("ImageStreamRecieveUDP : fps " + ofToString( ofGetFrameRate() ) , 10, ofGetHeight() - 60 );


	ofSetColor( 255 ) ;
	for ( int i = 0 ; i < tiles.size() ; i++ ) 
	{
		tiles[i]->draw( 25 + i * ( tiles[0]->tileWidth + 10 ) , ofGetHeight() - 75 - tiles[0]->tileHeight ) ;
	}

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
