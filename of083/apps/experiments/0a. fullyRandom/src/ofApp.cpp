#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    interface.setup();
    interface.setMax(2);
    interface.enableBackground();
    interface.invertColors();
    current = interface.getCurrent();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(interface.changed()) {
        current = interface.getCurrent();
        if(current == 1) { setupExp1(); }
        if(current == 2) { setupExp2(); }
        if(current == 3) { setupExp3(); }
        if(current == 4) { setupExp4(); }
    }
    interface.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(current == 1) { drawExp1(); }
    if(current == 2) { drawExp2(); }
    if(current == 3) { drawExp3(); }
    if(current == 4) { drawExp4(); }
    interface.draw();
}

//---------- Experiment 1: Objects appear randomly, overlapping
ofImage img1;

void ofApp::setupExp1(){
	img1.loadImage("1.png");
}

void ofApp::drawExp1(){
    ofSetColor(ofColor::white);
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
    ofSetColor(ofColor::white);
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
    interface.keyPressed(key);
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
