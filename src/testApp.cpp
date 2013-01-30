#include "testApp.h"
using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup(){
	//K-Initializing the Camera Parameters
	camWidth=320;
	camHeight=240;
	

	ofBackground(36,12,59);
	cam.initGrabber(camWidth,camHeight);

	camera.allocate(camWidth,camHeight,OF_IMAGE_GRAYSCALE);
	thresh.allocate(camWidth,camHeight, OF_IMAGE_GRAYSCALE);
	highpass.allocate(camWidth,camHeight,OF_IMAGE_GRAYSCALE);
	smooth.allocate(camWidth,camHeight,OF_IMAGE_GRAYSCALE);
	amplify.allocate(camWidth,camHeight,OF_IMAGE_GRAYSCALE);


	//Initialzing Font Parameters
	ofTrueTypeFont::setGlobalDpi(72);
	myFont.loadFont("newmedia.ttf", 20, true, true);
	myFont.setLineHeight(20.0f);
	myFont.setLetterSpacing(1.037);


	//K-Initializing the gui object and specifying the gui x,y co-ordinates as well as width and height
	left_panel = new ofxUICanvas(0,0,320,900);
	left_panel->addWidgetDown(new ofxUILabel("K Alligator Eye Control Panel", OFX_UI_FONT_LARGE));
	ofAddListener(left_panel->newGUIEvent, this, &testApp::guiEvent); 
	left_panel->loadSettings("GUI/guiSettings.xml");



	//Initialized a gui for the threshold video parameter
	thresh_panel=new ofxUICanvas(600,600,50,50);
	thresh_panel->addWidgetDown(new ofxUILabel("THRESHOLD PARAMETERS",OFX_UI_FONT_SMALL));
	thresh_panel->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"THRESHOLD VALUE"));
	ofAddListener(left_panel->newGUIEvent, this, &testApp::guiEvent);

}

//--------------------------------------------------------------
void testApp::update(){
	cam.update();
	if(cam.isFrameNew())
	{
		convertColor(cam, thresh, CV_RGB2GRAY);
		convertColor(cam,camera,CV_RGB2GRAY);
		threshold(thresh, thresholdValue);
		thresh.update();
		camera.update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	//K-Drawing the Camera
	camera.draw(360,60);

	thresh.draw(360,400);
	ofSetColor(225);
	myFont.drawString("Source Image", 360, 40);
	myFont.drawString("Tracked Image",700,40);
	
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

//-------------------------------------------------------------
void testApp::exit()
{
	left_panel->saveSettings("GUI/guiSettings.xml");     
    	delete left_panel;
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	if(e.widget->getName() == "THRESHOLD VALUE")	
    	{
        	ofxUISlider *slider = (ofxUISlider *) e.widget;    
        	thresholdValue = slider->getScaledValue();
	}
	
}
