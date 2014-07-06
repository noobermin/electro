#!/usr/bin/env python2
'''usage: ./plotx.py <infile>'''
import matplotlib.pyplot as plt;
import numpy as np;
import cPickle;
from docopt import docopt;

opts=docopt(__doc__,help=True);
with open(opts['<infile>'],'rb') as f:
    d=cPickle.load(f);
r,v=d;
r[:] = [ np.array(i) for i in r];
v[:] = [ np.array(i) for i in v];
vm = np.sqrt(v[0]**2+v[1]**2+v[2]**2);

plt.scatter(np.arange(len(vm)),vm);
plt.xlabel("time step");
plt.ylabel("speed (cm/s)");
plt.show();
