#include "SimpleCirclePattern.h"

void SimpleCirclePattern::setup() {
    ofSetCircleResolution(20);
    ofEnableSmoothing();
    color.setDuration(0.75);
    color.setCurve(SWIFT_GOOGLE);
}

void SimpleCirclePattern::update() {
    color.update(1.0f/ofGetFrameRate());
}

void SimpleCirclePattern::draw() {
    ofSetColor(color.getCurrentColor());
    ofCircle(0, 0, size);
}

void SimpleCirclePattern::setColor(ofColor _color) {
    color.setColor(_color);
}

void SimpleCirclePattern::animateToColor(ofColor _color) {
    color.animateTo(_color);
}

void SimpleCirclePattern::setSize(int _size) {
    size = _size;
}

void SimpleCirclePattern::incrementSize() {
    size *= 2;
}