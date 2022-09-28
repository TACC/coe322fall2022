/****************************************************************
 * This is file optdemo.cxx
 * 
 * Assume that in the same directory you install the cxxopts package:

  wget https://github.com/jarro2783/cxxopts/archive/refs/tags/v3.0.0.tar.gz
  tar fxz v3.0.0.tar.gz
  cd cxxopts-3.0.0/
  mkdir build
  cd build
  CXX=icpc cmake ..
  make
  cd ../..

  You can then compile this file with:
  
  icpc -o demo optdemo.cxx -I cxxopts-3.0.0/include

  (if you install it elsewhere you need to update the include path)
  and try out options with:

  ./demo
  ./demo -h
  ./demo -n 
  ./demo -n 10
  ./demo -n 10 foo

  and study the (error) messages
 ****************************************************************/

#include <iostream>
using std::cout;
#include <string>
using std::string;

#include "cxxopts.hpp"

int main( int argc,char **argv ) {
  cxxopts::Options options
    ("optdemo", "Commandline options demo");
  // help option
  options.add_options() 
    ("h,help","usage information");
  // int option
  options.add_options()
    ("n,ntimes","number of times",
     cxxopts::value<int>()->default_value("37")
     ) ;
  options.add_options()
    ("keyword","whatever keyword",
     cxxopts::value<string>()) ;
  options.parse_positional({"keyword"});

  // Parse the commandline!
  auto result = options.parse(argc, argv);

  // act on the options that were used
  if (result.count("help")>0) {
    cout << options.help() << '\n';
    return 0;
  }
  // read out ‘-n’ option and use:
  auto number_of_times = result["ntimes"].as<int>();
  cout << "Using number of times: " << number_of_times << '\n';

  // read the positional keyword:
  auto keyword = result["keyword"].as<string>(); 
  cout << "Found keyword: " << keyword << '\n';

  return 0;
}
