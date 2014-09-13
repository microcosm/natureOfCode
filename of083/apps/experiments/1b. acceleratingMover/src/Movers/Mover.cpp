#include "Mover.h"

void Mover::setup() {
    location.set(ofRandomWidth(), ofRandomHeight());
    setVelocityMultiplier(20);
    setChangeFreq(25);
    newRandomVelocity();
}

void Mover::update() {
    location += velocity;
    if(ofGetFrameNum() % changeFreq == 0) {
        newRandomVelocity();
    }
    checkEdges();
}

void Mover::draw() {
    ofTranslate(location.x, location.y);
}

void Mover::setLocation(float x, float y) {
    location.set(x, y);
}

void Mover::setVelocityMultiplier(int mult) {
    velocityMultiplier = mult;
}

void Mover::setChangeFreq(int frames) {
    changeFreq = frames;
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

void Mover::newRandomVelocity() {
    int randomX = ofRandom(velocityMultiplier) - velocityMultiplier * 0.5;
    int randomY = ofRandom(velocityMultiplier) - velocityMultiplier * 0.5;
    velocity.set(randomX, randomY);
}