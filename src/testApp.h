#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//K-Camera Initiation
		ofVideoGrabber cam;
		int camWidth;
		int camHeight;
		int smallWidth;
		int smallHeight;
		

		//K-Image Variables declared
		ofImage thresh;
		ofImage highpass;
		ofImage amplify;
		ofImage smooth;
		ofImage camera;

		//K-Initializing the font variables
		ofTrueTypeFont myFont;

		//K-Initializing the Graphic User Interface
		ofxUICanvas *gui;
		void guiEvent(ofxUIEventArgs &e);

		float thresholdValue;
};
