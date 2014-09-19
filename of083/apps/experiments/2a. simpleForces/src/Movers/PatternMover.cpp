#include "PatternMover.h"

void PatternMover::setup() {
    Mover::setup();
    circle.setup();
    ofSetRectMode(OF_RECTMODE_CENTER);
}

void PatternMover::update() {
    Mover::update();
    circle.update();
}

void PatternMover::draw() {
    ofPushMatrix();
    Mover::draw();
    circle.draw();
    ofPopMatrix();
}

void PatternMover::setColor(ofColor _color) {
    circle.setColor(_color);
}

void PatternMover::animateToColor(ofColor _color) {
    circle.animateToColor(_color);
}

void PatternMover::setAnimationTime(float time) {
    circle.setAnimationTime(time);
}

void PatternMover::setSize(int size) {
    circle.setSize(size);
}

void PatternMover::incrementSize() {
    circle.incrementSize();
}