/*
http://natureofcode.com/book/chapter-1-vectors/

The PVector Class
=================
*/
//Euclidean vector, aka geometric vector: 'an entity with both magnitude and direction'
//Implemented with scalars:
float x = 100; float y = 100;
float xspeed = 1; float yspeed = 3.3;

void draw() {
  x = x + xspeed;
  y = y + yspeed;

  if ((x > width) || (x < 0)) {
    xspeed = xspeed * -1; //if we hit the edges...
  }
  if ((y > height) || (y < 0)) {
    yspeed = yspeed * -1; //...we reverse the sign
  }
  ellipse(x, y, 16, 16);
}

//However, instead of:
float x; float y;
float xspeed; float yspeed;

//We could simply have...
PVector location;
PVector speed;

/*
The Velocity Vector
===================
A vector is the difference between two points. Velocity is therefore a natural vector. It is the difference between two points traveled in a single frame.

Arguably, location is NOT a vector. It is simply a point in space, it says nothing of magnitude nor direction. However, it CAN be said to be a vector, in that it represents the difference between origin (0, 0) and some other point.

Think of cardinal directions and a map. To get from point A to point B, you might go 2 steps North and 3 steps East.

For every frame, new location = velocity applied to current location:
*/
location.add(velocity);
//same as
location.x += velocity.x;
location.y += velocity.y;

/*
Arrow Notation
==============
In mathematical notation, you can always tell a vector as opposed to a scalar (a single int or float value) because a vector has an arrow above the algebraic symbol:
        ->
Vector: u
Scalar: x
*/

/*
PVector Operations
================== */
.add()          //add vectors
.sub()          //subtract vectors
.mult()         //scale the vector with multiplication
.div()          //scale the vector with division
.mag()          //calculate the magnitude of a vector (Pythagoras)
.setMag()       //set the magnitude of a vector
.normalize()    //normalize the vector to a unit length of 1
.limit()        //limit the magnitude of a vector
.heading()      //the 2D heading of a vector expressed as an angle
.rotate()       //rotate a 2D vector by an angle
.lerp()         //linear interpolate to another vector
.dist()         //the Euclidean distance between two vectors (considered as points)
.angleBetween() //find the angle between two vectors
.dot()          //the dot product of two vectors
.cross()        //the cross product of two vectors (only relevant in three dimensions)
.random2D()     //make a random 2D vector
.random3D()     //make a random 3D vector

/*
Static Methods
==============
PVector's static methods allow us to perform math operations without having to change the value of the existing objects. By contrast, regular methods operate directly on the instance:
*/
PVector z = PVector.add(x, y);
  //vs
x.add(y);

/*
Motion 101
==========
Let's make a simple OO sketch to show all this off:
*/
Mover mover;

void setup() {
  size(640, 360);
  mover = new Mover();
}

void draw() {
  background(255);
  mover.update();
  mover.checkEdges();
  mover.display();
}

class Mover {
  PVector location;
  PVector velocity;

  Mover() {
    location = new PVector(random(width), random(height));
    velocity = new PVector(random(-2, 2), random(-2, 2));
  }

  void update() {
    location.add(velocity);
  }

  void display() {
    stroke(0);
    fill(175);
    ellipse(location.x, location.y, 16, 16);
  }

  void checkEdges() {
    if (location.x > width) {
      location.x = 0;
    } else if (location.x < 0) {
      location.x = width;
    }

    if (location.y > height) {
      location.y = 0;
    } else if (location.y < 0) {
      location.y = height;
    }
  }
}

/*
Acceleration
============
Now let's add acceleration. First, some definitions:
Velocity:      the rate of change of location
Acceleration:  the rate of change of velocity.

Notice the trickle-down effect? This will continue later with forces.

Acceleration algorithms we are going to run through now:
1. A constant acceleration
2. A totally random acceleration
3. Acceleration towards the mouse

So starting with (1), here is the same sketch from above - but this time with all movement controlled not by direct changes to location nor velocity, but to acceleration alone.

1. A constant acceleration
--------------------------
*/
class Mover {
  PVector location;
  PVector velocity;
  PVector acceleration;
  float topspeed;

  Mover() {
    location = new PVector(width/2,height/2);
    velocity = new PVector(0,0);
    acceleration = new PVector(-0.001,0.01);
    topspeed = 10;
  }

  void update() {
    velocity.add(acceleration);
    velocity.limit(topspeed);
    location.add(velocity);
  }

  void display() {//as above}
  void checkEdges() {//as above}
}
/*

2. A totally random acceleration
--------------------------------
*/
void update() {
  //Gives us a PVector of length 1, pointing in a random direction
  acceleration = PVector.random2D();

  velocity.add(acceleration);
  velocity.limit(topspeed);
  location.add(velocity);
}

/*
Note: Acceleration is Steering Too
==================================
It’s crucial to understand that acceleration does NOT merely refer to the speeding up or slowing down of a moving object, but rather any change in velocity in either magnitude OR direction.

Acceleration is used to steer an object - this is part of what it means to modify a velocity vector.

With random2D() the result we get is normalized, it's magnitude will always be 1. Therefore we can scale it: */
//(a) scaling the acceleration to a constant value
  acceleration = PVector.random2D();
  acceleration.mult(0.5);

//(b) scaling the acceleration to a random value
  acceleration = PVector.random2D();
  acceleration.mult(random(2));

/*
Exercise 1.6
============
Referring back to the Introduction, implement acceleration according to Perlin noise

3. Acceleration towards the mouse
---------------------------------
*/
void update() {
  PVector mouse = new PVector(mouseX,mouseY);
  //Step 1: Compute direction
  PVector dir = PVector.sub(mouse,location);
  //Step 2: Normalize
  dir.normalize();
  //Step 3: Scale
  dir.mult(0.5);
  //Step 4: Accelerate
  acceleration = dir;

  velocity.add(acceleration);
  velocity.limit(topspeed);
  location.add(velocity);
}