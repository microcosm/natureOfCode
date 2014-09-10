#include "Mover.h"

void Mover::setup() {
    //Always use setup() for OF functions, such as ofRandom or ofGetWidth...
    //Never use a constructor
    //http://forum.openframeworks.cc/t/ofrandom-in-class-constructor-problem/16429
    location.set(ofRandomWidth(), ofRandomHeight());
    velocity.set(ofRandom(20) - 10, ofRandom(20) - 10);
}

void Mover::update() {
    location += velocity;
    if(ofGetFrameNum() % 25 == 0) {
        velocity.set(ofRandom(20) - 10, ofRandom(20) - 10);
    }
}

void Mover::draw() {
    ofFill();
    hue = fmodf(ofGetElapsedTimef() * 10, 255);
    color.setHsb(hue, 255, 255);
	ofSetColor(color);
    ofSetCircleResolution(50);
	ofCircle(location.x, location.y, 50);
}

void Mover::checkEdges() {
    if (location.x > ofGetWidth()) {
        location.x = 0;
    } else if (location.x < 0) {
        location.x = ofGetWidth();
    }
    
    if (location.y > ofGetHeight()) {
        location.y = 0;
    } else if (location.y < 0) {
        location.y = ofGetHeight();
    }
}