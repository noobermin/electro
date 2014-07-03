#ifndef _NOOB3D_NUMER_H
#define _NOOB3D_NUMER_H

#include "prim.hpp"
#include <iostream>
namespace noob3d
{
  namespace integrate
  {
    //as a note, BinaryHomotopy should be
    // Value (Value r, Value v ,scalar t)
    //and a Homotopy is just
    // Value (Value r, scalar t).

  
    //////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////
    //runge-kutta 4th order implementation
    template <typename T,class BinaryHomotopy> void
    rk4_sample(const T &ri,  //initial displacement
	       const T &vi,  //initial momentum
	       T &dr,         //displacement differential (output)
	       T &dv,         //velocity differential (output)
	       scalar t,      //parametrization (time)
	       BinaryHomotopy f)//force
    {
      dr = vi;
      dv = f(ri, vi, t);
    }

    /*
     * rk4 
     *
     * integrate a step of a second order differential equation;
     *   dr/dt = v,
     *   dv/dt = f(r,v,t);
     * using runge-kutta 4th order method. 
     */
    template<typename T, class BinaryHomotopy> void
    rk4(T &r,          //r
	T &v,          //r-dot
	scalar t,      //parametrization (time)
	scalar dt,     //timestep
	BinaryHomotopy f)//Right hand side of the acceleration equation.
    {
      T 
	rk1,rk2,rk3,rk4,
	vk1,vk2,vk3,vk4;
      rk4_sample(r,             v,             rk1, vk1, dt,       f);
      rk4_sample(r + rk1*t/2.0, v + vk1*t/2.0, rk2, vk2, t+dt/2.0, f);
      rk4_sample(r + rk2*t/2.0, v + vk2*t/2.0, rk3, vk3, t+dt/2.0, f);
      rk4_sample(r + rk3*t,     v + vk3*t,     rk4, vk4, t+dt,     f);
      
      v += (vk1/6.0 + vk2/3.0 + vk3/3.0 + vk4/6.0)*dt;
      r += (rk1/6.0 + rk2/3.0 + rk3/3.0 + rk4/6.0)*dt;
      return;
    }
    template<typename T, class BinaryHomotopy> void
    rk4(const T &ri,   //r input
	const T &vi,   //r-dot input
	T &ro,         //r output
	T &vo,         //r-dot (output)
	scalar t,      //parametrization (time)
	scalar dt,     //timestep
	BinaryHomotopy f)//Right hand side of the acceleration equation.
    {
      T 
	rk1,rk2,rk3,rk4,
	vk1,vk2,vk3,vk4;
      rk4_sample(ri,             vi,             rk1, vk1, t,        f);
      rk4_sample(ri + rk1*t/2.0, vi + vk1*t/2.0, rk2, vk2, t+dt/2.0, f);
      rk4_sample(ri + rk2*t/2.0, vi + vk2*t/2.0, rk3, vk3, t+dt/2.0, f);
      rk4_sample(ri + rk3*t,     vi + vk3*t,     rk4, vk4, t+dt,     f);
      
      ro = ri+(vk1/6.0 + vk2/3.0 + vk3/3.0 + vk4/6.0)*dt;
      vo = vi+(rk1/6.0 + rk2/3.0 + rk3/3.0 + rk4/6.0)*dt;
      return;
    }
    
    //////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////
    //leap frog implementation
    /*
     * leapfrog_integrate 
     *
     * integrate a step of a second order differential equation;
     *   dr/dt = v,
     *   dv/dt = f(r,v,t);
     * using leap frog algorithm.
     */
    template<typename Value,class Homotopy> void
    leapfrog(Value &r,          //r
	     Value &v,          //r-dot
	     scalar t,      //parametrization (time)
	     scalar dt,     //timestep
	     Homotopy f)//Right hand side of the acceleration equation.
    {
      Value a1 = f(r,v,t);
      r += (v + a1*dt/2.0)*dt;
      Value a2 = f(r,v,t+dt);
      v += (a1+a2)/2.0*dt;
      return;
    }
    
    template<typename Value,class Homotopy> void
    leapfrog(const Value &ri,    //r
	     const Value &vi,   //r-dot
	     Value &ro,         //r output
	     Value &vo,         //r-dot output
	     scalar t,      //parametrization (time)
	     scalar dt,     //timestep
	     Homotopy f)//Right hand side of the acceleration equation.
    {
      Value a1 = f(ri,t);
      ro = ri + (vi + a1*dt/2.0)*dt;
      Value a2 = f(ro,t+dt);
      vo = vi + (a1+a2)/2.0*dt;
      return;
    }
  }//namespace integrate
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  
  //differentiation implementations
  namespace diff{

    //worst derivative
    template<typename Function, typename Value> 
    Value linear(Function f, scalar t1, scalar  t2)
    {
      return (f(t2)-f(t1))/(t2-t1);
    }
    //3 point averaging
    template<typename Function, typename Value> 
    Value avg_3p(Function f, scalar t0, scalar t1, scalar t2)
    { 
      return ( (f(t0)-f(t1))/(x0-x1)+(f(t1)-f(t2))/(x1-x2) )/2.0;
    }
    
  }//namespace diff

}// namespace noob3d
#endif /*_NOOB3D_NUMER_HPP_*/