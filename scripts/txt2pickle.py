#!/usr/bin/env python2
'''
Convert generic output to a pickle of data.

Usage:
  ./txt2pickle <infile> <outfile>
  ./txt2pickle
'''
from docopt import docopt;
import numpy as np;
import cPickle;
import fileinput;

opts=docopt(__doc__,help=True);
inname = opts['<infile>'];

#get data and split
if inname:
    with open(inname,'r') as f:
        lines = [line.strip() for line in f.readlines()];
else:
    lines = [line.strip() for line in fileinput.input()];
time, data = zip(*[line.split(':') for line in lines]);
time = np.array(map(float,time));
data = [line.split() for line in data];
#only select 1 out of 100
data[:] = data[::1];
#data[:] = data[:];
#get each point pair and make into floats, finally.
data[:] = [[map(float,p.split(',')) for p in line ] for line in data];
#zip into particles...
out = zip(*data);
del data;
#and zip into x,y, and z coordinates.
out[:] = [zip(*p) for p in out];

if inname:
    with open(opts['<outfile>'],'wb') as f:
        cPickle.dump((time,out),f,2);
else:
    print(cPickle.dumps((time,out)));
pass;

