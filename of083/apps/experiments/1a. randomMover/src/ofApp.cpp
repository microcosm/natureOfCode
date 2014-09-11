#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    current = last = max = 4;
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
CircleMover circle;

void ofApp::setupExp1() {
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false);
    circle.setup();
}

void ofApp::drawExp1() {
    circle.update();
    circle.draw();
}

//---------- Experiment 2:
vector <CircleMover> circles; //A little confusing in this context, but a vector is just a C++ array

void ofApp::setupExp2() {
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false);
    circles.clear();
    
    CircleMover circle;
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
            
            circle.setup();
            circle.setLocation(x, y);
            circles.push_back(circle);
        }
    }
}

void ofApp::drawExp2() {
    for(int i = 0; i < circles.size(); i++) {
        circles.at(i).update();
        circles.at(i).draw();
    }
}

//---------- Experiment 3:
VideoMover video;

void ofApp::setupExp3() {
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false);
    ofSetColor(ofColor::white);
    
    video.load("Ssangyong.mp4");
    video.setup();
    video.setVelocityMultiplier(10);
    video.setChangeFreq(120);
}

void ofApp::drawExp3() {
    video.update();
    video.draw();
}

//---------- Experiment 4:
vector <VideoMover> videos;
int velocityMultiplier, numVideosToShow, maxVideosToShow = 10;

void ofApp::setupExp4() {
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false);
    
    videos.clear();
    velocityMultiplier = 10;
    numVideosToShow = 1;
    
    for(int i = 0; i < maxVideosToShow; i++) {
        pushNewVideo();
    }
}

void ofApp::drawExp4() {
    if(ofGetFrameNum() > 1 && ofGetFrameNum() % 300 == 0) {
        numVideosToShow++;
    }
    
    if(numVideosToShow > maxVideosToShow) {
        numVideosToShow = 1;
    }
    
    for(int i = 0; i < numVideosToShow; i++) {
        videos.at(i).update();
        videos.at(i).draw();
    }
}

void ofApp::pushNewVideo() {
    VideoMover video;
    video.load("Ssangyong.mp4");
    video.setup();
    video.setVelocityMultiplier(velocityMultiplier += 10);
    videos.push_back(video);
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
