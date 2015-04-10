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

//---------- Experiment 1:
vector <PatternMover> movers;
int numMovers;
ofVec2f gravity;
float x, y, weight, minX, maxX, minWeight, maxWeight;
ofColor color;

void ofApp::setupExp1() {
    interface.initText("Differently-sized balls\noperating according to\nnewton's second law,\nbut not taking into\naccount the effect of\ngravity on weight.\n\n(w = m * g)");

    ofBackground(ofColor::black);
    ofSetBackgroundAuto(true);
    numMovers = 20;
    movers.clear();
    gravity = ofVec2f(0, 4.5);
    
    for(int i = 0; i < numMovers; i++) {
        minX = ofGetWidth()  * 0.01;
        maxX = ofGetWidth()  * 0.99;
        
        minWeight = ofGetWidth() * 0.002;
        maxWeight = ofGetWidth() * 0.025;
        
        x = ofRandom(minX, maxX);
        y = 0.5;
        weight = ofRandom(minWeight, maxWeight);
        
        color = ofColor::fromHsb(ofRandom(0, 255), 255, 255);
        
        PatternMover mover;
        mover.setup();
        mover.setColor(color);
        mover.setSize(weight);
        mover.setMass(weight);
        mover.setLocation(x, y);
        movers.push_back(mover);
    }
}

void ofApp::drawExp1() {
    for(int i = 0; i < numMovers; i++) {
        //Note - applyForce
        movers.at(i).applyForce(gravity);
        movers.at(i).update();
        movers.at(i).draw();
    }
}

//---------- Experiment 2:
void ofApp::setupExp2() {
    interface.initText("Differently-sized balls\noperating according to\nnewton's second law,\nbut now taking into\naccount the effect of\ngravity on weight.\n\n(w = m * g)");
    
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(true);
    numMovers = 20;
    movers.clear();
    gravity = ofVec2f(0, 0.5);
    
    for(int i = 0; i < numMovers; i++) {
        minX = ofGetWidth()  * 0.01;
        maxX = ofGetWidth()  * 0.99;
        
        minWeight = ofGetWidth() * 0.002;
        maxWeight = ofGetWidth() * 0.025;
        
        x = ofRandom(minX, maxX);
        y = 0.5;
        weight = ofRandom(minWeight, maxWeight);
        
        color = ofColor::fromHsb(ofRandom(0, 255), 255, 255);
        
        PatternMover mover;
        mover.setup();
        mover.setColor(color);
        mover.setSize(weight);
        mover.setMass(weight);
        mover.setLocation(x, y);
        movers.push_back(mover);
    }
}

void ofApp::drawExp2() {
    for(int i = 0; i < numMovers; i++) {
        //Note - applyGravity
        movers.at(i).applyGravity(gravity);
        movers.at(i).update();
        movers.at(i).draw();
    }
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
