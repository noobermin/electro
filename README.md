electro
=======

A basic test EM solver for test particles.


Usage / Configuration
---------------------
electro has no configuration save the "main" file.

The basic concept is that the type `Electro` represents the simulation. Its constructor has four arguments:
* A std::function to a function (subroutine) that gives the Electric Field as a function (mathematical) of spacetime
* A std::function to a function that gives the Magnetic Field as a function of spacetime
* The time step.
* A bool that declares whether threads will be used or not. Currently, each particle is stepped by its own thread. The default value is false.

Honestly, just look at electro.hpp. It is simple enough to read, I prefer to code this way.

The units used are cgs and natural units. To use natural units, define the macro `ELECTRO_USE_NATURAL` before the start including `electro.hpp`.

`Electro` has two public methods of interest, the first is `add`. Use this to add particles into the simulation. The second method is `step`, which advances the simulation in time. This returns a vector of first a timestamp, position, and then velocities, from x to z in that order, for each particle in queue order to when they were appended by `add`.

Technical
---------
Mostly everything I wrote (haven't attached a copyright yet, this isn't quite heavy stuff, though).
The lorentz force is integrated using the so called "leapfrog" algorithm. See noob3d/numer.hpp for details. Yes, it is relativistic ;)