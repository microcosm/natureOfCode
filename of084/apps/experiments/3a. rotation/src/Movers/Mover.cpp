#include "Mover.h"

void Mover::setup() {
    topspeed = 2000;
    topAngularVelocity = 2.5;
    setLocation(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    setMass(1);
}

void Mover::update() {
    //Orginal motion
    velocity += acceleration;
    velocity.limit(topspeed);
    location += velocity;
    
    //Quick n dirty 'force' instead of torque and moment of inertia
    //Just use acceleration to determine rotation
    angularAcceleration = velocity.x / 1.0;
    
    //Then reset, once we've grabbed that value. Forces will calculate our next acceleration
    acceleration *= 0;

    //New (angular) motion
    angularVelocity += angularAcceleration;
    angularVelocity = limit(angularVelocity, topAngularVelocity);
    angle += angularVelocity;
    //angularAcceleration *= 0; //reset? no because quick n dirty 'force' above
    
    checkEdges();
}

void Mover::draw() {
    ofTranslate(location.x, location.y);
    ofRotate(angle);
}

void Mover::applyForce(ofVec2f force) {
    //Newton's second law:
    // Net force = mass x acceleration
    // The 'net' is why it's += and not just plain equals
    acceleration += force / mass;
}

void Mover::applyGravity(ofVec2f force) {
    //The force of gravity is applied to objects via weight,
    //measured in newtons. Weight = mass * gravity.
    acceleration += (force * mass) / mass;
    //Isn't this equivalent to
    //acceleration += force; ??
}


void Mover::applyFriction(float frictionCoefficient, float frictionNormal) {
    //Friction is a dissipative force: one in which the total energy of a system decreases when an object is in motion:
    //                          ^
    //  Friction = -1 * u * N * v
    //
    //  -1  points in opposite direction to velocity
    //  u   (mu) coefficient of friction. e.g. block of ice vs sandpaper
    //  N   the 'normal' force - calculated by reference to gravity, but not necessarily pointing in the same direction as gravity - for now let's use a constant 1
    //  ^
    //  v   is the unit vector for velocity (velocity normalized - the ^ means it's a unit vector)
    //
    //(See the diagram in section 2.7!)
    
    ofVec2f force = velocity;
    force.normalize();
    force *= -1;
    force *= frictionCoefficient;
    force *= frictionNormal;
    
    acceleration += force / mass;
}

void Mover::setTopSpeed(int speed) {
    topspeed = speed;
}

void Mover::setLocation(float x, float y) {
    location.set(x, y);
}

void Mover::setMass(float _mass) {
    mass = _mass;
}

void Mover::setAcceleration(float x, float y) {
    //Don't use this unless you want to override forces
    acceleration.set(x, y);
}

void Mover::accelerateTowards(ofVec2f target, float multiplier) {
    //Don't use this unless you want to override forces
    acceleration = target - location;
    acceleration.normalize();
    acceleration *= multiplier;
}

float Mover::getX() {
    return location.x;
}

float Mover::getY() {
    return location.y;
}

float Mover::limit(float f, float max) {
    if(f > max) {
        return max;
    } else if(f < -max) {
        return -max;
    }
    return f;
}

void Mover::checkEdges() {
    if (location.x > ofGetWidth()) {
        location.x = ofGetWidth();
        velocity.x *= -1;
    } else if (location.x < 0) {
        location.x = 0;
        velocity.x *= -1;
    }
    
    if (location.y > ofGetHeight()) {
        location.y = ofGetHeight();
        velocity.y *= -1;
    } else if (location.y < 0) {
        location.y = 0;
        velocity.y *= -1;
    }
}