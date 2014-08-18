#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = 1;
    max = 3;
    ofToggleFullscreen();
    setupExp1();
    setupExp2();
    setupExp3();
    setupExp4();
}

//--------------------------------------------------------------
void ofApp::update(){
    changed = prev != current;
    prev = current;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    if(current == 1) { if(changed) { setupExp1(); } drawExp1(); }
    if(current == 2) { if(changed) { setupExp2(); } drawExp2(); }
    if(current == 3) { if(changed) { setupExp3(); } drawExp3(); }
    if(current == 4) { if(changed) { setupExp4(); } drawExp4(); }
	ofDisableAlphaBlending();
}

//---------- Experiment 1: A 1D incrementing array of normalised values
map<int, int> normalisedIntCount;
int xMultiplier, yMultiplier, yPosition;

void ofApp::setupExp1(){
    
    //Init the array
    for(int i = 0; i < 500; i++) {
        normalisedIntCount[i] = 0;
    }
    
    //Figure out draw values
    yPosition = ofGetHeight() - (ofGetHeight() / 10);
    xMultiplier = ofGetWidth() / 500;
    yMultiplier = (ofGetHeight() - (yMultiplier * 2)) / 300;
}

void ofApp::drawExp1(){
    
    //Add a new normal each frame
    float normal = nextGaussian(50, 250);
    normalisedIntCount[normal] += 1;
    
    //Re-draw
    ofBackgroundGradient(ofColor::mediumAquaMarine, ofColor::maroon, OF_GRADIENT_LINEAR);
    ofSetColor(ofColor::white);
    
    for(int i = 0; i < 500; i++) {
        ofRect(i * xMultiplier, yPosition, xMultiplier, -normalisedIntCount[i] * yMultiplier);
    }
}

//---------- Experiment 2: A 2D incrementing array of normalised values
map<vec2Key, int> normalisedVectorCount;
int alphaMultiplier;

void ofApp::setupExp2() {
    
    //Init the array
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            normalisedVectorCount[vec2Key(i,j)] = 0;
        }
    }
    
    //Assign drawing values
    alphaMultiplier = 25;
    xMultiplier = ofGetWidth() / 500;
    yMultiplier = ofGetHeight() / 500;
}

void ofApp::drawExp2(){
    
    //Add new normals each frame
    for(int i = 0; i < 500; i++){
        int normalX = nextGaussian(50, 250);
        int normalY = nextGaussian(50, 250);
        normalisedVectorCount[vec2Key(normalX, normalY)] += 1;
    }
        
    //Re-draw
    ofBackgroundGradient(ofColor::maroon, ofColor::mediumAquaMarine, OF_GRADIENT_CIRCULAR);
    
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            vec2Key vector = vec2Key(i, j);
            int alpha = ofClamp(normalisedVectorCount[vector] * alphaMultiplier, 0, 255);
            ofSetColor(ofColor(255, 255, 255, alpha));
            ofRect(i * xMultiplier, j * yMultiplier, xMultiplier, yMultiplier);
        }
    }
}

//---------- Experiment 3: Same as Experiment 1, but animated
map<int, ofxAnimatableFloat> heights;
int numNormals;

void ofApp::setupExp3(){
    
    numNormals = 100;
    
    //Init the array
    ofxAnimatableFloat f;
	f.setDuration(0.8);
    f.setCurve(EASE_OUT);
    
    for(int i = 0; i < numNormals; i++) {
        heights[i] = f;
    }
    
    //Figure out draw values
    yPosition = ofGetHeight() - (ofGetHeight() / 10);
    xMultiplier = ofGetWidth() / numNormals;
    yMultiplier = (ofGetHeight() - (yMultiplier * 2)) / 100;
}

void ofApp::drawExp3(){
    
    //Add a new normal each frame
    float normal = nextGaussian(numNormals * 0.1, numNormals * 0.5);
    heights[normal].animateTo(heights[normal].val() + 1 * yMultiplier);
    
    //Re-draw
    ofBackgroundGradient(ofColor::purple, ofColor::blue, OF_GRADIENT_LINEAR);
    ofSetColor(ofColor::white);
    float dt = 1.0f / ofGetFrameRate();
    
    for(int i = 0; i < numNormals; i++) {
        heights[i].update(dt);
        ofRect(i * xMultiplier, yPosition, xMultiplier, -heights[i].val());
    }
}

//---------- Experiment 4:
void ofApp::setupExp4() {
    
}

void ofApp::drawExp4(){

}

//Adapted from andyr0id/ofxGaussian
bool haveNextGaussian = false;
float theNextGaussian;

float ofApp::nextGaussian() {
    if (haveNextGaussian){
        haveNextGaussian = false;
        return theNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        theNextGaussian = v2 * multiplier;
        haveNextGaussian = true;
        
        return v1 * multiplier;
    }
}

float ofApp::nextGaussian(float sd, float mean) {
    
    return sd * nextGaussian() + mean;
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
