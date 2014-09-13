#pragma once

#include "Mover.h"
#include "CirclePattern.h"

class PatternMover : public Mover {
    
public:
    void setup();
    void update();
    void draw();
    
protected:
    CirclePattern smallCircle, bigCircle, biggerCircle;
};