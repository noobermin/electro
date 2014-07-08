#include "noob3d/prim.hpp"
#include <vector>
#include <tuple>
#include <utility>
#include <iostream>
#define _USE_NATURAL
#define _USE_NEWSCHEME
#include "electro.hpp"
#include <random>

using namespace noob3d;
typedef vector3d v3;
typedef scalar sc;

inline
v3 E(v3 r, sc t)
{
  return v3();
}

inline
v3 B(v3 r, sc t)
{
  return v3(0.0,0.0,1.0);
}

#define N 600

void range(Electro& electro, 
	   v3 r_min, v3 r_max,
	   v3 v_min, v3 v_max,
	   unsigned int n)
{
  std::random_device g;
  std::uniform_real_distribution<scalar> 
    d_rx(r_min.x, r_max.x),
    d_ry(r_min.y, r_max.y),
    d_rz(r_min.z, r_max.z),

    d_vx(v_min.x, v_max.x),
    d_vy(v_min.y, v_max.y),
    d_vz(v_min.z, v_max.z);
  ++n;
  while(n--)
    electro.add(v3(d_rx(g),d_ry(g),d_rz(g)),
		v3(d_vx(g),d_vy(g),d_vz(g)),
		1.0);
  return;
}

int main()
{
  Electro electro(E,B,1e-6,true);
  range(electro,
	v3(), v3(),
	v3(), v3(0.99,0.0,0.0),
	20);
  for(int i=0;i<N; ++i)
    {
      std::vector<sc> c = electro.step();
      if(!(1 || i%100))
	{
	  std::cout << c[0] << ":";
	  for(auto j=c.begin()+1;j!=c.end();j+=3)
	    std::cout<< *j <<","<<*(j+1)<<","<<*(j+2)<<" ";
	  std::cout << std::endl;
	}
    }
  return 0;
}

