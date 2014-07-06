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
    const scalar c=3e10;
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
      scalar invsqgamma = (1-(v/consts::c).squareLength());
      matrix3d V(v.x*v.x, v.x*v.y, v.x*v.z,
		 v.y*v.x, v.y*v.y, v.y*v.z,
		 v.x*v.z, v.y*v.z, v.z*v.z);
      V/=invsqgamma;
      V+= matrix3d(1,0,0,
		   0,1,0,
		   0,0,1);
      V = inverse(V);
      V*=squareRoot(invsqgamma);
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
    
    std::vector<vector3d>
    step()
    {
      std::vector<vector3d> out;
      for(auto i = ps.begin(); i!=ps.end(); ++i)
	{
	  integrate::leapfrog(i->r,i->v, t, dt,
			      [i,this](vector3d r,vector3d v,scalar _t){
				//return _lorentz(i->r,i->v,_t,i->qmr);
				return _relativistic_lorentz(i->r,i->v,_t,i->qmr);
			      });
	  out.push_back(i->r);
	  out.push_back(i->v);
	}
      return out;
    } 
  };
}//namespace noob3d

#endif //_ELECTRO_HPP_
