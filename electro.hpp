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
#include <thread>
#include <functional>

namespace noob3d {
  namespace consts
  {
#ifdef ELECTRO_USE_NATURAL
    const scalar c=1;
    const scalar e=0.302822;
#else
    const scalar c=2.99792458e10;
    const scalar e=4.80320425e-10;
#endif
  }
  struct particle
  {
    vector3d r,v; scalar qmr; unsigned int id;
  };
  typedef std::function<vector3d(vector3d,scalar)> FieldFunc;

  static vector3d zerovector;

  inline vector3d 
  lorentz(vector3d r, vector3d v, scalar t, scalar qmr,
	  FieldFunc E, FieldFunc B)
  {
    return (E(r,t)+cross(v,B(r,t)/consts::c))*qmr;
  }
  inline vector3d
  relativistic_lorentz(vector3d r, vector3d v, scalar t, scalar qmr,
		       FieldFunc E, FieldFunc B)
  {
    using namespace consts;
    scalar invgamma = squareRoot(1-(v/c).squareLength());
    matrix3d V(sq(c)-sq(v.y)-sq(v.z), v.x*v.y,               v.x*v.z,
	       v.y*v.x,               sq(c)-sq(v.x)-sq(v.z), v.y*v.z,
	       v.x*v.z,               v.y*v.z,               sq(c)-sq(v.x)-sq(v.y));
    V/=sq(c);
    V=inverse(V);
    V*=invgamma*invgamma*invgamma;
    return V*lorentz(r,v,t,qmr,E,B);
  }

  class Electro
  {
    std::vector<particle> ps;
    scalar t;
    scalar dt;
    unsigned int ids;
    FieldFunc E,B;
    void (Electro::*actual_step)(std::vector<scalar>&);
  protected:
    void
    step_threaded(std::vector<scalar>& out)
    {
      struct output_data
      {
	vector3d r,v;
      };
      std::vector<output_data> _out(ps.size());
      std::vector<std::thread> pool;
      auto f = [this](particle &p, output_data &d)
	{
	  integrate::leapfrog(p.r,p.v, t, dt,
			      [p,this](vector3d r,vector3d v,scalar _t)
	{return relativistic_lorentz(p.r,p.v,_t,p.qmr,E,B);});
	  d.r=p.r;
	  d.v=p.v;
	};
      for(int i=0; i!=ps.size(); ++i)
	pool.push_back(std::thread(f, std::ref(ps[i]), std::ref(_out[i])));
      for(std::thread &t : pool)
	if(t.joinable()) t.join();
      for (output_data d: _out)
	{
	  out.push_back(d.r.x);
	  out.push_back(d.r.y);
	  out.push_back(d.r.z);
	  out.push_back(d.v.x);
	  out.push_back(d.v.y);
	  out.push_back(d.v.z);
	}
      return;
    }
    
    void
    step_linear(std::vector<scalar>& out)
    {
      for(auto i = ps.begin(); i!=ps.end(); ++i)
	{
	  integrate::leapfrog(i->r,i->v, t, dt,
			      [i,this](vector3d r,vector3d v,scalar _t)
			      {return relativistic_lorentz(i->r,i->v,_t,i->qmr,E,B);});
	  out.push_back(i->r.x);
	  out.push_back(i->r.y);
	  out.push_back(i->r.z);
	  out.push_back(i->v.x);
	  out.push_back(i->v.y);
	  out.push_back(i->v.z);
	}
      return;
    }
  public:
    Electro(FieldFunc _E,
	    FieldFunc _B,
	    scalar idt=0.25,
	    bool ithreading=false)
      : t(0.0), dt(idt), ids(0), E(_E), B(_B),
	actual_step( ithreading ? 
          &Electro::step_threaded 
        : &Electro::step_linear )
    {}
    void
    add(vector3d r, vector3d v, scalar qmr)
    {
      ps.push_back({r,v,qmr,ids++});
    }
    std::vector<scalar>
    step()
    {
      std::vector<scalar> out;
      out.push_back(t+dt);
      (this->*(actual_step))(out);
      t+=dt;
      return out;
    }
  };//class Electro
  
  inline
  void run_and_output(Electro& electro, int N)
  {
    //why is this not a member function? Because I do not mean to not
    //have Electro be inherited. Output code will change as my needs change
    //and I prefer to deal with that by writing a new function, not inheritance.
    //Why? Because I'm a generic man, not a OOP man. FFS, if anyone will ever 
    //care about this childish sim they should add it themselves.
    for(int i=0;i<N; ++i)
    {
      std::vector<scalar> c = electro.step();
      std::cout << c[0] << ":";
      for(auto j=c.begin()+1;j!=c.end();j+=3)
	std::cout<< *j <<","<<*(j+1)<<","<<*(j+2)<<" ";
      std::cout << std::endl;
    }
  }
}//namespace noob3d

#endif //_ELECTRO_HPP_
