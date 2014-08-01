#!/usr/bin/env python2
'''
Check the if the particles do not exceed c.

Usage:
  ./txt2pickle [options] <infile>
  ./txt2pickle [options]

Options:
  --natural-units -n        Use natural units instead of cgs.
'''
from docopt import docopt;
import numpy as np;
import cPickle;
import fileinput;
import itertools as itools;
import sys;

opts=docopt(__doc__,help=True);
c = 1.0 if opts['--natural-units'] else 2.99792458e10;

if opts['<infile>']:
    with open(opts['<infile>'],'rb') as f:
        t,d=cPickle.load(f);
else:
    t,d = cPickle.loads(sys.stdin.read());

errmsg = "exceeded speed of light at time {} s of particle {} (speed is {}, v-c={})"

for i,v in enumerate(d[1::2]):
    v = np.array(v);
    v_m = np.sqrt(v[0]**2+v[1]**2+v[2]**2);
    import matplotlib.pyplot as plt;
    plt.hist(v_m,bins=100);
    plt.show();
    for cv_m,ct in itools.izip(v_m,t):
        if cv_m > c:
            print(errmsg.format(ct,i,cv_m,cv_m-c));
        pass;
pass;
