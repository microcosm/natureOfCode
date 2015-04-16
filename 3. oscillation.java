/*
http://natureofcode.com/book/chapter-3-oscillation/

Angular Motion
==============
3.2 Angular Motion

Remember all this stuff?

  velocity = velocity + acceleration
  location = location + velocity

Well, we can apply exactly the same logic to a rotating object.

  angular velocity = angular velocity + angular acceleration
  angle = angle + angular velocity

In fact, the above is actually simpler because an angle is a scalar quantity—a single number, not a vector!
*/
class Mover {
 
  PVector location;
  PVector velocity;
  PVector acceleration;
  float mass;
 
  float angle = 0;
  float aVelocity = 0;
  float aAcceleration = 0.01;

  void update() {
    //Regular old-fashioned motion
    velocity.add(acceleration);
    location.add(velocity);
 
    //Newfangled angular motion
    aVelocity += aAcceleration;
    angle += aVelocity;
 
    acceleration.mult(0);
  }

  void display() {
    stroke(0);
    fill(175,200);
    rectMode(CENTER);
    //pushMatrix() and popMatrix() are necessary so that the rotation of this shape doesn’t affect the rest of our world.
    pushMatrix();
 
    //Set the origin at the shape’s location.
    translate(location.x,location.y);
    //Rotate by the angle.
    rotate(angle);
    rect(0, 0, mass*16, mass*16);
    popMatrix();
  }
}