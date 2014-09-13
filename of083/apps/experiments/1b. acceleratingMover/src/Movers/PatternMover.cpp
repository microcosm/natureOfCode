#include "PatternMover.h"

void PatternMover::setup() {
    Mover::setup();
    
    smallCircle.setSize(ofGetWidth() * 0.08);
    smallCircle.setNumLines(2);
    smallCircle.setup();
    
    bigCircle.setSize(ofGetWidth() * 0.084);
    bigCircle.setNumLines(180);
    bigCircle.setup();
    
    biggerCircle.setSize(ofGetWidth() * 0.1);
    biggerCircle.setNumLines(4);
    biggerCircle.setup();
    
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