#include <iostream>
using std::cout;

int update( int n ) {
 if (n%2==0) 
   return n/2;
 else
   return 3*n+1;
}

int length_of_sequence( int start ) {
  int count=0, current=start;
  while (current!=1) {
    if (current%2==0)
      current /= 2;
    else
      current = 3*current+1;
    count++;
  }
  return count;
}

int main() {

  int max_length=0;
  for (int starting_point=1; starting_point<1000; starting_point++) {
    int l = length_of_sequence( starting_point );
    if (l>max_length){
      max_length = l;
      cout << "New record of " << max_length << " at " << starting_point << '\n';
    }
  }
  return 0;
}
