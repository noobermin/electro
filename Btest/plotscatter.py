#!/usr/bin/env python2
'''usage: ./plotx.py <infile>'''
import matplotlib.pyplot as plt;
import numpy as np;
from mpl_toolkits.mplot3d import Axes3D
import cPickle;
from docopt import docopt;

opts=docopt(__doc__,help=True);
with open(opts['<infile>'],'rb') as f:
    d=cPickle.load(f);
r,v=d;

r[:] = [ l[::10] for l in r]
fig = plt.figure(1);
ax = fig.add_subplot(111,projection='3d');
ax.scatter(r[0],r[1],r[2],marker='o',label='r',c='b');
plt.show();
