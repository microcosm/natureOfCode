/*
http://natureofcode.com/book/chapter-2-forces/

Newton's laws
=============
Law #1
------
An object at rest stays at rest and an object in motion stays in motion at a constant speed and direction unless acted upon by an unbalanced force.
(or)
An object’s PVector velocity will remain constant if it is in a state of equilibrium, i.e. the sum of all forces add to zero.

Law #2
------
Force = mass x acceleration
(or)
->    ->
F = M A
(or)
Acceleration is directly proportional to force and inversely proportional to mass. This means that if you get pushed, the harder you are pushed (force), the faster you’ll move (accelerate). The bigger you are, the slower you’ll move (mass).
(or)
*Net* force = mass x acceleration
(or)
Acceleration is equal to the *sum of all* forces divided by mass. This makes perfect sense. After all, as we saw in Newton’s first law, if all the forces add up to zero, an object experiences an equilibrium state (i.e. no acceleration). Our implementation of this is through a process known as force accumulation. It’s actually very simple; all we need to do is add all of the forces together.

Law #3
------
For every action there is an equal and opposite reaction.
(or)
Forces always occur in pairs. The two forces are of equal strength, but in opposite directions.
(or)
If we calculate a PVector f that is a force of object A on object B, we must also apply the force — PVector.mult(f,-1); — that B exerts on object A. If, that is, we choose to model it. For example we may choose to model the effect of wind on a moving car, but not of the car on the wind.


Weight vs. Mass
===============
- The mass of an object is a measure of the amount of matter in the object (measured in kilograms).
- Weight, though often mistaken for mass, is technically the force of gravity on an object. From Newton’s second law, we can calculate it as mass times the acceleration of gravity (w = m * g). Weight is measured in newtons.
- Density is defined as the amount of mass per unit of volume (grams per cubic centimeter, for example).
- Note that an object that has a mass of one kilogram on earth would have a mass of one kilogram on the moon. However, it would weigh only one-sixth as much.

Simple Forces Modelled
======================
A bunch of movers affected by wind to the right and (simplified) gravity to the bottom. Just a couple of PVector forces:
*/
  class Mover {
    PVector location;
    PVector velocity;
    PVector acceleration;
    float mass;

    Mover(float m, float x , float y) {
      mass = m;
      location = new PVector(x,y);
      velocity = new PVector(0,0);
      acceleration = new PVector(0,0);
    }

    //Newton’s second law
    void applyForce(PVector force) {
      PVector f = PVector.div(force, mass);
      acceleration.add(f);
    }

    void update() {
      velocity.add(acceleration);
      location.add(velocity);
      //Clear acceleration each time so that the forces actions don't unintentionally accumulate
      acceleration.mult(0);
    }

    void display() {
      stroke(0);
      fill(175);
      //Scale the size according to the mass
      ellipse(location.x, location.y, mass*16, mass*16);
    }

    //Bounce off window edges, the quick-n-dirty way. Just reverse the corresponding velocity
    void checkEdges() {
      if (location.x > width) {
        location.x = width;
        velocity.x *= -1;
      } else if (location.x < 0) {
        velocity.x *= -1;
        location.x = 0;
      }

      if (location.y > height) {
        velocity.y *= -1;
        location.y = height;
      } else if (location.y < 0) {
        velocity.y *= -1;
        location.y = 0;
      }
    }
  }

  Mover[] movers = new Mover[100];
  PVector wind;
  PVector gravity;

  void setup() {
    for (int i = 0; i < movers.length; i++) {
      movers[i] = new Mover(random(0.1,5), 0, 0);
    }

    //Invent two forces
    wind = new PVector(0.01, 0);
    gravity = new PVector(0, 0.1);
  }

  void draw() {
    background(255);

    for(int i = 0; i < movers.length; i++) {
      movers[i].applyForce(wind);
      movers[i].applyForce(gravity);
      movers[i].update();
      movers[i].display();
      movers[i].checkEdges();
    }
  }
/*
Exercise 2.3
============
"Instead of objects bouncing off the edge of the wall, create an example in which an invisible force pushes back on the objects to keep them in the window. Can you weight the force according to how far the object is from an edge—i.e., the closer it is, the stronger the force?"

Actual Gravity
==============
The problem with the code above is that small objects will fall faster, because acceleration / mass = force. With actual gravity, do Smaller Objects Really Fall Faster??
Er, no.

Actual gravity has another nuance we haven't modeled yet - it is calculated relative to an object's mass. The bigger the object, the stronger the force. So if the force is scaled according to mass, it is canceled out when acceleration is divided by mass. We can implement this in our sketch rather easily by multiplying our made-up gravity force by mass:
*/
  for(int i = 0; i < movers.length; i++) {
    PVector wind = new PVector(0.001, 0);
    float m = movers[i].mass;
    PVector gravity = new PVector(0, 0.1*m);
    movers[i].applyForce(wind);
    movers[i].applyForce(gravity);
    movers[i].update();
    movers[i].display();
    movers[i].checkEdges();
  }
/*
Any Old Force
=============
You don't have to copy the real world. Here's what we're trying to learn how to do for each possible force:

- Understand the concept behind a force
- Deconstruct the force's formula into two parts:
   - How do we compute the force's direction?
   - How do we compute the force's magnitude?
- Translate that formula into Processing code that calculates a PVector to be sent through our Mover's applyForce() function

Let's do this with gravity and fiction, then hopefully if you ever find yourself Googling "atomic nuclei weak nuclear force" at 3 a.m., you will have the skills to take what you find and adapt it for Processing

Deconstructing Formulae
=======================
1. Evaluate the right side, assign to the left side
2. Are we talking about a vector or a scalar? (or even a unit vector?)
3. When symbols are placed next to each other, we mean for them to be multiplied

Friction
========
Friction is a dissipative force: one in which the total energy of a system decreases when an object is in motion:
                        ^
Friction = -1 * u * N * v

-1  points in opposite direction to velocity
u   (mu) coefficient of friction. e.g. block of ice vs sandpaper
N   the 'normal' force - calculated by reference to gravity, but not necessarily pointing in the same direction as gravity - for now let's use a constant 1
*/
  float coefficient = 0.01;
  float normal = 1;
  
  void draw() {
    background(255);

    PVector wind = new PVector(0.001, 0);
    //Remember, we *could* scale by mass to be more accurate.
    PVector gravity = new PVector(0, 0.1);

    for(int i = 0; i < movers.length; i++) {
      PVector friction = movers[i].velocity.get();
      friction.mult(-1);
      friction.normalize();
      friction.mult(normal);
      friction.mult(coefficient);

      movers[i].applyForce(friction);
      movers[i].applyForce(wind);
      movers[i].applyForce(gravity);

      movers[i].update();
      movers[i].display();
      movers[i].checkEdges();
    }
  }
/*
Exercise 2.4
============
"Create pockets of friction in a Processing sketch so that objects only experience friction when crossing over those pockets. What if you vary the strength (friction coefficient) of each area? What if you make some pockets feature the opposite of friction—i.e., when you enter a given pocket you actually speed up instead of slowing down?"

Drag / Fluid Resistance
=======================
A special case of friction with its own formula is 'drag', as in the drag of passing through a liquid. aka: viscous force, drag force, fluid resistance.
                 2            ^
Fd = -0.5 * p * v  * A * Cd * v

Fd   drag force, the vector we are calculating
-0.5 only the negation is really key for us
p    (rho) constant representing density of liquid - we'll use 1
v    speed of moving object
A    constant representing front of moving object, i.e. how aerodynamic
Cd   coefficient of drag, like coefficient of friction
^
v    velocity unit vector

Let's implement this but with a differentiation between liquid and non-liquid:
*/
  class Liquid {
    float x,y,w,h;
    float c;

    Liquid(float x_, float y_, float w_, float h_, float c_) {
      x = x_;
      y = y_;
      w = w_;
      h = h_;
      c = c_;
    }

    void display() {
      noStroke();
      fill(175);
      rect(x,y,w,h);
    }
  }

  class Mover {
    //etc
    boolean isInside(Liquid l) {
      return location.x > l.x &&
             location.x < l.x + l.w &&
             location.y > l.y &&
             location.y < l.y + l.h;
    }

    void drag(Liquid l) {
      float speed = velocity.mag();
      float dragMagnitude = l.c * speed * speed;

      PVector drag = velocity.get();
      drag.mult(-1);
      drag.normalize();
      drag.mult(dragMagnitude);
      applyForce(drag);
    }
  }

  Mover[] movers = new Mover[100];
  Liquid liquid;

  void setup() {
    size(360, 640);
    for(int i = 0; i < movers.length; i++) {
      movers[i] = new Mover(random(0.1, 5),0 ,0);
    }
    liquid = new Liquid(0, height/2, width, height/2, 0.1);
  }

  void draw() {
    background(255);
    liquid.display();

    for(int i = 0; i < movers.length; i++) {
      if (movers[i].isInside(liquid)) {
        movers[i].drag(liquid);
      }

      //For now still using cheap constant for gravity
      float m = 0.1 * movers[i].mass;
      PVector gravity = new PVector(0,  m);
      movers[i].applyForce(gravity);
      movers[i].update();
      movers[i].display();
      movers[i].checkEdges();
    }
  }
/*
Notice that the smaller objects slow down a great deal more than larger ones. Remember implementing Newton's second law in Mover.applyForce()?

net acceleration = force / mass

So now that we've added our fluid drag force, gravity alone isn't dictating the fall of our objects. The drag force will be stronger when there is a smaller mass to divide it by. Therefore, smaller objects will take longer to reach the bottom than larger ones.

Exercise 2.6
============
"Take a look at our formula for drag again:"

  drag force = coefficient * speed * speed

"The faster an object moves, the greater the drag force against it. In fact, an object not moving in water experiences no drag at all. Expand the example to drop the balls from different heights. How does this affect the drag as they hit the water?"

Exercise 2.6
============
"The formula for drag also included surface area. Can you create a simulation of boxes falling into water with a drag force dependent on the length of the side hitting the water?"

Exercise 2.7
============
"Fluid resistance does not only work opposite to the velocity vector, but also perpendicular to it. This is known as “lift-induced drag” and will cause an airplane with an angled wing to rise in altitude. Try creating a simulation of lift."

Gravity
=======
At last, let's fill this in:

     G * m1 * m2    ^
F =  -----------  * r
           2
          r

F    the gravitational force, the vector we are computing

G    the universal gravitational constant: [6.67428 x 10-11 meters cubed per kilogram per second squared]. Or 1, for us.

m1&2 the masses of objects 1 and 2

r    the distance between the two objects - used in the following two contexts:

^
r    unit vector pointing from m1 to m2

2
r    the distance between the two objects squared

Note that with the last value, we are dividing, not multiplying. The strength of the force is *inversely* proportional to the distance squared. The farther away an object is, the weaker the force; the closer, the stronger.

Now let's implement gravity with a fixed Attractor and a moving Mover:
*/
  Mover m;
  Attractor a;

  void setup() {
    size(640,360);
    m = new Mover();
    a = new Attractor();
  }

  void draw() {
    background(255);
    PVector force = a.attract(m);
    m.applyForce(force);
    m.update();

    a.display();
    m.display();
  }

  class Attractor {
    float mass;
    PVector location;
    float G;

    Attractor() {
      location = new PVector(width/2, height/2);
      mass = 20;
      G = 0.4; //should it really be a member variable?
    }

    PVector attract(Mover m) {
      PVector force = PVector.sub(location, m.location);
      float distance = force.mag();
      //Keep it sensible with some arbitrary numbers
      distance = constrain(distance, 5.0, 25.0);

      force.normalize();
      float strength = (G * mass * m.mass) / (distance * distance);
      force.mult(strength);
      return force;
    }

    void display() {
      stroke(0);
      fill(175, 200);
      ellipse(location.x, location.y, mass*2, mass*2);
    }
  }
/*
Exercise 2.8
============
In the example above, we have a system (i.e. array) of Mover objects and one Attractor object. Build an example that has systems of both movers and attractors. What if you make the attractors invisible? Can you create a pattern/design from the trails of objects moving around attractors? See the Metropop Denim project by Clayton Cubitt and Tom Carden for an example.

Exercise 2.9
============
It's worth noting that gravitational attraction is a model we can follow to develop our own forces. This chapter isn't suggesting that you should exclusively create sketches that use gravitational attraction. Rather, you should be thinking creatively about how to design your own rules to drive the behavior of objects. For example, what happens if you design a force that is weaker the closer it gets and stronger the farther it gets? Or what if you design your attractor to attract faraway objects, but repel close ones?

Mutual Attraction
=================
No more fixed-location Attractor nonsense. Let's go crazy for once:
*/
  Mover[] movers = new Mover[20];
  float g = 0.4; //more like it

  void setup() {
    size(400, 400);
    for(int i = 0; i < movers.length; i++) {
      movers[i] = new Mover(random(0.1, 2), random(width), random(height));
    }
  }

  void draw() {
    background(255);
    for (int i = 0; i < movers.length; i++) {
      for (int j = 0; j < movers.length; j++) {
        if (i != j) {
          PVector force = movers[j].attract(movers[i]);
          movers[i].applyForce(force);
        }
      }
      movers[i].update();
      movers[i].display();
    }
  }
/*
Exercise 2.10
=============
"Change the attraction force in Example 2.8 to a repulsion force. Can you create an example in which all of the Mover objects are attracted to the mouse, but repel each other? Think about how you need to balance the relative strength of the forces and how to most effectively use distance in your force calculations."

The Ecosystem Project
=====================
Step 2 Exercise: "Incorporate the concept of forces into your ecosystem. Try introducing other elements into the environment (food, a predator) for the creature to interact with. Does the creature experience attraction or repulsion to things in its world? Can you think more abstractly and design forces based on the creature’s desires or goals?"

