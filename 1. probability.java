/*
http://natureofcode.com/book/introduction/

Random Walker
=============
*/
// Equal chance to move left, right, up, or down.
    if (int(random(4)) == 0) {
      x++;
    } else if (choice == 1) {
      x--;
    } else if (choice == 2) {
      y++;
    } else {
      y--;
    }

// Now add in diagonals + possibility of staying the same:
  void step() {
    int stepx = int(random(3))-1; //-1, 0, or 1
    int stepy = int(random(3))-1;
    x += stepx;
    y += stepy;
  }

// Same, but with floating point numbers
 void step() {
    float stepx = random(-1, 1); //-1.0 <> 1.0
    float stepy = random(-1, 1);
    x += stepx;
    y += stepy;
  }

/*
Probability’s basic principles
==============================

Single event probability
------------------------
The likelihood that a given event will occur once.

"If you have a system with a certain number of possible outcomes, the probability of the occurrence of a given event equals the number of outcomes that qualify as that event *divided by* the total number of all possible outcomes."

e.g.
number of heads / number of sides of coin = 1 / 2 = 0.5 = 50%
number of aces / number of cards          = 4 / 52 = 0.077 = ~ 8%
number of diamonds / number of cards      = 13 / 52 = 0.25 = 25%

Multiple event probability
--------------------------
Just multiply the individual probabilities. The probability of a coin turning up heads three times in a row is:
*/
(1/2) * (1/2) * (1/2) = 1/8 (or 0.125)
/*
...meaning that a coin will turn up heads three times in a row one out of eight times (each "time" being three tosses).


Techniques to produce probablistic outcomes in code
===================================================

#1. Choosing from pre-weighted arrays
-------------------------------------*/
int[] stuff = new int[5];
stuff[0] = 1;
stuff[1] = 1;
stuff[2] = 2;
stuff[3] = 3;
stuff[4] = 3;
int index = int(random(stuff.length));
/*
Running this code will produce a 40% chance of printing the value 1, a 20% chance of printing 2, and a 40% chance of printing 3.

#2. Choosing from bracketed probability bands
---------------------------------------------*/
float num = random(1);
if (num < 0.6) {              // less than 0.6
  println("Outcome A");
} else if (num < 0.7) {       // between 0.6 and 0.7
  println("Outcome B");
} else {                      // greater than 0.7
  println("Outcome C");
}
/*
You can use these to make a Random Walker with a tendency to move to the right

Normal / Gaussian / Laplacian Distributions
===========================================

Consider
--------
- Consider heights of NY residents as between 200 <> 300
- Most will cluster around 250
- Few will be close to 200 or 300

Definitions
-----------
- This is a 'normal' distribution - consider a bell curve
- The mean is the average, say 250 (or maybe it's 245 or 255 depending on your set)
- The standard deviation is how clustered the set is around the average

Example
-------
- i.e. does the bell curve flatten out smoothly either side
- or is it high in the middle and drops off either side?

Java's built in Gaussian function
---------------------------------
//The method Random.nextGaussian() has a mean of 0 and a standard deviation of 1
//All we have to do is multiply & add...
*/
void draw() {
  generator = new Random();
  float num = (float) generator.nextGaussian();
  float sd = 60;
  float mean = 320;
 
  //Multiply by the standard deviation and add the mean.
  float x = sd * num + mean;
}

/*
Uniform vs normal vs Lévy flight
================================

We could implement a Lévy flight by saying that there is a 1% chance of the walker taking a large step.
*/
//A 1% chance of taking a large step
float r = random(1);
if (r < 0.01) {
  xstep = random(-100,100);
  ystep = random(-100,100);
} else {
  xstep = random(-1,1);
  ystep = random(-1,1);
}
/*
What if we wanted to make a more general rule—the higher a number, the more likely it is to be picked?

            |  /
Probability | /
            |/____
              Value to be picked

One way is the Monte Carlo method. See below - when r1 is 1 it's almost certain to be picked, but when r1 is 0.01 it is unlikely, but possible:
*/
float montecarlo() {
  while (true) {
    float r1 = random(1);
    float probability = r1;
    float r2 = random(1);

    if (r2 < probability) {
      return r1;
    }
  }
}
/*
You can change that probability assignment to a squaring function to get an exponentially increasing probability curve.

Perlin noise
============
Randomness gets you schizophrenic results. In noise, each new value is influenced by it's neighbors.

Noise is gradations over time, therefore we must pass in an incrementing time value to traverse it, i.e.

Time.   Noise Value
0.      0.365
1.      0.363
2.      0.363
3.      0.364
4.      0.366

The faster we increment, the faster we traverse the noise.

Noise function return values are always 0 to 1, therefore we use a mapping function:
*/
float t = 0;

void draw() {
    float n = noise(t);
    float x = map(n, 0, 1, 0, width);
    ellipse(x, 180, 16, 16);

    t += 0.01;
}
/*
When using two or more dimensions, we need an arbitrary offset to avoid x & y being the same!
*/
void setup() {
  offx = 10000; //arbitrary offset
  tx = 0 + offx;
  ty = 0;
}

void step() {
    x = map(noise(tx), 0, 1, 0, width);
    y = map(noise(ty), 0, 1, 0, height);

    tx += 0.01;
    ty += 0.01;
  }
}
/*
"It’s important to remember, however, that Perlin noise values are just that—values. They aren’t inherently tied to pixel locations or color. Any example ... that has a variable could be controlled via Perlin noise. When we model a wind force, its strength could be controlled by Perlin noise. Same goes for the angles between the branches in a fractal tree pattern, or the speed and direction of objects moving along a grid in a flow field simulation."
*/