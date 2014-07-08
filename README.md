electro
=======

A basic test EM solver for test particles.


Usage / Configuration
---------------------
electro has no configuration save the "main" file.

The basic concept is that the type `Electro` represents the simulation. Its constructor has four arguments:
* A function pointer to a function (subroutine) that gives the Electric Field as a function (mathematical) of spacetime
* A function pointer to a function that gives the Magnetic Field as a function of spacetime
* The time step.
* A bool that declares whether threads will be used or not. Currently, each particle is stepped by its own thread.

The units used are cgs and natural units. To use natural units, define the macros ELECRO_USE_NATURAL before the start including `electro.hpp`.

`Electro` has two public methods of interest, the first is `add`. Use this to add particles into the simulation. The second method is `step`, which advances the simulation in time. This (currently) returns a vector of position and velocity pairs, in queue order to when they were appended by `add`.

Technical
---------
Mostly everything I wrote (haven't attached a copyright yet, this isn't quite heavy stuff, though).
The lorentz force is integrated using the so called "leapfrog" algorithm. See noob3d/numer.hpp for details. Yes, it is relativistic ;)