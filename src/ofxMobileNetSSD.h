#pragma once

#include "ofMain.h"
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace cv;
using namespace cv::dnn;

std::string Replace( std::string String1, std::string String2, std::string String3 );
bool doesIncludeExtensions(string _filename, vector<string>_extensions);

class TrainObject{
public:
    TrainObject(int _id, string _name, ofRectangle _r){
        id = _id;
        name = _name;
        r.set(_r);
    }
    ~TrainObject(){
        
    }
    int id;
    string name;
    ofRectangle r;
    ofRectangle getScaledBB(float _w, float _h);
};

class Object{
public:
    Object(int _class_id, string _name, float _p, float _x, float _y, float _w, float _h);
    ~Object();
    ofRectangle r;
    ofRectangle getScaledBB(float _w, float _h);
    string name;
    float p;
    int class_id;
};

class ofxMobileNetSSD{
public:
    ofxMobileNetSSD();
    ~ofxMobileNetSSD();
    void setup(string _path_to_cfg, string _path_to_weights, string _path_to_names);
    void draw(float _x, float _y, float _w, float _h);
    void drawAnnotation(float _x, float _y, float _w, float _h);
    void update(ofPixels &op);
    void setConfidenceThreshold(float _threshold);

    void setNextAnnotation();
    void setPreviousAnnotation();
    
    void loadAnnotationDir(string _path_to_file);
    void loadAnnotationImage(string _path_to_file);
    void loadBoundingBoxFile(string _path_to_file);
    void saveAnnotation();
    void saveBoundingBoxToFile(string _path_to_file);

    void drawClassSelector(float _x, float _y, int _row);
    void addTrainObject(ofRectangle _r);
    
    vector<Object> object;
    vector<TrainObject>train;
    
    cv::Mat toCV(ofPixels &pix);
    dnn::Net net;
    int network_width = 300;
    int network_height = 300;
    vector<string> classNamesVec;
    vector<ofColor> detection_color;
    float confidenceThreshold;
    ofTrueTypeFont font_info;

    string filename;
    string filename_jpg;
    string filename_txt;
    string filepath;
    ofDirectory dir_annotation;
    int pos_annotation_file;
    ofImage image_annotation;
    int class_id_selected;

};
