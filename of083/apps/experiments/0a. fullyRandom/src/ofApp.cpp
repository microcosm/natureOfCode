#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = 1;
    max = 2;
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

//---------- Experiment 1: Objects appear randomly, overlapping
ofImage img1;

void ofApp::setupExp1(){
	img1.loadImage("1.png");
}

void ofApp::drawExp1(){
	for(int i = -100; i < ofGetWidth(); i += 100) {
        for(int j = -100; j < ofGetHeight(); j += 100) {
            if ((int)ofRandom(2) == 0) {
                img1.draw(i, j);
            }
        }
    }
}

//---------- Experiment 2: Objects appear randomly, non-overlapping
int w, h;

void ofApp::setupExp2() {
    w = img1.getWidth(); h = img1.getHeight();
}

void ofApp::drawExp2(){
    for(int i = -w; i < ofGetWidth() + w; i += w) {
        for(int j = -h; j < ofGetHeight() + h; j += h) {
            if ((int)ofRandom(2) == 0) {
                img1.draw(i, j);
            }
        }
    }
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
