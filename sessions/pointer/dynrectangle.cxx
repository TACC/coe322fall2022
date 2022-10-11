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
  Point scale( float s ) { return Point(s*x,s*y); };
  void scaleby( float s ) { x *= s; y *= s; };
  Point operator*(float s) { return Point(s*x,s*y); };
  Point operator+(Point other) {
    return Point(x+other.x,y+other.y);
  };
  void print() { cout << x << "," << y << '\n'; };

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

#include <memory>
using std::shared_ptr; 
using std::make_shared;

class DynRectangle {
protected:
  shared_ptr<Point> bl,tr;
public:
  DynRectangle
  ( shared_ptr<Point> p,shared_ptr<Point> q) {
    bl = p; tr = q;
  };
  double area() {
    double width = tr->getx() - bl->getx(),
      height = tr->gety() - bl->gety();
    return width*height;
  };
};

int main() {
  auto p = make_shared<Point>(0,0);
  auto q = make_shared<Point>(5,2.);

  DynRectangle pq_rect(p,q);

  cout << "area: " << pq_rect.area() << '\n';
  q->scaleby(2.);
  cout << "area: " << pq_rect.area() << '\n';

  return 0;
}

