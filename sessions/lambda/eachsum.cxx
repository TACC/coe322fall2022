#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;

int main() {

  vector<float> values{ .5, 1., 1.5, 2. };
  float sum{0.};

  for_each( values.begin(),values.end(),
	    [&sum] ( float x ) -> void { sum += x;}
	    );
  cout << "Sum is: " << sum << '\n';
  
  return 0;
}
