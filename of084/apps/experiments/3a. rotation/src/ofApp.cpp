#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    interface.setup();
    interface.setMax(1);
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

//---------- Experiment 1:
vector <PatternMover> movers;
int numMovers;
ofVec2f gravity, wind;
float x, y, weight, minX, maxX, minWeight, maxWeight;
ofColor color;
float frictionCoefficient, frictionNormal;

void ofApp::setupExp1() {
    interface.initText("Boxes are blown from\nthe left, and rotate in\nthe direction they are\nmoving.\n\nThey bounce off the\nright. That's your lot\nmate.");

    ofBackground(ofColor::black);
    ofSetBackgroundAuto(true);
    numMovers = 10;
    movers.clear();
    
    gravity = ofVec2f(0, 4.5);
    wind = ofVec2f(1.5, 0);
    
    frictionCoefficient = 1;
    frictionNormal = 1;
    
    for(int i = 0; i < numMovers; i++) {
        minX = ofGetWidth()  * 0.01;
        maxX = ofGetWidth()  * 0.99;
        
        minWeight = ofGetWidth() * 0.02;
        maxWeight = ofGetWidth() * 0.10;
        
        x = ofRandom(minX, maxX);
        y = ofMap(0.25, 0, 1, 0, ofGetHeight());
        weight = ofRandom(minWeight, maxWeight);
        
        color = ofColor::fromHsb(ofRandom(0, 255), 255, 255);
        
        PatternMover mover;
        mover.setup();
        mover.setColor(color);
        mover.setSize(weight);
        mover.setMass(weight / 10);
        mover.setLocation(x, y);
        movers.push_back(mover);
    }
}

void ofApp::drawExp1() {
    for(int i = 0; i < numMovers; i++) {
        //Note - applyForce
        movers.at(i).applyForce(gravity);
        movers.at(i).applyForce(wind);
        //Note - applyFriction
        //movers.at(i).applyFriction(frictionCoefficient, frictionNormal);
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
