#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    void update();
    void draw();
    void checkEdges();
    
protected:
    ofVec2f location;
    ofVec2f velocity;
    float hue;
    ofColor color;
};