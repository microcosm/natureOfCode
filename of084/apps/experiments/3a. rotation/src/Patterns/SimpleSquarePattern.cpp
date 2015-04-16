#include "SimpleSquarePattern.h"

void SimpleSquarePattern::setup() {
    ofEnableSmoothing();
    setAnimationTime(0.5);
    color.setCurve(SWIFT_GOOGLE);
}

void SimpleSquarePattern::update() {
    float dt = 1.0f/ofGetFrameRate();
    color.update(dt);
    size.update(dt);
}

void SimpleSquarePattern::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(color.getCurrentColor());
    ofRect(0, 0, size, size);
}

void SimpleSquarePattern::setColor(ofColor _color) {
    color.setColor(_color);
}

void SimpleSquarePattern::setAnimationTime(float time) {
    color.setDuration(time);
    size.setDuration(time);
}

void SimpleSquarePattern::animateToColor(ofColor _color) {
    color.animateTo(_color);
}

void SimpleSquarePattern::setSize(float _size) {
    size.reset(_size);
}

float SimpleSquarePattern::getSize() {
    return size.getCurrentValue();
}

void SimpleSquarePattern::incrementSize() {
    size.animateToIfFinished(size.getCurrentValue() * 2);
}