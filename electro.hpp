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

namespace electro {
  using namespace noob3d;
  namespace consts
  {
#ifdef ELECTRO_USE_NATURAL
    const scalar c=1.0;
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
    vector3d b = v/c;
    matrix3d V(1-sq(b.x),  -b.x*b.y, -b.x*b.z,
	       -b.y*b.x,  1-sq(b.y), -b.y*b.z,
	       -b.x*b.z,   -b.y*b.z, 1-sq(b.z));
    return V*lorentz(r,v,t,qmr,E,B) * squareRoot(1-b.squareLength());
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
    template <typename T> void
    out_step(std::vector<scalar>& out, T p)
    {
      out.push_back(p.r.x);
      out.push_back(p.r.y);
      out.push_back(p.r.z);
      out.push_back(p.v.x);
      out.push_back(p.v.y);
      out.push_back(p.v.z);
    }
    
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
      //sort by i;
      for(int i=0; i!=ps.size(); ++i)
	pool.push_back(std::thread(f, std::ref(ps[i]), std::ref(_out[i])));
      for(std::thread &t : pool)
	if(t.joinable()) t.join();
      for (output_data d: _out)
	out_step(out,d);
      return;
    }
    
    void
    step_linear(std::vector<scalar>& out)
    {
      for(particle &p : ps)
	{
	  integrate::leapfrog(p.r, p.v, t, dt,
			      [p,this](vector3d r,vector3d v,scalar _t)
			      {return relativistic_lorentz(p.r,p.v,_t,p.qmr,E,B);});
	  out_step(out,p);
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
    for(int i=0;i<N; ++i)
    {
      std::vector<scalar> c = electro.step();
      std::cout << c[0] << ":";
      for(auto j=c.begin()+1;j!=c.end();j+=6)
	std::cout << *j <<","<<*(j+1)<<","<<*(j+2)<<" "
		  <<*(j+3) <<","<<*(j+4)<<","<<*(j+5)
		  << ( j+6 != c.end() ? ";" : "");
      std::cout << std::endl;
    }
  }
}//namespace noob3d

#endif //_ELECTRO_HPP_
