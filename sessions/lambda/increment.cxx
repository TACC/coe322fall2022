#include <iostream>
using std::cout;
#include <iomanip>
using std::boolalpha;

int main() {
  int one=3;
  auto increment =
    [one] ( int input ) -> int { 
        return input+one;
  };
  // cout << increment (5) << '\n';
  // cout << increment (12) << '\n';
  // cout << increment (25) << '\n';
  

  {
    float lo=.5, hi=1.5;
    auto between = [hi,lo] ( float x ) -> bool {
      return (lo<x and x<hi) ;
    };
    cout << boolalpha << between(.99) << '\n';
  }

 return 0;

}
