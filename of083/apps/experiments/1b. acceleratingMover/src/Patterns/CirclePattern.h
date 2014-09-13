#pragma once

#include "ofMain.h"

class CirclePattern {
    
public:
    void setup();
    void update();
    void draw();
    
    void setNumLines(int _numLines);
    void setSize(int _size);
    
protected:
    
    void init(ofFbo &fbo);
    void drawMaskFbo();
    void drawMaskedFbo();
    
    ofShader maskingShader;
    ofFbo maskFbo, maskedFbo;
    int fboSize, halfFboSize;
    int numLines;
};