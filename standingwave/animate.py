#!/usr/bin/env python2
'''
Animate for standing wave output, first particle only.

Usage:
  ./animate.py [options] <infile>
  ./animate.py [options]

Options:
  -e END         Read to index END.
  -s STEP        Read with STEP.
  -o OUTPUT      Output to OUTPUT, if not chosen, just display.
  --intensity=I  Set the intensity to I
  --ET=ET   Set time phase of the electric field to ET.
  --BT=BT   Set time phase of the magnetic field to BT.
  --ES=ES   Set time phase of the electric field to ES.
  --BS=BS   Set time phase of the magnetic field to BS.
  --no-B         Don't plot the B-field.
'''
import math as m;
import matplotlib.pyplot as plt;
import matplotlib.animation as anim;
import numpy as np;
import pickle;
import sys;
from docopt import docopt;

#arguments
opts=docopt(__doc__,help=True);
end  = int(opts['-e']) if opts['-e'] else None;
step = int(opts['-s']) if opts['-s'] else None;
output = opts['-o'];

#IMPORTANT: we use microns and seconds here.
lm = 8e-1;
c = 2.99792458e14;
Et = float(opts['--ET']) if opts['--ET'] else 1/2;
Es = float(opts['--ES']) if opts['--ES'] else 1/2;
Bt = float(opts['--BT']) if opts['--BT'] else 0.0;
Bs = float(opts['--BS']) if opts['--BS'] else 0.0;
I     = float(opts['--intensity']) if opts['--intensity'] else 1e18;
E_0   = 2*np.sqrt(4*np.pi*I*1e11/c);

if opts['<infile>']:
    with open(opts['<infile>'],'rb') as f:
        t,d=pickle.load(f);
else:
    t,d=pickle.loads(sys.stdin.read());
r,v=d;

x,y,z = r;
x = np.array(x[:end:step])*1e4;
z = np.array(z[:end:step])*1e4;
t = np.array(t[:end:step]);

zmin = m.floor(z.min()/(lm/2))*lm/2;
zmax = m.ceil(z.max()/(lm/2))*lm/2;
xmin = x.min();
xmax = x.max();

X,Z = np.mgrid[ xmin : xmax : 16j,
                zmin : zmax : 16j];
zeros = np.zeros(Z.shape);
Ez = np.sin(2*np.pi*Z/lm+Es*np.pi)*E_0;

#initial plotting
fig = plt.figure();
ax = fig.add_subplot(111);
p, = ax.plot(x[0:1],z[0:1],marker='o',label='r',c='r');
if not opts['--no-B']:
    Xh,Zh = np.mgrid[ xmin : xmax : 64j,
                      zmin : zmax : 64j];
    By = -np.sin(2*np.pi*Zh/lm+Bs*np.pi)*E_0*0.0;
    By=By[:-1,:-1];
    pc = ax.pcolormesh(Xh,Zh,By,vmin=-E_0,vmax=E_0);
q = ax.quiver(X,Z,Ez,zeros,scale=1e9);
ax.set_ylim(zmin,zmax);
ax.set_xlim(x.min(),x.max());
ax.set_ylabel('x ($\mu$m)');
ax.set_xlabel('z ($\mu$m)');

def animate(ii):
    i,t=ii;
    Ez = np.sin(2*np.pi*Z/lm+Es*np.pi)*np.sin(2*np.pi/lm*c*t+Et*np.pi)*E_0;
    p.set_data(x[0:i],z[0:i]);
    q.set_UVC(Ez,zeros);
    if not opts['--no-B']:
        By = -np.sin(2*np.pi*Zh/lm+Bs*np.pi)*np.sin(2*np.pi/lm*c*t+Bt*np.pi)*E_0;
        By=By[:-1,:-1];
        pc.set_array(By.ravel());
    return p,q;

ts = list(enumerate(t));
a = anim.FuncAnimation(fig,animate, ts, interval=0.01);
if output:
    a.save(output,fps=15);
else:
    plt.show();
