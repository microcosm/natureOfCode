#pragma once

#include "Mover.h"
#include "SimpleCirclePattern.h"
#include "ofxAnimatableOfColor.h"

class PatternMover : public Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void setColor(ofColor _color);
    
protected:
    SimpleCirclePattern circle;
};