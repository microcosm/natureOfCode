#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    void update();
    void draw();
    
    void applyForce(ofVec2f force);
    void applyGravity(ofVec2f force);
    void applyFriction(float frictionCoefficient, float frictionNormal);
    void setTopSpeed(int speed);
    void setLocation(float x, float y);
    void setMass(float _mass);
    void setAcceleration(float x, float y);
    void accelerateTowards(ofVec2f target, float multiplier);
    float getX();
    float getY();
    
protected:
    float limit(float f, float max);
    void checkEdges();
    
    ofVec2f location, velocity, acceleration;
    float mass;
    float angle, angularVelocity, angularAcceleration;
    int topspeed;
    float topAngularVelocity;
};