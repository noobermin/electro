#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#define _USE_NATURAL
#define _USE_NEWSCHEME
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
  return v3(0.0,0.0,1.0);
}

#define N 6000000

int main()
{
  Electro electro(E,B,1e-6);
  electro.add(v3(),
	      v3(1.0,0.0,0.0)*0.5,
	      1.0);
  for(int i=0;i<N; ++i)
    {
      std::vector<sc> c = electro.step();
      if(!(0 && i%100))
	{
	  std::cout << c[0] << ":";
	  for(auto j=c.begin()+1;j!=c.end();j+=3)
	    std::cout<< *j <<","<<*(j+1)<<","<<*(j+2)<<" ";
	  std::cout << std::endl;
	}
    }
  return 0;
}

