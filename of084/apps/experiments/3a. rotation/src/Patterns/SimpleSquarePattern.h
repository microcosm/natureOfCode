#pragma once

#include "ofMain.h"
#include "ofxAnimatableOfColor.h"
#include "ofxAnimatableFloat.h"

class SimpleSquarePattern {
    
public:
    void setup();
    void update();
    void draw();
    void setColor(ofColor _color);
    void setAnimationTime(float time);
    void animateToColor(ofColor _color);
    void setSize(float _size);
    float getSize();
    void incrementSize();
    
protected:
    ofxAnimatableOfColor color;
    ofxAnimatableFloat size;
    float animationTime;
};