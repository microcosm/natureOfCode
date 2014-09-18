#pragma once

#include "ofMain.h"

class CirclePattern {
    
public:
    void setup();
    void update();
    void draw();
    
    void setNumLines(int _numLines);
    void setSize(int _size);
    void setColor(ofColor _color);
    void setTransparent(bool _transparent);
    
protected:
    
    void init(ofFbo &fbo);
    void drawMaskFbo();
    void drawMaskedFbo();
    void clearFbo();
    
    ofShader maskingShader;
    ofFbo maskFbo, maskedFbo;
    ofColor color;
    int fboSize, halfFboSize;
    int numLines;
    bool transparent;
};