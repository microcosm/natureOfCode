#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = last = max = 1;
    ofToggleFullscreen();
    setupExp1();
    setupExp2();
    setupExp3();
    setupExp4();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(changed()) {
        if(current == 1) { setupExp1(); }
        if(current == 2) { setupExp2(); }
        if(current == 3) { setupExp3(); }
        if(current == 4) { setupExp4(); }
    }
    
    last = current;
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(current == 1) { drawExp1(); }
    if(current == 2) { drawExp2(); }
    if(current == 3) { drawExp3(); }
    if(current == 4) { drawExp4(); }
}

//---------- Experiment 1:
vector <PatternMover> patternMovers;
int numMovers = 8;
float x, y;

void ofApp::setupExp1() {
    for(int i = 0; i < numMovers; i++) {
        x = ofGetWidth() * (1.0 / (numMovers+1)) * (i+1);
        y = ofGetHeight() * 0.5;
        
        PatternMover patternMover;
        patternMover.setup();
        patternMover.setLocation(x, y);
        patternMover.setAcceleration(0, 0.02 * (i+1));
        
        patternMovers.push_back(patternMover);
    }
}

void ofApp::drawExp1() {
    for(int i = 0; i < numMovers; i++) {
        patternMovers.at(i).update();
        patternMovers.at(i).draw();
    }
}

//---------- Experiment 2:
void ofApp::setupExp2() {
    
}

void ofApp::drawExp2() {
    
}

//---------- Experiment 3:
void ofApp::setupExp3() {
    
}

void ofApp::drawExp3() {
    
}

//---------- Experiment 4:
void ofApp::setupExp4() {
    
}

void ofApp::drawExp4() {
    
}

//--------------------------------------------------------------
bool ofApp::changed() {
    return current != last;
}

void ofApp::keyPressed(int key){
    if(key == 'n') {
        last = current;
        
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
