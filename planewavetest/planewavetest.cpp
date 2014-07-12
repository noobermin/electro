#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#include "electro.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace noob3d;
typedef vector3d v3;
typedef scalar sc;

using namespace noob3d::consts;
const double pi = M_PI;
const double m_e = 9.10938291e-28;
//               800 nm          100 W/cm^2
const double lambda = 8e-5, E_0=sqrt(4*pi*1e25/c);

inline
scalar realphase(v3 r, sc t)
{ return cos(2*pi/lambda*(r.z-c*t));}

inline
scalar timephase(v3 r, sc t)
{ return cos(2*pi/lambda*(c*t));}


inline
v3 E(v3 r, sc t)
{
  return v3(1.0,0.0,0.0)*E_0*realphase(r,t);
}

inline
v3 B(v3 r, sc t)
{
  return v3(0.0,1.0,0.0)*E_0*realphase(r,t);
}

#define N 200000

int main()
{
  Electro electro(E,B,1e-19);
  electro.add(v3(),
	      v3(),
	      -e/m_e);
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

