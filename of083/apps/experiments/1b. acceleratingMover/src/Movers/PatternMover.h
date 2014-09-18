#pragma once

#include "Mover.h"
#include "CirclePattern.h"
#include "ofxAnimatableOfColor.h"

class PatternMover : public Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void setSize(float _size);
    void setColor(ofColor _color);
    void setColorChangeMode(int mode);
    void setLineThickness(float thickness);
    
protected:
    CirclePattern smallCircle, bigCircle, biggerCircle;
    float size;
};