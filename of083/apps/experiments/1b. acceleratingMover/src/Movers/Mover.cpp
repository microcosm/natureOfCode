#include "Mover.h"

void Mover::setup() {
    topspeed = 1000;
    setLocation(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    setAcceleration(0, 0.02);
}

void Mover::update() {
    velocity += acceleration;
    velocity.limit(topspeed);
    location += velocity;
    checkEdges();
}

void Mover::draw() {
    ofTranslate(location.x, location.y);
}

void Mover::setTopSpeed(int speed) {
    topspeed = speed;
}

void Mover::setLocation(float x, float y) {
    location.set(x, y);
}

void Mover::setAcceleration(float x, float y) {
    acceleration.set(x, y);
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