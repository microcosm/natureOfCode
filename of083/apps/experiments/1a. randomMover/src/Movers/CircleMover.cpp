#include "CircleMover.h"

void CircleMover::draw() {
    ofFill();
    hue = fmodf(ofGetElapsedTimef() * 10, 255);
    color.setHsb(hue, 255, 255);
    ofSetColor(color);
    ofSetCircleResolution(50);
    ofCircle(location.x, location.y, 50);
}