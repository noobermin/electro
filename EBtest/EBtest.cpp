#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#define ELECTRO_USE_NATURAL
#include "electro.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using namespace noob3d;
typedef vector3d v3;
typedef scalar sc;
const double pi = M_PI;

#define N 4000

int main()
{
  auto E = [](v3 r, sc t)    
    { return v3(0,   0, 1); };
  auto B = [](v3 r, sc t)
    { return v3(2*pi,0, 0); };
  
  Electro electro(E,B,1e-3);
  electro.add(v3(),
	      v3(),
	      1.0);
  run_and_output(electro,N);
  return 0;
}

