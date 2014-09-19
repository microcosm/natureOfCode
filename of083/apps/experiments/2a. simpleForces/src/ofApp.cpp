#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    interface.setup();
    interface.setMax(2);
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

//---------- Experiment 1:
vector <PatternMover> movers;
int numMovers;
ofVec2f initial, gravity;
ofColor color;
float x, y, minX, maxX, minY, maxY;

void ofApp::setupExp1() {
    ofBackground(ofColor::black);
    numMovers = 50;
    movers.clear();
    gravity = ofVec2f(0, 0.2);
    
    for(int i = 0; i < numMovers; i++) {
        minX = ofGetWidth()  * 0.495;
        maxX = ofGetWidth()  * 0.505;
        x = ofRandom(minX, maxX);
        
        minY = ofGetHeight() * 0;
        maxY = ofGetHeight() * 0.7;
        y = ofRandom(minY, maxY);
        
        color.setHsb(     ofMap(y, minY, maxY, 0, 70), 255, 255);
        initial = ofVec2f(ofMap(x, minX, maxX, -4, 4), 0);
        
        PatternMover mover;
        mover.setup();
        mover.setColor(color);
        mover.applyForce(initial);
        mover.setLocation(x, y);
        movers.push_back(mover);
    }
}

void ofApp::drawExp1() {
    for(int i = 0; i < numMovers; i++) {
        movers.at(i).applyForce(gravity);
        movers.at(i).update();
        movers.at(i).draw();
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
