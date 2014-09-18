#pragma once

#include "Mover.h"
#include "CirclePattern.h"

class PatternMover : public Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void setSize(float _size);
    void setColor(ofColor _color);
    
protected:
    CirclePattern smallCircle, bigCircle, biggerCircle;
    ofColor color;
    float size;
};