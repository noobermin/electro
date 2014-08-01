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
//const double T =
const double l = 8e-5;

int
main(int argc, char* argv[])
{
  const double timestep = 1e-21;
  unsigned int N;
  double I,Et,Bt,Es,Bs;
  //reading in arguments
  DocoptArgs opts = docopt(argc,argv,true,"1.0");
  I = convert_arg(opts.intensity,"intensity",1e18)*1e7;
  N = convert_arg(opts.periods,"periods",1)*int(l/c/timestep);
  Et= convert_arg(opts.ET,"ET",1.0/2.0);
  Es= convert_arg(opts.ET,"ES",1.0/2.0);
  Bt= convert_arg(opts.BT,"BT",0.0);
  Bs= convert_arg(opts.BS,"BS",0.0);
  

  double E_0 = sqrt(4*pi*I/c);
  //making fields lambda functions. The 2.0 is due to the standing wave forming
  //from constructive interference of two plane waves.
  auto E = [E_0,Et,Es](v3 r, sc t)
    {
      return v3(1,0,0)*2.0*E_0*sin(2*pi/l*c*t+pi*Et)*sin(2*pi/l*r.z+pi*Es);
    };
  auto B = [E_0,Bt,Bs](v3 r, sc t)
    {
      return v3(0,1,0)*2.0*E_0*sin(2*pi/l*c*t+pi*Bt)*sin(2*pi/l*r.z+pi*Bs);
    };
  //initializing simulation
  Electro electro(E,B,timestep);
  //adding four starting points.
  //electro.add(v3(0,0,0   ),v3(),-e/m_e);
  //electro.add(v3(0,0,l/16),v3(),-e/m_e);
  electro.add(v3(0,0,l*2/16),v3(),-e/m_e);
  //electro.add(v3(0,0,3/16),v3(),-e/m_e);
  run_and_output(electro, N);
  return 0;
}

