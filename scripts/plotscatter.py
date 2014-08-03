#!/usr/bin/env python2
'''
Generate a 3d scatter plot of the first particle.

Usage:
  ./plotscatter.py [options] <infile>
  ./plotscatter.py [options]

Options:
  -s STEP           Step by STEP amount
  -e END            End at END

'''
import matplotlib.pyplot as plt;
import numpy as np;
from mpl_toolkits.mplot3d import Axes3D
import cPickle;
import sys;
from docopt import docopt;

opts=docopt(__doc__,help=True);
if opts['<infile>']:
    with open(opts['<infile>'],'rb') as f:
        t,d=cPickle.load(f);
else:
    t,d = cPickle.loads(sys.stdin.read());
r,v=d;

end  = int(opts['-e']) if opts['-e'] else None;
step = int(opts['-s']) if opts['-s'] else None;

x,y,z = r[:] = [ np.array(l[:end:step]) for l in r]
fig = plt.figure(1);
ax = fig.add_subplot(111,projection='3d');
ax.scatter(x,y,z,marker='o',label='r',c='b');
plt.show();
