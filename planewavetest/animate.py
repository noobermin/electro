#!/usr/bin/env python2
'''
Usage: ./animate.py [options] <infile>

Options:
  -e END        read to index END
  -s STEP       read with STEP
'''
import matplotlib.pyplot as plt;
import matplotlib.animation as anim;
import numpy as np;
import cPickle;

from docopt import docopt;

opts=docopt(__doc__,help=True);
if opts['-e']:
    end = int(opts['-e']);
else:
    end = None;
if opts['-s']:
    step = int(opts['-s']);
else:
    step = None;
lm = 8e-5;
c = 2.999792458e10;
E_0 = np.sqrt(4*np.pi*1e25/c);
phi = np.pi/2;
with open(opts['<infile>'],'rb') as f:
    d=cPickle.load(f);
t,r,v=d;
x,y,z = r;
x = np.array(x[:end:step]);
z = np.array(z[:end:step]);
t = np.array(t[:end:step]);

zmin = z.min();
zmax = z.max();
xmin = x.min();
xmax = x.max();

X,Z = np.mgrid[ xmin : xmax : 20j,
                zmin : zmax : 20j];
v = np.zeros(Z.shape);
u = np.sin(2*np.pi*Z/lm+phi)*E_0;
#initial plotting
fig = plt.figure();
ax = fig.add_subplot(111);
p, = ax.plot(x[0:1],z[0:1],marker='o',label='r',c='r');
q = ax.quiver(X,Z,u,v);
ax.set_ylim(z.min(),z.max());
ax.set_xlim(x.min(),x.max());

def animate(ii):
    i,t=ii;
    u = np.sin(2*np.pi*Z/lm -2*np.pi/lm*c*t+phi)*E_0;
    p.set_data(x[0:i],z[0:i]);
    q.set_UVC(u,v);
    return p,q;

ts = list(enumerate(t));
a = anim.FuncAnimation(fig,animate, ts, interval=0.01);
plt.show();
