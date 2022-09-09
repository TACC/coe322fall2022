#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "functions.cxx"

#include <vector>
using std::vector;

TEST_CASE( "coefficients represent polynomial", "[1]") {
  vector<double> coefficients = { 1.5, 0., -3 }; 
  REQUIRE( coefficients.size()>0 );
  REQUIRE( coefficients.front()!=0. );
}

TEST_CASE( "proper polynomial coefficients" ) {
  vector<double> coefficients = { 1.5, 0., -3 }; 
  REQUIRE( is_proper_polynomial( coefficients ) );
  vector<double> notcoefficients = { 0., -3 }; 
  REQUIRE( not is_proper_polynomial( notcoefficients ) );
}

TEST_CASE( "polynomial evaluation" ) {
  polynomial second{2,0,1};
  // correct interpretation: 2x^2 + 1
  REQUIRE( is_proper_polynomial(second) );
  REQUIRE( evaluate_at(second,2.) == Catch::Approx(9.) ); // wrong interpretation: 1x^2 + 2
  REQUIRE( evaluate_at(second,2.) != Catch::Approx(6.) );
}

// C-x i : insert file
