#pragma once

#include "ofMain.h"

class ofxExperimentInterface {
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void initText(string text);
    void addText(string text);
    void setMax(int _max);
    void setCurrent(int _current);
    void enableBackground();
    void invertColors();
    bool changed();
    int getCurrent();
    
protected:
    void drawBackground();
    void drawText();
    void newBackgroundSize();
    
    int current, last, max;
    ofVec2f backgroundSize, initialBackgroundSize;
    bool displayToggle, displayBackground, invertedColors;
    string displayString, initialText, additionalText;
};