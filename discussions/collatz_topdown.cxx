#include <iostream>
using std::cout;

int main () {
  // find the longest sequence under 1000
  int length_of_longest=0;
  for (int starting_point=1; starting_point<1000; starting_point++) {
    // compute length of the sequence
    int iterate=starting_point, count=0;
    while (iterate!=1) {
      // next iterate, 
	if (iterate%2==0)
	  iterate /=2;
	else
	  iterate = 3*iterate+1;
	count++;
    }
    // if longer than pre max, record
    if (count>length_of_longest) {
      length_of_longest = count;
      cout << "New record of " << length_of_longest << " at " << starting_point << '\n';
    }
  }

  return 0;
}
