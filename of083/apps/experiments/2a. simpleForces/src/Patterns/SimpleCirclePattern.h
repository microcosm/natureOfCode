#pragma once

#include "ofMain.h"
#include "ofxAnimatableOfColor.h"

class SimpleCirclePattern {
    
public:
    void setup();
    void update();
    void draw();
    void setColor(ofColor _color);
    void animateToColor(ofColor _color);
    void setSize(int _size);
    void incrementSize();
    
protected:
    ofxAnimatableOfColor color;
    int size;
};