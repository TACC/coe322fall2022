/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** newton1.cxx : newton scalar example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

#include <functional>
using std::function;

// double f(double x) { return x*x-2; };
// double fprime(double x) { return 2*x; };

double newton_root ( function< double(double) > f,
		     function< double(double) > fprime ) {
  double x{1.};
  while ( true ) {
    auto fx = f(x); // apply f, get rid of `f'
    cout << "f( " << x << " ) = " << fx << "\n";
    if (std::abs(fx)<1.e-10 ) break;
    x = x - fx/fprime(x); // applying fprime, so get rid of `fprime'
  }
  return x;
}

int main() {

  // auto f = [] (double x) -> double { return x*x-2; };
  // auto fprime = [] (double x) -> double { return 2*x; };

  auto sqrt2 = newton_root
    (  [] (double x) -> double { return x*x-2; },
       [] (double x) -> double { return 2*x; } );

  cout << sqrt2 << '\n';

  return 0;
}

// Ctrl-space : set mark (this should echo "Mark set" in the status line) 
// (alternatively: ESC x set-mark )
// go to the other end
// Ctrl-w : scoop up region
// go elsewhere
// Ctrl-y : yank back

// also possible:
//     auto fx = [] (double x) -> double { return x*x-2; } (x);
