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
  auto dx(Point other) { return x-other.x; };
  auto dy(Point other) { return y-other.y; };
  // accessors
  auto getx() { return x;};
  auto gety() { return y;};
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

class LinearFunction {
private:
  // data members
  Point reference;
  float slope;
public:
  LinearFunction( Point p,Point q ) 
    : reference(p){
    slope = p.dy(q) / p.dx(q);
      // (q.y-p.y)/(q.x-p.x);
  };
  float evaluate_at( float x ) {
    float dx = x-reference.getx();
    float dy = dx*slope;
    return reference.gety()+dy;
  };
};

class Rectangle {
protected:
  Point bl;
  float width,height;
public:
  Rectangle( Point p,float w,float h ) 
    : bl(p),width(w),height(h) {};
  float area() {
    return width*height;
  };
  float circumference() {
    return 2*(width+height);
  };
};

class Square : public Rectangle {
private:
  // no data members specific to the square
public:
  Square( Point p,float side ) 
    : Rectangle(p,side,side) {};
};

int main() {
  Point p(1.0,1.0), q(2.0,3.);

  Rectangle pq_rect(p,2,1);
  cout << "area: " << pq_rect.area() << '\n';

  Square p_square(p,1.414);
  cout << "area: " << p_square.area() << '\n';

  // LinearFunction slope(p,q);

  // cout << "dist: " << p.distance(q) << '\n';

  // float d = p.distance_to_origin();
  // cout << "Distance to origin: "
  //      << d << endl;
  // cout << "angle: " << p.angle() << '\n';
  
  return 0;
}

  // ESC < : beginning of file
  // ESC > : end of file
  // C-space : set "mark"
  // C-i : indent "region"
