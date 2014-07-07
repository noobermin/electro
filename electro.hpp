#ifndef _ELECTRO_HPP_
#define _ELECTRO_HPP_

#include "noob3d/prim.hpp"
#include "noob3d/numer.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <utility>
#include <exception>
#include <cstdlib>
#include <cmath>

namespace noob3d {

  namespace consts
  {
#ifdef ELECTRO_USE_NATURAL
    const scalar c=1;
#else
    const scalar c=3e10;
#endif
  }

  struct particle
  {
    vector3d r,v; int id; scalar qmr;
  };


  typedef vector3d vector3d;
  static vector3d zerovector;

  class Electro
  {
    std::vector<particle> ps;
    scalar t;
    scalar dt;
    int ids;
    vector3d (*E)(vector3d,scalar);
    vector3d (*B)(vector3d,scalar);
    
    vector3d 
    _lorentz(vector3d r, vector3d v, scalar t, scalar qmr)
    {
      return (E(r,t)+cross(v,B(r,t)/consts::c))*qmr;
    }
    
    vector3d
    _relativistic_lorentz(vector3d r, vector3d v, scalar t, scalar qmr)
    {
      using namespace consts;
      scalar invgamma = squareRoot(1-(v/c).squareLength());
#ifdef ELECTRO_USE_NEWSCHEME
      matrix3d V(sq(c)-sq(v.y)-sq(v.z), v.x*v.y,               v.x*v.z,
		 v.y*v.x,               sq(c)-sq(v.x)-sq(v.z), v.y*v.z,
		 v.x*v.z,               v.y*v.z,               sq(c)-sq(v.x)-sq(v.y));
      V/=sq(c);
      V=inverse(V);
      V*=invgamma*invgamma*invgamma;
#else
      matrix3d V(sq(v.x), v.x*v.y, v.x*v.z,
		 v.y*v.x, sq(v.y), v.y*v.z,
		 v.x*v.z, v.y*v.z, sq(v.z));
      V/=(sq(c)-v.squareLength());
      V+=matrix3d(1,0,0,
		  0,1,0,
		  0,0,1);
      V=inverse(V);
      V*=invgamma;
#endif
      return V*_lorentz(r,v,t,qmr);
    }
  public:
    Electro(vector3d (*_E)(vector3d,scalar),
	    vector3d (*_B)(vector3d,scalar),
	    scalar idt=0.25) 
      : t(0.0), dt(idt), ids(0), E(_E),B(_B)
    {}
    void
    add(vector3d r, vector3d v, scalar qmr)
    {
      ps.push_back({r,v,ids++,qmr});
    }
    
    std::vector<scalar>
    step()
    {
      std::vector<scalar> out;
      out.push_back(t+dt);
      for(auto i = ps.begin(); i!=ps.end(); ++i)
	{
	  integrate::leapfrog(i->r,i->v, t, dt,
			      [i,this](vector3d r,vector3d v,scalar _t){
				return _relativistic_lorentz(i->r,i->v,_t,i->qmr);
			      });
	  out.push_back(i->r.x);
	  out.push_back(i->r.y);
	  out.push_back(i->r.z);
	  out.push_back(i->v.x);
	  out.push_back(i->v.y);
	  out.push_back(i->v.z);
	}
      t+=dt;
      return out;
    } 
  };
}//namespace noob3d

#endif //_ELECTRO_HPP_
