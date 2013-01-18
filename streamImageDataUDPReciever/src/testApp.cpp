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

	//bFirstContact = false ; 
	//connectionsRecieved = 0 ; 
	tileStreamer.setupListener( 125 , 125 , "127.0.0.1" , 11999 , ofColor( 255 , 0 , 255 ) ) ; 
	tileStreamer2.setupListener( 125 , 125 , "127.0.0.1" , 11998 , ofColor( 0 , 255 , 125 ) ) ; 
}

//--------------------------------------------------------------
void testApp::update(){

	/*
	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
	if(message!="")
	{
		
		connectionsRecieved++ ; 
		if ( connectionsRecieved == 1 ) 
		{
			cout << "1st message : " << message << endl ; 
			string _width = message.substr( 5 , message.length() - 5 ) ; 
			cout << "width : " << _width << " : " << ofToFloat( _width) << endl ; 
			recievedTexture.allocate( ofToFloat( _width) , ofToFloat( _width) , GL_RGB ) ; 
			recievedTexture2.allocate( ofToFloat( _width) , ofToFloat( _width) , GL_RGB ) ; 
		}
		if ( connectionsRecieved == 2 ) 
		{
			cout << "2nd message : " << message << endl; 
			string _height = message.substr( 6 , message.length() - 6 ) ; 
			cout << "height : " << _height << " : " << ofToFloat( _height ) << endl ; 
			float _width = recievedTexture.getWidth() ; 
			recievedTexture.allocate( _width ,  ofToFloat( _height ) , GL_RGB ) ; 
			recievedTexture2.allocate( _width ,  ofToFloat( _height ) , GL_RGB ) ; 
		}
		//The first message is for calibration and tells us dimensions
		if ( bFirstContact == false ) 
		{
			bFirstContact = true ; 
		}

		int width = recievedTexture.getWidth() ; 
		int height = recievedTexture.getHeight() ; 
		int numChannels = 3 ; 
		int numPixels = width*height*numChannels + 1  ; 
		
		char _char0 = 0 ;  
		char _char1 = 1 ;  
		//if ( message.at( 0 ) == _char0 )
		//{
			cout << "first! " << endl; 
			//unsigned char * webcamPixels = videoGrabber.getPixels() ; 
			unsigned char * pixels = new unsigned char[ numPixels ] ; //videoGrabber.getPixels() ; 
		
			for ( int i = 1 ; i < numPixels ; i+=3 ) 
			{
				pixels[i] = udpMessage[i] ; 
				pixels[i+1] = udpMessage[i+1] ; 
				pixels[i+2] = udpMessage[i+2] ; 
			}

			recievedTexture.loadData( pixels , recievedTexture.getWidth() , recievedTexture.getHeight() , GL_RGB ) ; 
		//}
		//if (  message.at( 0 ) == _char1 ) 
		//{
			cout << "second! " << endl; 
			/*
			unsigned char * _pixels = new unsigned char[ numPixels ] ; //videoGrabber.getPixels() ; 
		
			for ( int i = 1 ; i < numPixels ; i+=3 ) 
			{
				_pixels[i] = udpMessage[i] ; 
				_pixels[i+1] = udpMessage[i+1] ; 
				_pixels[i+2] = udpMessage[i+2] ; 
			}
		
			recievedTexture2.loadData( _pixels , recievedTexture.getWidth() , recievedTexture.getHeight() , GL_RGB ) ; */
		//}
		//else
		//{
			/*
			char _char = 1 ; 
			string subString =  message.substr( 0 , 1 ) ; //message.at( 0 ) ; 
			cout << "SUB STRING : " << subString << endl ; 
			cout << "0 char is : '" << _char << "'"<< endl ;
			string msg = ofToString( message[0] ) ;
			cout << "message[0] = " << message[0]<< endl ; 
			cout << "message[0] as a string " << ofToString( message[0] ) << endl ; */
		//}
		/*
		char udpMessage[100000];
		udpConnection.Receive(udpMessage,100000);

		unsigned char * _pixels = new unsigned char[ numPixels ] ; //videoGrabber.getPixels() ; 
		
		for ( int i = 0 ; i < numPixels ; i+=3 ) 
		{
			_pixels[i] = udpMessage[i] ; 
			_pixels[i+1] = udpMessage[i+1] ; 
			_pixels[i+2] = udpMessage[i+2] ; 
		}
		
		recievedTexture2.loadData( _pixels , recievedTexture.getWidth() , recievedTexture.getHeight() , GL_RGB ) ; 
		*/


	//}

	tileStreamer.recieveData() ;
	tileStreamer2.recieveData( ) ; 

}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
	ofDrawBitmapStringHighlight("ImageStreamRecieveUDP : fps " + ofToString( ofGetFrameRate() ) , 10, ofGetHeight() - 60 );

	ofSetColor( 255 ) ;
	tileStreamer.draw( 25 , 25 ) ; 
	tileStreamer2.draw( 25 + 10 + tileStreamer.tileWidth , 25 ) ; 
//	recievedTexture2.draw( 50 + recievedTexture.getWidth() , 25 ) ; 
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
