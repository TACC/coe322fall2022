/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointdist.cxx : make a Point class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

class Point {
private:
  float x,y;
public:
  Point() {};
  Point(float ux,float uy) { x = ux; y = uy; };
  float distance_to_origin() {
    return sqrt( x*x + y*y );
  }
  float angle() {
    return atan(y/x);
  }
  float distance(Point other) {
    float dx = x-other.x, dy = y-other.y;
    return sqrt( dx*dx + dy*dy );
  }
  Point halfway( Point other ) {
    auto halfx = (x+other.x)/2, halfy = (y+other.y)/2;
    Point halfwaypoint(halfx,halfy);
    return halfwaypoint;
    // or just:
    // return Point((x+other.x)/2, halfy = (y+other.y)/2);
  };
};

int main() {
  Point p(1.0,1.0), q(2.0,0.5);
  Point z;

  cout << "dist: " << p.distance(q) << '\n';

  float d = p.distance_to_origin();
  cout << "Distance to origin: "
       << d << endl;
  cout << "angle: " << p.angle() << '\n';
  
  return 0;
}

  // ESC < : beginning of file
  // ESC > : end of file
  // C-space : set "mark"
  // C-i : indent "region"
