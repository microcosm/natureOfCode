/*

http://natureofcode.com/book/chapter-1-vectors/

Euclidean vector / geometric vector - an entity that has both magnitude and direction.

Or in other words, a vector is the difference between two points.
*/
float x = 100; float y = 100;
float xspeed = 1; float yspeed = 3.3;

void draw() {
  x = x + xspeed;
  y = y + yspeed;

  if ((x > width) || (x < 0)) {
    xspeed = xspeed * -1;
  }
  if ((y > height) || (y < 0)) {
    yspeed = yspeed * -1;
  }
  ellipse(x,y,16,16);
}

//Instead of:
  float x; float y;
  float xspeed; float yspeed;

//We could simply have…
  Vector location;
  Vector speed;
/*
Location is a vector. It represents the difference between origin (0,0) and some other point.

Velocity is a vector. Think of cardinal directions and a map. To get from point A to point B, you might go 2 steps North and 3 steps East.

For every frame:
new location = velocity applied to current location
*/
  location.add(velocity);
  //same as
  location.x += velocity.x;
  location.y += velocity.y;





