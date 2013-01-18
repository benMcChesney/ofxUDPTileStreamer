Created by Ben McChesney of Helios Interactive - Janurary 2013.
Using Open Frameworks 0071

I wanted to stream larger images streams across apps using UDP. 
To avoid the max packet size issue I broke down the texture into several "tiles" each tile texture data gets broadcasted with it's own port and combines to form the larger image.

There's probably a better way to do this with GStreamer, or SharedMemory or just using Syphon on Mac. 


Potential Solutions / Resources

https://github.com/soyoungshin/ofxGstStandaloneVideo
http://forum.openframeworks.cc/index.php/topic,3505.15.html
https://github.com/patriciogonzalezvivo/ofxKinectStreamer
