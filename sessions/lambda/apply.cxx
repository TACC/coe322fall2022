#include <iostream>
using std::cout;

#include <functional>
using std::function;

// function<
//     returntype(intype1,intype2)
// >

void apply_to_5( function< void(int) > f ) { f(5); }

int main() {

  apply_to_5( [] (int i) { cout << i << '\n'; } );

  return 0;
}
