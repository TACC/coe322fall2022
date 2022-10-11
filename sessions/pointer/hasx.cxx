#include <iostream>
using std::cout;

#include <memory>
using std::make_shared;

class HasX {
private:
  double x;
public:
  HasX( double xx ) 
    : x(xx) {};
  double get() { return x; };
  void set(double v) { x = v; };
};

int main() {
  HasX five(5.);
  HasX six = five;
  five.set(5.1);
  // cout << five.get() << '\n';
  // cout << six.get() << '\n';

  // auto is short for ` shared_ptr<HasX> '
  auto five_ptr = make_shared<HasX>(5.);
  cout << five_ptr->get() << '\n';
  auto six_ptr = five_ptr;
  five_ptr->set(4.9);
  cout << six_ptr->get() << '\n';  

  return 0;
}

// emacs
// C-c C-c : comment region
