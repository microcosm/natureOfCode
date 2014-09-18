#pragma once

#include "ofMain.h"

class ofxExperimentInterface {
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void setMax(int _max);
    void setCurrent(int _current);
    void enableBackground();
    void invertColors();
    bool changed();
    int getCurrent();
    
protected:
    void drawBackground();
    void drawText();
    
    int current, last, max;
    bool displayToggle, displayBackground, invertedColors;
    string displayString;
};