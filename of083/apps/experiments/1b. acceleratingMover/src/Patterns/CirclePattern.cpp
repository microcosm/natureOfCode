#include "CirclePattern.h"

void CirclePattern::setup() {
#ifdef TARGET_OPENGLES
    maskingShader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        maskingShader.load("shadersGL3/shader");
    } else {
        maskingShader.load("shadersGL2/shader");
    }
#endif
    
    setTransparent(false);
    setColorChangeMode(COLOR_CHANGE_IMMEDIATE);
    setColor(ofColor::white);
    setLineThickness(1);
    
    color.setDuration(0.5);
    color.setCurve(SWIFT_GOOGLE);
    
    ofSetCircleResolution(halfFboSize);
    ofEnableSmoothing();
    
    init(maskFbo);
    init(maskedFbo);
}

void CirclePattern::update() {
    color.update(1.0f/ofGetFrameRate());
    drawMaskedFbo();
    drawMaskFbo();
}

void CirclePattern::draw() {
    ofSetColor(255); //This wipes out the influence of previous ofSetColor() calls
    maskingShader.begin();
    maskingShader.setUniformTexture("maskTex", maskFbo.getTextureReference(), 1);
    maskedFbo.draw(0, 0);
    maskingShader.end();
}

void CirclePattern::setSize(int _size) {
    fboSize = _size;
    halfFboSize = fboSize * 0.5;
}

void CirclePattern::setColor(ofColor _color) {
    switch(colorChangeMode){
        case COLOR_CHANGE_IMMEDIATE:
            color.setColor(_color);
            break;
        case COLOR_CHANGE_SLOW:
            color.animateToIfFinished(_color);
            break;
    }
}

void CirclePattern::setColorChangeMode(int mode) {
    colorChangeMode = mode;
}

void CirclePattern::setTransparent(bool _transparent) {
    transparent = _transparent;
}

void CirclePattern::setLineThickness(float thickness) {
    lineThickness = thickness;
}

void CirclePattern::setNumLines(int _numLines) {
    numLines = _numLines;
}

void CirclePattern::init(ofFbo &fbo) {
    fbo.allocate(fboSize, fboSize, GL_RGBA, 4);
    /*fbo.begin();
    ofClear(255, 255, 255, alpha);
    fbo.end();*/
}

void CirclePattern::drawMaskedFbo() {
    maskedFbo.begin();
    clearFbo();
    ofSetColor(color.getCurrentColor());
    ofSetLineWidth(lineThickness);
    for(int i = 0; i < numLines; i++) {
        ofLine(ofRandom(fboSize), ofRandom(fboSize), ofRandom(fboSize), ofRandom(fboSize));
    }
    maskedFbo.end();
}

void CirclePattern::drawMaskFbo() {
    maskFbo.begin();
    ofClear(ofColor::black);
    ofSetColor(ofColor::white);
    
    ofCircle(halfFboSize, halfFboSize, halfFboSize);
    maskFbo.end();
}

void CirclePattern::clearFbo() {
    if(transparent) {
        ofClear(255, 255, 255, 0);
    } else {
        ofClear(0, 0, 0, 255);
    }
}