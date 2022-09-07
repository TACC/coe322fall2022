#include "function.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "test that f always returns positive" ) {
  for ( int n=-1000; n<10000; n++)
    REQUIRE( f(n)>0 );
}

TEST_CASE( "increment function" ) {
  for (int n=1; n<1000; n++) 
    REQUIRE( increment_positive_only(n)==n+1 );
}

// C-n : next line
// C-p : previous line
// C-f C-b : for/back character

// C-x C-f find other file
// C-x b   switch to other buffer

// C-x 3 : split window horizontally
// C-x 2 : same vertically
// C-x o : go other panel
