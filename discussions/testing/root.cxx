#include <iostream>
using std::cout, std::cin;
#include <cmath>

double compute_root(double x) {
  if (x<0)
    throw(1);
  return sqrt(x);
}

int main() {
  double x,y;
  cin >> x;
  try {
    y = compute_root(x);
  } catch (int e) {
    /* handle error */
    cout << "Root failed with error " << e << "; using default\n"; 
    y = 0;
  } catch (...) { /* other exceptions */ }
  cout << "root is: " << y << '\n';
  return 0;
}

// TAB or C-i fix indentation

// emacs navigation
// arrow keys
// C-f C-b forward back char
// C-p C-n prev next line
// ESC f ESC b : word forward/back

// C-x C-s save
// C-x C-c exit
// C-z : suspend
