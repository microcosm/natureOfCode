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
    if(current == 1) { drawExp1(); }
    if(current == 2) { drawExp2(); }
    if(current == 3) { drawExp3(); }
    if(current == 4) { drawExp4(); }
}

//---------- Experiment 1:
void ofApp::setupExp1(){

}

void ofApp::drawExp1(){

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
