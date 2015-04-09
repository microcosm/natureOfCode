#pragma once

#include "Mover.h"

class CircleMover : public Mover {
    
public:
    void draw();
    
protected:
    float hue;
    ofColor color;
};