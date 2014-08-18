#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = max = 1;
    ofToggleFullscreen();
    setupExp1();
    setupExp2();
    setupExp3();
    setupExp4();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    if(current == 1) { drawExp1(); }
    if(current == 2) { drawExp2(); }
    if(current == 3) { drawExp3(); }
    if(current == 4) { drawExp4(); }
	ofDisableAlphaBlending();
}

//---------- Experiment 1:
map<int, int> normals;
int xMultiplier, yMultiplier, yPosition;

void ofApp::setupExp1(){
    
    //Init the array
    for(int i = 0; i < 500; i++) {
        normals[i] = 0;
    }
    
    //Figure out draw values
    yPosition = ofGetHeight() - (ofGetHeight() / 10);
    xMultiplier = ofGetWidth() / 500;
    yMultiplier = (ofGetHeight() - (yMultiplier * 2)) / 300;
    cout << yMultiplier << "\n";
}

void ofApp::drawExp1(){
    
    //Add a new normal each frame
    float normal = nextGaussian(50, 250);
    normals[normal] += yMultiplier;
    
    //Re-draw
    ofBackgroundGradient(ofColor::mediumAquaMarine, ofColor::maroon, OF_GRADIENT_LINEAR);
    ofSetColor(ofColor::white);
    
    for(int i = 0; i < 500; i++) {
        ofRect(i * xMultiplier, yPosition, xMultiplier, -normals[i]);
    }
}

//---------- Experiment 2:
void ofApp::setupExp2() {

}

void ofApp::drawExp2(){

}

//---------- Experiment 3:
void ofApp::setupExp3() {

}

void ofApp::drawExp3(){

}

//---------- Experiment 4:
void ofApp::setupExp4() {
    
}

void ofApp::drawExp4(){

}

//Adapted from andyr0id/ofxGaussian
bool haveNextGaussian = false;
float theNextGaussian;

float ofApp::nextGaussian() {
    if (haveNextGaussian){
        haveNextGaussian = false;
        return theNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        theNextGaussian = v2 * multiplier;
        haveNextGaussian = true;
        
        return v1 * multiplier;
    }
}

float ofApp::nextGaussian(float sd, float mean) {
    
    return sd * nextGaussian() + mean;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'n')
    {
        if(current < max){
            current++;
        } else {
            current = 1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
