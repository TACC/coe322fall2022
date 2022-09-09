#include <vector>
using std::vector;

using polynomial = vector<double>;

bool is_proper_polynomial( vector<double> coeff ) {
  return coeff.size()>0 and coeff.front()!=0.;
}

double evaluate_at( polynomial coeff,double x ) {
  double xpower=1., result=0.;
  for (int i=coeff.size()-1; i>=0; i--) {
    auto c = coeff.at(i);
    result += c * xpower;
    xpower *= x;
  }
  return result;
}
