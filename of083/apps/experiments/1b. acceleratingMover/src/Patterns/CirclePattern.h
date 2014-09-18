#pragma once

#include "ofMain.h"
#include "ofxAnimatableOfColor.h"

#define COLOR_CHANGE_IMMEDIATE 1
#define COLOR_CHANGE_SLOW 2

class CirclePattern {
    
public:
    void setup();
    void update();
    void draw();
    
    void setNumLines(int _numLines);
    void setSize(int _size);
    void setColor(ofColor _color);
    void setColorChangeMode(int mode);
    void setTransparent(bool _transparent);
    void setLineThickness(float thickness);
    
protected:
    
    void init(ofFbo &fbo);
    void drawMaskFbo();
    void drawMaskedFbo();
    void clearFbo();
    
    ofShader maskingShader;
    ofFbo maskFbo, maskedFbo;
    ofxAnimatableOfColor color;
    int colorChangeMode;
    int fboSize, halfFboSize;
    int numLines;
    bool transparent;
    float lineThickness;
};