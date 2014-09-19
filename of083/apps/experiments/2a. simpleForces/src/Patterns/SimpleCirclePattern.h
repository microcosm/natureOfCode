#pragma once

#include "ofMain.h"
#include "ofxAnimatableOfColor.h"

class SimpleCirclePattern {
    
public:
    void setup();
    void update();
    void draw();
    void setColor(ofColor _color);
    
protected:
    ofColor color;
};