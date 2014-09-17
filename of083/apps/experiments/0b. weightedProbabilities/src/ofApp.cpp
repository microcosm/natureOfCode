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
    ofEnableAlphaBlending();
    if(current == 1) { drawExp1(); }
    if(current == 2) { drawExp2(); }
    if(current == 3) { drawExp3(); }
    if(current == 4) { drawExp4(); }
    ofDisableAlphaBlending();
    interface.draw();
}

//---------- Experiment 1: Two images with slim chances of appearing
map<int, ofImage> imgs3;
ofImage img1, img2, noImage;

void ofApp::setupExp1() {
	img1.loadImage("1.png");
    img2.loadImage("2.png");
    noImage.allocate(1, 1, OF_IMAGE_COLOR);
    imgs3[0]  = img1;
    imgs3[1]  = img2;
    imgs3[2]  = img2;
    imgs3[3]  = noImage;
    imgs3[4]  = noImage;
    imgs3[5]  = noImage;
    imgs3[6]  = noImage;
    imgs3[7]  = noImage;
    imgs3[8]  = noImage;
    imgs3[9]  = noImage;
    imgs3[10] = noImage;
}

void ofApp::drawExp1(){
    ofSetColor(ofColor::white);
	for(int i = -100; i < ofGetWidth(); i += 150) {
        for(int j = -100; j < ofGetHeight(); j += 150) {
            int index = (int)ofRandom(imgs3.size());
            imgs3[index].draw(i, j);
        }
    }
    ofSleepMillis(200);
}

//---------- Experiment 2: Five images, with better chances of appearing
map<int, ofImage> imgs4;
ofImage img3, img4, img5;

void ofApp::setupExp2() {
    img3.loadImage("3.png");
    img4.loadImage("4.png");
    img5.loadImage("5.png");
    imgs4[0]  = img1;
    imgs4[1]  = img2;
    imgs4[2]  = img3;
    imgs4[3]  = img4;
    imgs4[4]  = img5;
    imgs4[5]  = img1;
    imgs4[6]  = noImage;
    imgs4[7]  = noImage;
    imgs4[8]  = noImage;
    imgs4[9]  = noImage;
    imgs4[10] = noImage;
}

void ofApp::drawExp2(){
    ofSetColor(ofColor::white);
	for(int i = -100; i < ofGetWidth(); i += 150) {
        for(int j = -100; j < ofGetHeight(); j += 150) {
            int index = (int)ofRandom(imgs4.size());
            imgs4[index].draw(i, j);
        }
    }
    ofSleepMillis(200);
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
