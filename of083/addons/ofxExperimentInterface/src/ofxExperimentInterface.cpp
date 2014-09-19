#include "ofxExperimentInterface.h"

void ofxExperimentInterface::setup() {
    current = max = 1;
    last = 0;
    displayToggle = true;
    displayBackground = false;
    invertedColors = false;
    backgroundSize = initialBackgroundSize = ofVec2f(215, 114);
    ofToggleFullscreen();
}

void ofxExperimentInterface::update(){
    last = current;
}

void ofxExperimentInterface::draw() {
    if(displayToggle) {
        drawBackground();
        drawText();
    }
}

void ofxExperimentInterface::keyPressed(int key){
    if(key == 'n') {
        last = current;
        
        if(current < max){
            current++;
        } else {
            current = 1;
        }
    }
    
    if(key == 'd') {
        displayToggle = !displayToggle;
    }
}

void ofxExperimentInterface::addText(string text) {
    newBackgroundSize(text);
    additionalText = text;
}

void ofxExperimentInterface::setMax(int _max) {
    max = _max;
}

void ofxExperimentInterface::setCurrent(int _current) {
    current = _current;
}

void ofxExperimentInterface::enableBackground() {
    displayBackground = true;
}

void ofxExperimentInterface::invertColors() {
    invertedColors = true;
}

bool ofxExperimentInterface::changed() {
    return current != last;
}

int ofxExperimentInterface::getCurrent() {
    return current;
}

void ofxExperimentInterface::drawBackground() {
    if(displayBackground) {
        if(invertedColors) {
            ofSetColor(ofColor::white);
        } else {
            ofSetColor(ofColor::black);
        }
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofRect(0, 0, backgroundSize.x, backgroundSize.y);
    }
}

void ofxExperimentInterface::drawText() {
    if(invertedColors) {
        ofSetColor(ofColor::black);
    } else {
        ofSetColor(ofColor::white);
    }
    displayString = "";
    displayString += "Running experiment #" + ofToString(current);
    displayString += "\n\n";
    displayString += ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight());
    displayString += ", " + ofToString(ofGetFrameRate()) + "fps";
    displayString += "\n\n";
    displayString += "d: toggle display\n";
    displayString += "n: next experiment\n\n";
    displayString += additionalText;
    ofDrawBitmapString(displayString, 19, 25);
}

void ofxExperimentInterface::newBackgroundSize(string toFitString) {
    int numLines = count(toFitString.begin(), toFitString.end(), '\n') + 1;
    backgroundSize = initialBackgroundSize;
    backgroundSize.y += 16 * numLines;
}