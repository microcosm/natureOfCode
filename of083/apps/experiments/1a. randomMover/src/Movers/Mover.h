#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    void setLocation(float x, float y);
    void setVelocityMultiplier(int mult);
    void setChangeFreq(int frames);
    void update();
    void checkEdges();
    
protected:
    void newRandomVelocity();
    ofVec2f location;
    ofVec2f velocity;
    int velocityMultiplier;
    int changeFreq;
};