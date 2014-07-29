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

inline
v3 E(v3 r, sc t)
{
  return v3(0.0,0.0,1.0);
}
inline
v3 B(v3 r, sc t)
{
  return v3(2*pi,0.0,0.0);
}

#define N 4000

int main()
{
  Electro electro(E,B,1e-3);
  electro.add(v3(),
	      v3(),
	      1.0);
  for(int i=0;i<N; ++i)
    {
      std::vector<sc> c = electro.step();
      std::cout << c[0] << ":";
      for(auto j=c.begin()+1;j!=c.end();j+=3)
	std::cout<< *j <<","<<*(j+1)<<","<<*(j+2)<<" ";
      std::cout << std::endl;
    }
  return 0;
}

