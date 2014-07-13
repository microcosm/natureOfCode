#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	img.loadImage("1.png");
    w = img.getWidth();
    h = img.getHeight();
    current = 1;
    max = 2;
    ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    if(current == 1){
        runExp1();
    }
    if(current == 2){
        runExp2();
    }
	ofDisableAlphaBlending();
}

//------ Experiments
void ofApp::runExp1(){
	for(int i = -100; i < ofGetWidth(); i += 100) {
        for(int j = -100; j < ofGetHeight(); j += 100) {
            if ((int)ofRandom(2) == 0) {
                img.draw(i, j);
            }
        }
    }
}

void ofApp::runExp2(){
    for(int i = -w; i < ofGetWidth() + w; i += w) {
        for(int j = -h; j < ofGetHeight() + h; j += h) {
            if ((int)ofRandom(2) == 0) {
                img.draw(i, j);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(current < max){
        current++;
    } else {
        current = 1;
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
