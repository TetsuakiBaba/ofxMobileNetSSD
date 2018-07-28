#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // cam
    video.setDeviceID( 0 );
    video.setDesiredFrameRate( 30 );
    video.initGrabber( 640, 480 );

    // MobileNetSSD Setting up
    ssd.setup(ofToDataPath("MobileNetSSD_deploy.prototxt"),
               ofToDataPath("MobileNetSSD_deploy.caffemodel"),
               ofToDataPath("names.txt"));

    ssd.setConfidenceThreshold(0.2);

}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if( video.isFrameNew() ){
        ssd.update(video.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    video.draw(0,0);
    ssd.draw(0,0,video.getWidth(), video.getHeight());
    ofDrawBitmapString(ofToString(ofGetFrameRate(), 0),20, 20);
}

void ofApp::keyPressed(int key)
{
}


