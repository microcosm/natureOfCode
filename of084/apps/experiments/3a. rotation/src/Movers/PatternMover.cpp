#include "PatternMover.h"

void PatternMover::setup() {
    Mover::setup();
    square.setup();
}

void PatternMover::update() {
    Mover::update();
    square.update();
}

void PatternMover::draw() {
    ofPushMatrix();
    Mover::draw();
    square.draw();
    ofPopMatrix();
}

void PatternMover::setColor(ofColor _color) {
    square.setColor(_color);
}

void PatternMover::animateToColor(ofColor _color) {
    square.animateToColor(_color);
}

void PatternMover::setAnimationTime(float time) {
    square.setAnimationTime(time);
}

void PatternMover::setSize(int size) {
    square.setSize(size);
}

float PatternMover::getSize() {
    return square.getSize();
}

void PatternMover::incrementSize() {
    square.incrementSize();
}