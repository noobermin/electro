#!/usr/bin/env python2
'''
Extract the p_z at lm/4 (the E node).

Usage:
  ./extractpf.py [options] <infile>
  ./extractpf.py [options]

Options:
  --stop=STOP    Read the z momentum at z=STOP instead of p_z=lm/4.
  --lambda=LM    Use wavelength LM instead of 8e-5 cm.
  --intensity=I  Use the intensity of I W/cm^2 instead of 1e18 W/cm^2
'''

import math as m;
import matplotlib.pyplot as plt;
import matplotlib.animation as anim;
import numpy as np;
import cPickle;
import sys;
import itertools as itools;
from docopt import docopt;

#arguments
opts=docopt(__doc__,help=True);
lm   = float(opts['--lambda']) if opts['--lambda'] else 8e-5;
I    = float(opts['--intensity']) if opts['--intensity'] else 1e18;
stop = float(opts['--stop']) if opts['--stop'] else lm/4;
#IMPORTANT: we use cgs here.
c   = 2.99792458e10;
m_e = 9.10938291e-28;
#reading in file or from stdin.
if opts['<infile>']:
    with open(opts['<infile>'],'rb') as f:
        t,d=cPickle.load(f);
else:
    t,d=cPickle.loads(sys.stdin.read());
#zip into r,v pairs.
datapairs = zip(d[::2],d[1::2]);
#for each r,v in a pair
for r,v in itools.izip(d[::2],d[1::2]):
    x,y,z = r;
    vx,vy,vz = v;
    #finding the one closest to z=lm/4.
    dz=np.abs(np.array(z)-stop);
    z,vx,vy,vz = sorted(zip(dz,vx,vy,vz), key=lambda x: x[0])[0];
    #calculating and printing out the x momenum.
    pz  = 1.0/m.sqrt(1-(vx**2+vy**2+vz**2)/c**2)*vz/c;
    a_0 = m.sqrt(I/1.37e18)*.8;
    print('{} {}'.format(I,pz/a_0));
