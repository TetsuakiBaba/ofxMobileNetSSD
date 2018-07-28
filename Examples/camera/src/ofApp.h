#pragma once

#include "ofMain.h"
#include "ofxMobileNetSSD.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    ofVideoGrabber video;
    ofxMobileNetSSD ssd;
    
    void keyPressed(int key);
};
