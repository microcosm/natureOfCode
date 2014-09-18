#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    interface.setup();
    interface.setMax(3);
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

//---------- Experiment 1: Constant Accelerators
vector <PatternMover> accelerators;
int numAccelerators;
float x, y;

void ofApp::setupExp1() {
    ofBackground(ofColor::black);
    numAccelerators = 8;
    accelerators.clear();
    
    for(int i = 0; i < numAccelerators; i++) {
        x = ofGetWidth() * (1.0 / (numAccelerators+1)) * (i+1);
        y = ofGetHeight() * 0.5;
        
        PatternMover mover;
        mover.setSize(1);
        mover.setup();
        mover.setLocation(x, y);
        mover.setAcceleration(0, 0.02 * (i+1));
        
        accelerators.push_back(mover);
    }
}

void ofApp::drawExp1() {
    for(int i = 0; i < numAccelerators; i++) {
        accelerators.at(i).update();
        accelerators.at(i).draw();
    }
}

//---------- Experiment 2: Random Accelerators
float mult;

void ofApp::setupExp2() {
    ofBackground(ofColor::black);
    numAccelerators = 5;
    accelerators.clear();
    
    for(int i = 0; i < numAccelerators; i++) {
        PatternMover mover;
        mover.setSize(ofMap(i, 0, numAccelerators, 0.2, 3));
        mover.setup();
        mover.setTopSpeed(ofMap(i, 0, numAccelerators, 1, 20));
        mover.setLocation(ofRandomWidth(), ofRandomHeight());
        accelerators.push_back(mover);
    }
}

void ofApp::drawExp2() {
    for(int i = 0; i < numAccelerators; i++) {
        mult = ofMap(i, 0, numAccelerators, 0.2, 0.7);
        accelerators.at(i).setAcceleration(ofRandom(-mult, mult), ofRandom(-mult, mult));
        accelerators.at(i).update();
        accelerators.at(i).draw();
    }
}

//---------- Experiment 3:
void ofApp::setupExp3() {
    ofBackground(ofColor::black);
    numAccelerators = 8;
    accelerators.clear();
    
    for(int i = 0; i < numAccelerators; i++) {
        PatternMover mover;
        mover.setSize(ofMap(i, 0, numAccelerators, 0.15, 1.2));
        mover.setup();
        mover.setTopSpeed(ofMap(i, 0, numAccelerators, 1, 20));
        mover.setLocation(ofRandomWidth(), ofRandomHeight());
        accelerators.push_back(mover);
    }
}

void ofApp::drawExp3() {
    for(int i = 0; i < numAccelerators; i++) {
        mult = ofMap(i, 0, numAccelerators, 1, 2);
        if(ofGetFrameNum() % 30 == 0) {
            accelerators.at(i).setColor(ofColor::red);
            accelerators.at(i).setAcceleration(ofRandom(-mult, mult), ofRandom(-mult, mult));
        } else {
            accelerators.at(i).setColor(ofColor::white);
        }
        accelerators.at(i).update();
        accelerators.at(i).draw();
    }
}

//---------- Experiment 4:
void ofApp::setupExp4() {
    
}

void ofApp::drawExp4() {
    
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
