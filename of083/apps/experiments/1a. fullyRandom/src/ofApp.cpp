#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = max = 4;
    ofToggleFullscreen();
    setupExp1();
    setupExp2();
    setupExp3();
    setupExp4();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    if(current == 1) { drawExp1(); }
    if(current == 2) { drawExp2(); }
    if(current == 3) { drawExp3(); }
    if(current == 4) { drawExp4(); }
	ofDisableAlphaBlending();
}

//---------- Experiment 1: Spread across the screen
ofImage img1;

void ofApp::setupExp1(){
	img1.loadImage("1.png");
}

void ofApp::drawExp1(){
	for(int i = -100; i < ofGetWidth(); i += 100) {
        for(int j = -100; j < ofGetHeight(); j += 100) {
            if ((int)ofRandom(2) == 0) {
                img1.draw(i, j);
            }
        }
    }
}

//---------- Experiment 2: Spatially ordered
int w, h;

void ofApp::setupExp2() {
    w = img1.getWidth(); h = img1.getHeight();
}

void ofApp::drawExp2(){
    for(int i = -w; i < ofGetWidth() + w; i += w) {
        for(int j = -h; j < ofGetHeight() + h; j += h) {
            if ((int)ofRandom(2) == 0) {
                img1.draw(i, j);
            }
        }
    }
}

//---------- Experiment 3: Pre-weighted image array
map<int, ofImage> imgs3;
ofImage img2, noImage;

void ofApp::setupExp3() {
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

void ofApp::drawExp3(){
	for(int i = -100; i < ofGetWidth(); i += 150) {
        for(int j = -100; j < ofGetHeight(); j += 150) {
            int index = (int)ofRandom(imgs3.size());
            imgs3[index].draw(i, j);
        }
    }
    ofSleepMillis(2000);
}

//---------- Experiment 4: More items in pre-weighted image array
map<int, ofImage> imgs4;
ofImage img3, img4, img5;

void ofApp::setupExp4() {
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

void ofApp::drawExp4(){
	for(int i = -100; i < ofGetWidth(); i += 150) {
        for(int j = -100; j < ofGetHeight(); j += 150) {
            int index = (int)ofRandom(imgs4.size());
            imgs4[index].draw(i, j);
        }
    }
    ofSleepMillis(200);
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
