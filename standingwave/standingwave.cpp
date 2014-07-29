#include "opts.cpp"
#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#include "electro.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace noob3d;
typedef vector3d v3;
typedef scalar sc;

//physical/mathematical constants
using namespace noob3d::consts;
const double pi = M_PI;
const double m_e = 9.10938291e-28;
const double l = 8e-5;
const double timestep = 1e-19;
const int steps_per_period = int(l/c/timestep);

int
main(int argc, char* argv[])
{
  unsigned int N=steps_per_period;
  double I = 1e7;
  //reading in arguments
  process_args(argc,argv,I,N);
  double E_0 = sqrt(4*pi*I/c);
  //making fields lambda functions. The 2.0 is due to the standing wave forming
  //from constructive interference of two plane waves.
  auto E = [E_0](v3 r, sc t)
    {
      return v3(2.0,0.0,0.0)*E_0*cos(2*pi/l*c*t)*cos(2*pi/l*r.z);
    };
  auto B = [E_0](v3 r, sc t)
    {
      return v3(0.0,2.0,0.0)*E_0*sin(2*pi/l*c*t)*sin(2*pi/l*r.z);
    };
  //initializing simulation
  Electro electro(E,B,timestep);
  electro.add(v3(0,0,l/8.0),v3(),-e/m_e);
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

