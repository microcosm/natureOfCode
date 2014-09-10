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

//---------- Experiment 1:
Mover mover;

void ofApp::setupExp1() {
    ofBackground(ofColor::black);
    //ofClear(ofColor::black);
    ofSetBackgroundAuto(false);
    mover.setup();
}

void ofApp::drawExp1() {
    mover.update();
    mover.draw();
}

//---------- Experiment 2:
vector <Mover> movers; //A little confusing in this context, but a vector is just a C++ array

void ofApp::setupExp2() {
    ofBackground(ofColor::black);
    ofClear(ofColor::black);
    ofSetBackgroundAuto(false);
    
    movers.clear();
    
    Mover mover;
    float x, y, xincrement, yincrement;
    int xcount, ycount;
    
    xcount = 18;
    ycount = 6;
    xincrement = ofGetWidth()  / (xcount + 1);
    yincrement = ofGetHeight() / (ycount + 1);
    
    for(int xi = 1; xi <= xcount; xi++) {
        for(int yi = 1; yi <= ycount; yi++) {
            x = xincrement * xi;
            y = yincrement * yi;
            
            mover.setLocation(x, y);
            movers.push_back(mover);
        }
    }
}

void ofApp::drawExp2() {
    for(int i = 0; i < movers.size(); i++) {
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
