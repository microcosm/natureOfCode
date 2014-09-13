#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void setLocation(float x, float y);
    void setAcceleration(float x, float y);
    
protected:
    void checkEdges();
    
    ofVec2f location, velocity, acceleration;
    int topspeed;
};