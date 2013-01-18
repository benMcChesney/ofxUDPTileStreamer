#include "testApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void testApp::setup(){
	// we don't want to be running to fast
	ofSetVerticalSync(true);
	ofSetFrameRate(30);

	string address = "127.0.0.1" ; 
	int port = 11999 ; 

	//( int _width , int _height , string _address , int _port ) ; 
	tileStreamer.setupStreamer( 125 , 125 , address , port , ofColor( 255 , 0 , 255 ) ) ; 
	tileStreamer2.setupStreamer( 125 , 125 , address , 11998 , ofColor( 0 , 255 , 125 ) ) ; 
	/*
    //create the socket and set to send to 127.0.0.1:11999
	udpConnection.Create();
	udpConnection.Connect( address.c_str() , port );
	udpConnection.SetNonBlocking(true);
	*/
	videoGrabber.listDevices() ; 
	videoGrabber.initGrabber( 640 , 480 , true ) ;

	//bCalibrationMessageSent = false ; 

	//fragmentWidth = 125 ; 
	//fragmentHeight = 125 ; 
}

//--------------------------------------------------------------
void testApp::update(){

	ofSetWindowTitle( ofToString( ofGetFrameRate() ) + " fps" ) ; 
	/*
	if ( bCalibrationMessageSent == false ) 
	{
		//bCalibrationMessageSent = true ; 
		int width = fragmentWidth ; 
		int height = fragmentHeight ; 
	
		string message = "width"+ofToString( width ) ; 
		udpConnection.Send( message.c_str() , message.length() ) ;

		string message2 = "height" + ofToString( height ) ; 
		udpConnection.Send( message2.c_str() , message2.length() ) ;  

		bCalibrationMessageSent = true ; 
		return ; 
		
	}*/
	videoGrabber.update() ; 

	/*
	if ( videoGrabber.isFrameNew() ) 
	{
		int width = fragmentWidth ; 
		int height = fragmentHeight ; 
		int numChannels = 3 ; 

		int numPixels = width*height*numChannels + 1 ; 
		unsigned char * webcamPixels = videoGrabber.getPixels() ; 
		unsigned char * pixels = new unsigned char[ numPixels  ] ; //videoGrabber.getPixels() ; 
		pixels[0] = 0 ; 
		for ( int i = 0 ; i < numPixels ; i+=3 ) 
		{
			pixels[i] = ofRandom( 255 ) ; 
			pixels[i+1] = ofRandom ( 64 , 198 )  ; 
			pixels[i+2] = ofRandom( 0 , 128 ) ; 
		}
		messageSentStatus = udpConnection.SendAll( (char*)pixels , numPixels ) ; 
		
		
		unsigned char * pixels2 = new unsigned char[ numPixels ] ; //videoGrabber.getPixels() ; 
		pixels[0] = 1 ;
		for ( int i = 1 ; i < numPixels ; i+=3 ) 
		{
			pixels2[i] = ofRandom( 0 , 128 ) ; 
			pixels2[i+1] = ofRandom ( 68 )  ; 
			pixels2[i+2] = ofRandom( 255 ) ; 
		}
		//messageSentStatus = udpConnection.SendAll( (char*)pixels2 , numPixels ) ; 
	}*/

	tileStreamer.generateNoise( ) ; 
	tileStreamer.sendData( ) ; 

	tileStreamer2.generateNoise( ) ; 
	tileStreamer2.sendData( ) ; 

	/*
		//string message="";
	//for(int i=0; i<stroke.size(); i++){
	//	message+=ofToString(stroke[i].x)+"|"+ofToString(stroke[i].y)+"[/p]";
	//}
	//int sent = udpConnection.Send(message.c_str(),message.length());
	*/
}

//--------------------------------------------------------------
void testApp::draw(){

	string status = "connected to UDP via - " ; //+ address + ":" + ofToString( port ) ; 
	status += "\nstreamer1 status : " + ofToString(tileStreamer.messageSentStatus) ; 
	status += "\nstreamer2 status : " + ofToString(tileStreamer2.messageSentStatus) ; 

	//"\nmessageSentStatus : " + ofToString( messageSentStatus ) ;
	ofDrawBitmapStringHighlight ( status , 25 , ofGetHeight() - 50 ) ; 
	ofSetColor( 255 , 255 , 255 ) ;
	videoGrabber.draw ( 25 , 25 ) ; 

	tileStreamer.draw( 25 , ofGetHeight() - 75 - tileStreamer.tileHeight ) ;
	tileStreamer2.draw( 25 + tileStreamer.tileWidth , ofGetHeight() - 75 - tileStreamer.tileHeight ) ;
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
	//stroke.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//stroke.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//string message="";
	//for(int i=0; i<stroke.size(); i++){
	//	message+=ofToString(stroke[i].x)+"|"+ofToString(stroke[i].y)+"[/p]";
	//}
	//int sent = udpConnection.Send(message.c_str(),message.length());
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
