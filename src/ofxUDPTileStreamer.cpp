 

#define STREAM_PACKET_MAX 100000
	
#include "ofxUDPTileStreamer.h"

void ofxUDPTileStreamer::setup ( bool bStreaming , int _width , int _height , string _address , int _port , ofColor _color ) 
{
	tileWidth = _width ; 
	tileHeight = _height ;
	address = _address ; 
	port = _port ; 
	debugColor = _color ; 

	udpConnection.SetReuseAddress( true ) ; 
	udpConnection.SetTimeoutReceive( 100 ) ; 
	udpConnection.SetTimeoutSend( 100 ) ; 
	udpConnection.Create() ; 
	

	if ( bStreaming == true ) 
	{
		cout << "streaming on : " << address << ":" << port << endl; 
		bool bResult = udpConnection.Connect( address.c_str() , port );
		cout << bResult << " connection result on port : " << port << endl  ; 
		udpConnection.SetNonBlocking(true);
	}
	else
	{
		cout << "listening on : " << address << ":" << port << endl; 
		
		bool bResult = udpConnection.Bind( port );
		cout << bResult <<  " bind result on port : " << port << endl  ; 
		udpConnection.SetNonBlocking( true );
	}

	messageSentStatus = -1 ;
	messageRecievedStatus = -1 ;
	
	texture.allocate( tileWidth , tileHeight , GL_RGB ) ; 

}

void ofxUDPTileStreamer::draw ( float x , float y ) 
{
	ofSetColor( 255 , 255 , 255 ) ; 
	texture.draw( x , y ) ; 
	string status = "sent: " + ofToString( messageSentStatus ) ; 
	status += "\nrecieved: " + ofToString( messageRecievedStatus ) ; 
	ofDrawBitmapStringHighlight( status , x , y + tileHeight + 5 ) ; 
}

void ofxUDPTileStreamer::sendData( )
{
	//ofPixels pix = ofPixels( ) ; 
	//pix.allocate( tileWidth , tileHeight , OF_IMAGETYPE_RGB ) ) ; 
	//unsigned char * pixels = texture.readToPixels(
	
}

void ofxUDPTileStreamer::recieveData( ) 
{
 
	char udpMessage[STREAM_PACKET_MAX];
	string message;
	string tempMessage;
	bool getNext = true ; 
	//while ( getNext ) 
	//{
		
		int recieve = udpConnection.Receive( udpMessage , STREAM_PACKET_MAX ) ; 
		tempMessage = udpMessage ; 

		//if ( tempMessage == "" ) 
		//{
		//	getNext = false ; 
		//}
		//else
		//{
			message = tempMessage ; 
		//}
	//}

	if ( message != "" ) 
	{
		int width = tileWidth ;
		int height = tileHeight ; 
		int numChannels = 3 ; 
		int numPixels = width*height*numChannels  ; 

		unsigned char * pixels = new unsigned char[ numPixels ] ; //videoGrabber.getPixels() ; 
		
		for ( int i = 0 ; i < numPixels ; i+=3 ) 
		{
			pixels[i] = udpMessage[i] ; 
			pixels[i+1] = udpMessage[i+1] ; 
			pixels[i+2] = udpMessage[i+2] ; 
		}

		texture.loadData( pixels , tileWidth , tileHeight , GL_RGB ) ; 
		messageRecievedStatus =  1 ;
	}
	else
	{
		messageRecievedStatus = -1 ; 
	}



	/*
	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
	if(message!="")
	{

		 
	}
	else
	{
		//cout << "blank message! " << endl ;
	}
		//if (  message.at( 0 ) == _char1 ) 
		//{
			//cout << "second! " << endl; 
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


	//}*/
}

void ofxUDPTileStreamer::recieveMessage( char udpMessage[100000] ) 
{
	
	//if ( message != "" ) 
	//{
		int width = tileWidth ;
		int height = tileHeight ; 
		int numChannels = 3 ; 
		int numPixels = width*height*numChannels  ; 

		unsigned char * pixels = new unsigned char[ numPixels ] ; //videoGrabber.getPixels() ; 
		
		for ( int i = 0 ; i < numPixels ; i+=3 ) 
		{
			pixels[i] = udpMessage[ i ] ; 
			pixels[i+1] = udpMessage[ i+1 ]  ; 
			pixels[i+2] = udpMessage[ i+2 ]  ; 
		}

		texture.loadData( pixels , tileWidth , tileHeight , GL_RGB ) ; 
		messageRecievedStatus =  1 ;
	//}
	//else
	//{
		messageRecievedStatus = -1 ; 
	//}
}

void ofxUDPTileStreamer::generateNoise( ) 
{
	int numChannels = 3 ; 

	int numPixels = tileWidth * tileHeight * numChannels ; 
	//unsigned char * webcamPixels = videoGrabber.getPixels() ; 

	unsigned char * pixels = new unsigned char[ numPixels  ] ; //videoGrabber.getPixels() ; 
	for ( int i = 0 ; i < numPixels ; i+=3 ) 
	{
		pixels[i] = ofRandom( debugColor.r ) ; 
		pixels[i+1] = ofRandom ( debugColor.g )  ; 
		pixels[i+2] = ofRandom( debugColor.b ) ; 
	}

	texture.loadData( pixels , tileWidth , tileHeight , GL_RGB ) ; 
	messageSentStatus = udpConnection.SendAll( (char*)pixels , numPixels ) ;
}

/*
string address ; 
int port ; 
int tileWidth , tileHeight ;
ofxUDPManager udpConnection ;
ofTexture texture ; 
*/