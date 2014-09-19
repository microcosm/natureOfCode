#include "SimpleCirclePattern.h"

void SimpleCirclePattern::setup() {
    ofSetCircleResolution(20);
    ofEnableSmoothing();
}

void SimpleCirclePattern::update() {
    
}

void SimpleCirclePattern::draw() {
    ofSetColor(color);
    ofCircle(0, 0, 20);
}

void SimpleCirclePattern::setColor(ofColor _color) {
    color = _color;
}