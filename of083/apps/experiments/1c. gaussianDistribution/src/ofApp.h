#pragma once

#include "ofMain.h"
#include "ofxAnimatableFloat.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setupExp1(); void drawExp1();
    void setupExp2(); void drawExp2();
    void setupExp3(); void drawExp3();
    void setupExp4(); void drawExp4();
    
    int current, prev, max;
    bool changed;
    
    float nextGaussian();
    float nextGaussian(float sd, float mean);
};

/* This class is required to use vectors as keys in maps
   More: http://www.openframeworks.cc/tutorials/c++%20concepts/002_stl_map.html */

class vec2Key {
    
    public:
        float x, y;
    
        vec2Key(float xValue, float yValue){
            
            x = xValue;
            y = yValue;
        }
    
        bool operator < (const vec2Key& other) const{
            
            if ( x == other.x ) {
                return y < other.y;
            }
        
            return x < other.x;
        }
};