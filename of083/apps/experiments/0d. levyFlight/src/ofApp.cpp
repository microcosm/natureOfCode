#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    interface.setup();
    interface.setMax(1);
    interface.invertColors();
    interface.enableBackground();
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
ofxAnimatableFloat x, y;
float xStep, yStep, midX, midY;
float regularStepSize, largeStepSize;
int ballSize, halfBallSize;

void ofApp::setupExp1(){
    
    //Figure out the screen
    midX = ofGetWidth() * 0.5;
    midY = ofGetHeight() * 0.5;
    
    regularStepSize = ofGetHeight() * 0.03;
    largeStepSize = ofGetHeight() * 0.2;
    
    //Set up animation behaviour
    x.setCurve(EASE_IN_EASE_OUT);
    y.setCurve(EASE_IN_EASE_OUT);
    
    x.setRepeatType(PLAY_ONCE);
    y.setRepeatType(PLAY_ONCE);
    
    x.setDuration(0.5);
    y.setDuration(0.5);
    
    //The ball
    ballSize = 10;
    halfBallSize = ballSize * 0.5;
    currentColor = ofColor::white;
}

void ofApp::drawExp1(){
    
    //Update animation
    float dt = 1.0f / ofGetFrameRate();
    x.update(dt);
    y.update(dt);
    
    //Next animation...
    if(x.hasFinishedAnimating() && y.hasFinishedAnimating()) {
        
        //Center the ball if it went offscreen
        if(midX + x.val() > ofGetWidth() + halfBallSize ||
           midY + y.val() > ofGetHeight() + halfBallSize ||
           midX + x.val() < -halfBallSize ||
           midY + y.val() < -halfBallSize) {
            currentColor = ofColor::red;
            x.animateTo(0);
            y.animateTo(0);
        } else {
            //Take a new step
            xStep = ofRandom(2) - 1;
            yStep = ofRandom(2) - 1;
            
            if (ofRandom(1) < 0.1) {
                currentColor = ofColor::purple;
                x.animateTo(x.val() + xStep * largeStepSize);
                y.animateTo(y.val() + yStep * largeStepSize);
            } else {
                currentColor = ofColor::white;
                x.animateTo(x.val() + xStep * regularStepSize);
                y.animateTo(y.val() + yStep * regularStepSize);
            }
            
        }
    }
    
    //Draw
    ofSetBackgroundColor(ofColor::black);
    ofSetColor(currentColor);
    ofCircle(midX + x.val(), midY + y.val(), ballSize);
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
