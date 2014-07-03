#!/usr/bin/env python2
'''usage: ./txt2pickle <infile> <outfile>'''
from docopt import docopt;
import numpy as np;
import cPickle;
import fileinput;

opts=docopt(__doc__,help=True);
#get data and split
with open(opts['<infile>'],'r') as f:
    data= [line.strip().split() for line in f.readlines()];
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

with open(opts['<outfile>'],'wb') as f:
    cPickle.dump(out,f,2);
pass;

