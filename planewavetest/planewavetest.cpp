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

#define N 200000

int main()
{
  auto E = [](v3 r, sc t)
    {
      return v3(1,0,0)*2.0*E_0*cos(2*pi/lambda*(r.z-c*t));
    };
  auto B = [](v3 r, sc t)
    {
      return v3(0,1,0)*2.0*E_0*cos(2*pi/lambda*(r.z-c*t));
    };
  Electro electro(E,B,1e-19);
  electro.add(v3(),
	      v3(),
	      -e/m_e);
  run_and_output(electro,N);
  return 0;
}

