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
//               800 nm          1e18 W/cm^2
const double lambda = 8e-5, E_0=sqrt(4*pi*1e25/c);
const double timestep = 1e-19;
const int steps_per_period = int(lambda/c/timestep);

inline
scalar time_p(sc t)
{ return cos(2*pi/lambda*(c*t));}

inline
scalar space_p(v3 r,sc phi=0.0)
{ return cos(2*pi/lambda*(r.z)+phi);}


inline
v3 E(v3 r, sc t)
{
  return v3(0.0,1.0,0.0)*E_0*time_p(t)*space_p(r,pi/2);
}

inline
v3 B(v3 r, sc t)
{
  return v3(1.0,0.0,0.0)*E_0*time_p(t)*space_p(r);
}


void range_add(Electro& electro, 
	       v3 r_min, v3 r_max,
	       v3 v_min, v3 v_max,
	       sc qmr,
	       unsigned int n)
{
  std::random_device g;
  std::uniform_real_distribution<scalar> 
    d_rx(r_min.x, r_max.x),
    d_ry(r_min.y, r_max.y),
    d_rz(r_min.z, r_max.z),

    d_vr(v_min.x, v_max.x),//really r
    d_vth(v_min.y, v_max.y),//really theta
    d_vphi(v_min.z, v_max.z);//phi
  ++n;
  while(n--)
    {
      v3 r(d_rx(g),d_ry(g),d_rz(g));
      sc phi = d_vphi(g), th = d_vth(g);
      v3 v(sin(th)*cos(phi),sin(th)*sin(phi),cos(th));
      v*=d_vr(g)*c;
      electro.add(r,v,qmr);
    }
  return;
}

int
main(int argc, char* argv[])
{
  unsigned int n, N=steps_per_period;
  process_args(argc,argv,n,N);
  //initializing simulation
  Electro electro(E,B,timestep,true);
  range_add(electro, 
	    v3(), v3(2*lambda,2*lambda,2*lambda),
	    v3(), v3(0.999,pi,2*pi),
	    -e/m_e,
	    n);
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

