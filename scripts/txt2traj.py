#!/usr/bin/env python2
'''Convert text files into a pickle containing trajectories.

Usage:
  ./txt2traj.py [options] <infile> ...

Options:
  -o OUTNAME,--output=OUTNAME   Output to file OUTNAME
'''
from docopt import docopt;
import numpy as np;
import cPickle;
import fileinput;

opts=docopt(__doc__,help=True);
#get data and split
outname = opts['--output'] if opts['--output'] else 'out.pickle';
time = None;
data = [];
for filename in opts['<infile>']:
    print('reading in {}'.format(filename));
    with open(filename,'r') as f:
        lines = [line.strip() for line in f.readlines()];
    ctime, cdata = zip(*[line.split(':') for line in lines]);
    if time is not None:
        time = np.array(map(float,ctime));
    print('splitting');
    cdata = [line.split() for line in cdata];
    print('splitting into vectors');
    cdata[:] = [[map(float,p.split(',')) for p in line ] for line in cdata];
    print('zipping into trajectories');
    trajs = zip(*cdata);
    print('zipping into particles');
    trajs[:] = [zip(*p) for p in trajs];
    print('adding to data');
    data.extend(trajs);
del cdata,trajs;

print('outputting');
with open(outname,'wb') as f:
    cPickle.dump((time,data),f,2);
pass;
