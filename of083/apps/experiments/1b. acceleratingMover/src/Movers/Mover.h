#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void setTopSpeed(int speed);
    void setLocation(float x, float y);
    void setAcceleration(float x, float y);
    void accelerateTowards(ofVec2f target, float multiplier);
    
protected:
    void checkEdges();
    
    ofVec2f location, velocity, acceleration;
    int topspeed;
};