#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    interface.setup();
    interface.setMax(4);
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
bool firstTime;
float xAcceleration, yAcceleration;
ofColor color;

void ofApp::setupExp3() {
    ofBackground(ofColor::black);
    numAccelerators = 8;
    accelerators.clear();
    firstTime = true;
    
    for(int i = 0; i < numAccelerators; i++) {
        PatternMover mover;
        mover.setSize(ofMap(i, 0, numAccelerators, 0.15, 1.2));
        mover.setup();
        mover.setTopSpeed(ofMap(i, 0, numAccelerators, 1, 20));
        mover.setLineThickness(ofMap(i, 0, numAccelerators, 2, 200));
        mover.setLocation(ofRandomWidth(), ofRandomHeight());
        accelerators.push_back(mover);
    }
}

void ofApp::drawExp3() {
    xAcceleration = ofRandom(-1, 1);
    yAcceleration = ofRandom(-1, 1);
    
    for(int i = 0; i < numAccelerators; i++) {
        mult = ofMap(i, 0, numAccelerators, 1, 10);
        if(firstTime || ofGetFrameNum() % 60 == 0) {
            color.setHsb(ofRandom(0, 255), 255, 255);
            accelerators.at(i).setColorChangeMode(COLOR_CHANGE_SLOW);
            accelerators.at(i).setColor(color);
            accelerators.at(i).setAcceleration(xAcceleration * mult, yAcceleration * mult);
        }
        accelerators.at(i).update();
        accelerators.at(i).draw();
    }
    firstTime = false;
}

//---------- Experiment 4:
ofVec2f mouse;
float accelerationMultiplier;

void ofApp::setupExp4() {
    ofBackground(ofColor::black);
    numAccelerators = 5;
    accelerators.clear();
    firstTime = true;
    
    for(int i = 0; i < numAccelerators; i++) {
        color.setHsb(ofMap(i, 0, numAccelerators, 0, 255), 255, 255);
        
        PatternMover mover;
        mover.setSize(ofMap(i, 0, numAccelerators, 2, 0.5));
        mover.setup();
        mover.setColor(color);
        mover.setTopSpeed(ofMap(i, 0, numAccelerators, 40, 4));
        mover.setLineThickness(ofMap(i, 0, numAccelerators, 2, 50));
        mover.setLocation(ofRandomWidth(), ofRandomHeight());
        accelerators.push_back(mover);
    }
}

void ofApp::drawExp4() {
    mouse.set(ofGetMouseX(), ofGetMouseY());
    
    for(int i = 0; i < numAccelerators; i++) {
        mult = ofMap(i, 0, numAccelerators, 2, 1);
        accelerators.at(i).accelerateTowards(mouse, mult);
        accelerators.at(i).update();
        accelerators.at(i).draw();
    }
    firstTime = false;
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
