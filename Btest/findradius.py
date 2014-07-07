#!/usr/bin/env python2
'''usage: ./plotx.py <infile>'''
import numpy as np;
import cPickle;
from docopt import docopt;

opts=docopt(__doc__,help=True);
with open(opts['<infile>'],'rb') as f:
    d=cPickle.load(f);
t,r,v=d;

r[:] = [ np.array(l) for l in r]
v[:] = [ np.array(l) for l in v]
c=1.0;
B=1.0;
mn=r[0].min();
mx=r[0].max();
radius=(mx-mn)/2;
print("radius is {}".format(radius));
vm = np.sqrt(v[0]**2+v[1]**2+v[2]**2);
vm_mean = vm.mean();
invgamma = np.sqrt(1-(.25)/(c**2))
qmratio = 1.0
r_relativistic = c*vm_mean/(qmratio*B*invgamma);
r_classical = c*vm_mean/(qmratio*B);
print("while the theoretic radius should be {}".format(r_relativistic));
print("and classically, should be {}".format(r_classical));
