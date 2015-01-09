#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#define ELECTRO_USE_NATURAL
#define _NEW_SCHEME
#include "electro.hpp"

using namespace noob3d;
using namespace electro;
typedef vector3d v3;
typedef scalar sc;

#define N 100000

int main()
{
  auto E = [](v3 r, sc t)    
    { return v3(0,0,0); };
  auto B = [](v3 r, sc t)
    { return v3(1,0,0); };
  
  Electro electro(E,B,1e-4);
  electro.add(v3(),
	      v3(0.0,0.0,1.0)*0.5,
	      1.0);
  run_and_output(electro,N);
  return 0;
}

