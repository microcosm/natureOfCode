#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = last = max = 2;
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

//---------- Experiment 1: Constant Accelerators
vector <PatternMover> constantAccelerators;
int numConstantAccelerators;
float x, y;

void ofApp::setupExp1() {
    numConstantAccelerators = 8;
    constantAccelerators.clear();
    
    for(int i = 0; i < numConstantAccelerators; i++) {
        x = ofGetWidth() * (1.0 / (numConstantAccelerators+1)) * (i+1);
        y = ofGetHeight() * 0.5;
        
        PatternMover mover;
        mover.setSize(1);
        mover.setup();
        mover.setLocation(x, y);
        mover.setAcceleration(0, 0.02 * (i+1));
        
        constantAccelerators.push_back(mover);
    }
}

void ofApp::drawExp1() {
    for(int i = 0; i < numConstantAccelerators; i++) {
        constantAccelerators.at(i).update();
        constantAccelerators.at(i).draw();
    }
}

//---------- Experiment 2: Random Accelerators
vector <PatternMover> randomAccelerators;
int numRandomAccelerators;
float mult;

void ofApp::setupExp2() {
    numRandomAccelerators = 5;
    randomAccelerators.clear();
    
    for(int i = 0; i < numRandomAccelerators; i++) {
        PatternMover mover;
        mover.setSize(ofMap(i, 0, numRandomAccelerators, 0.2, 3));
        mover.setup();
        mover.setTopSpeed(ofMap(i, 0, numRandomAccelerators, 1, 20));
        mover.setLocation(ofRandomWidth(), ofRandomHeight());
        randomAccelerators.push_back(mover);
    }
}

void ofApp::drawExp2() {
    for(int i = 0; i < numRandomAccelerators; i++) {
        mult = ofMap(i, 0, numRandomAccelerators, 0.2, 0.7);
        randomAccelerators.at(i).setAcceleration(ofRandom(-mult, mult), ofRandom(-mult, mult));
        randomAccelerators.at(i).update();
        randomAccelerators.at(i).draw();
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
