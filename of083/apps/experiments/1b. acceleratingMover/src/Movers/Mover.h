#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void setLocation(float x, float y);
    void setVelocityMultiplier(int mult);
    void setChangeFreq(int frames);
    
protected:
    void checkEdges();
    void newRandomVelocity();
    
    ofVec2f location, velocity;
    int velocityMultiplier;
    int changeFreq;
};