#!/usr/bin/env python2
'''
Animate for standing wave output.

Usage:
  ./animate.py [options] <infile>
  ./animate.py [options]

Options:
  -e END        Read to index END.
  -s STEP       Read with STEP.
  -o OUTPUT     Output to OUTPUT, if not chosen, just display.
  --ETphase=ET  Set time phase of the electric field to ET.
  --BTphase=BT  Set time phase of the magnetic field to BT.
  --ESphase=ES  Set time phase of the electric field to ES.
  --BSphase=BS  Set time phase of the magnetic field to BS.
  --no-B        Don't plot the B-field.
'''
import math as m;
import matplotlib.pyplot as plt;
import matplotlib.animation as anim;
import numpy as np;
import cPickle;
import sys;
from docopt import docopt;

#arguments
opts=docopt(__doc__,help=True);
end  = int(opts['-e']) if opts['-e'] else None;
step = int(opts['-s']) if opts['-s'] else None;
output = opts['-o'];
if opts['<infile>']:
    with open(opts['<infile>'],'rb') as f:
        t,d=cPickle.load(f);
else:
    t,d=cPickle.loads(sys.stdin.read())

lm = 8e-5;
c = 2.999792458e10;
E_0 = np.sqrt(4*np.pi*1e25/c);
Etphi = float(opts['--ETphase']) if opts['--ETphase'] else np.pi/2;
Esphi = float(opts['--ESphase']) if opts['--ESphase'] else np.pi/2;
Btphi = float(opts['--BTphase']) if opts['--BTphase'] else 0.0;
Bsphi = float(opts['--BSphase']) if opts['--BSphase'] else 0.0;

r,v=d;
x,y,z = r;
x = np.array(x[:end:step]);
z = np.array(z[:end:step]);
t = np.array(t[:end:step]);

zmin = m.floor(z.min()/(lm/2))*lm/2;
zmax = m.ceil(z.max()/(lm/2))*lm/2;
xmin = x.min();
xmax = x.max();

X,Z = np.mgrid[ xmin : xmax : 16j,
                zmin : zmax : 16j];
zeros = np.zeros(Z.shape);
Ez = np.sin(2*np.pi*Z/lm+Esphi)*E_0;
#initial plotting
fig = plt.figure();
ax = fig.add_subplot(111);
p, = ax.plot(x[0:1],z[0:1],marker='o',label='r',c='r');
if not opts['--no-B']:
    Xh,Zh = np.mgrid[ xmin : xmax : 64j,
                      zmin : zmax : 64j];
    By = -np.sin(2*np.pi*Zh/lm+Bsphi)*E_0*0.0;
    By=By[:-1,:-1];
    pc = ax.pcolormesh(Xh,Zh,By,vmin=-E_0,vmax=E_0);
q = ax.quiver(X,Z,Ez,zeros,scale=1e9);
ax.set_ylim(zmin,zmax);
ax.set_xlim(x.min(),x.max());

def animate(ii):
    i,t=ii;
    Ez = np.sin(2*np.pi*Z/lm+Esphi)*np.sin(2*np.pi/lm*c*t+Etphi)*E_0;
    p.set_data(x[0:i],z[0:i]);
    q.set_UVC(Ez,zeros);
    if not opts['--no-B']:
        By = -np.sin(2*np.pi*Zh/lm+Bsphi)*np.sin(2*np.pi/lm*c*t+Btphi)*E_0;
        By=By[:-1,:-1];
        pc.set_array(By.ravel());
    return p,q;

ts = list(enumerate(t));
a = anim.FuncAnimation(fig,animate, ts, interval=0.01);
if output:
    a.save(output,fps=15);
else:
    plt.show();
