#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#include "electro.hpp"

using namespace noob3d;
typedef vector3d v3;
typedef scalar sc;

inline
v3 E(v3 r, sc t)
{
  return v3();//v3(1.0,0.0,0.0)*1.0e9;
}
inline
v3 B(v3 r, sc t)
{
  return v3(0.0,0.0,1.0)*1.0e9;
}

#define N 200000
int main()
{
  Electro electro(E,B,0.001);
  electro.add(v3(),
	      v3(1.0,0.0,0.0)*1.5e10,
	      1.0);
  for(int i=0;i<N; ++i)
    {
      std::vector<v3> c = electro.step();
      for(auto j: c)
	std::cout<<j.x<<","<<j.y<<","<<j.z<<" ";
      std::cout << std::endl;
    }
}

