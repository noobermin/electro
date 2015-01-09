#include "opts.cpp"
#include "noob3d/prim.hpp"
#include <vector>
#include <iostream>
#include "electro.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace noob3d;
using namespace electro;
typedef vector3d v3;
typedef scalar sc;

//physical/mathematical constants
using namespace electro::consts;
const double pi = M_PI;
const double m_e = 9.10938291e-28;
const double l = 8e-5;
const double T = l/c;
const double qmr = -e/m_e;
const double dt_factor = 100;
int
main(int argc, char* argv[])
{
  unsigned int N;
  double I,Et,Bt,Es,Bs,timestep;
  //reading in arguments
  DocoptArgs opts = docopt(argc,argv,true,"1.0");
  I = convert_arg(opts.intensity,"intensity",1e18)*1e7;
  const double E_0 = sqrt(4*pi*I/c);
  timestep = std::min(c/(2*abs(qmr)*E_0)/dt_factor, T/1e4);
  N = convert_arg(opts.periods,"periods",1) * int(T/timestep);
  Et= convert_arg(opts.ET,"ET",0.0);
  Es= convert_arg(opts.ET,"ES",1.5);
  Bt= convert_arg(opts.BT,"BT",0.0);
  Bs= convert_arg(opts.BS,"BS",1.5);

  //making fields lambda functions. The 2.0 is due to the standing wave forming
  //from constructive interference of two plane waves.
  auto E = [E_0,Et,Es](v3 r, sc t)
    {
      return v3(1,0,0)*2.0*E_0*cos(2*pi/l*c*t+pi*Et)*cos(2*pi/l*r.z+pi*Es);
    };
  auto B = [E_0,Bt,Bs](v3 r, sc t)
    {
      return v3(0,1,0)*2.0*E_0*cos(2*pi/l*c*t+pi*Bt)*cos(2*pi/l*r.z+pi*Bs);
    };
  //initializing simulation
  Electro electro(E,B,timestep);
  electro.add(v3(0,0,l/8),v3(), qmr);
  run_and_output(electro, N);
  return 0;
}

