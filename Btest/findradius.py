#!/usr/bin/env python2
'''usage: ./plotx.py <infile>'''
import numpy as np;
import cPickle;
from docopt import docopt;

opts=docopt(__doc__,help=True);
with open(opts['<infile>'],'rb') as f:
    d=cPickle.load(f);
r,v=d;

r[:] = [ np.array(l[::10]) for l in r]
v[:] = [ np.array(l[::10]) for l in v]
mn=r[0].min();
mx=r[0].max();
radius=(mx-mn)/2;
print("radius is {}".format(radius));
vm = np.sqrt(v[0]**2+v[1]**2+v[2]**2);
vm_mean = vm.mean();
gamma = 1/np.sqrt(1-vm_mean**2/9e20)
qmratio = 1.0 /gamma;
r_theory = 3e10*vm_mean/(qmratio*1.0e9)

print("while the theoretic radius should be {}".format(r_theory));
