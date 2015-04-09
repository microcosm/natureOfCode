#include "PatternMover.h"

void PatternMover::setup() {
    Mover::setup();
    
    smallCircle.setSize(ofGetWidth() * 0.08 * size);
    smallCircle.setNumLines(2);
    smallCircle.setup();
    
    bigCircle.setSize(ofGetWidth() * 0.084 * size);
    bigCircle.setNumLines(180);
    bigCircle.setup();
    
    biggerCircle.setSize(ofGetWidth() * 0.1 * size);
    biggerCircle.setNumLines(4);
    biggerCircle.setup();
    biggerCircle.setTransparent(true);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
}

void PatternMover::update() {
    Mover::update();
    
    smallCircle.update();
    bigCircle.update();
    biggerCircle.update();
}

void PatternMover::draw() {
    ofPushMatrix();
    
    Mover::draw();
    biggerCircle.draw();
    bigCircle.draw();
    smallCircle.draw();
    
    ofPopMatrix();
}

void PatternMover::setSize(float _size) {
    size = _size;
}

void PatternMover::setColor(ofColor _color) {
    smallCircle.setColor(_color);
    bigCircle.setColor(_color);
    biggerCircle.setColor(_color);
}


void PatternMover::setColorChangeMode(int mode) {
    smallCircle.setColorChangeMode(mode);
    bigCircle.setColorChangeMode(mode);
    biggerCircle.setColorChangeMode(mode);
}

void PatternMover::setLineThickness(float thickness) {
    smallCircle.setLineThickness(thickness);
    bigCircle.setLineThickness(thickness);
    biggerCircle.setLineThickness(thickness);
}