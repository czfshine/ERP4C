# -*- coding: utf-8 -*-
import numpy as np

infile ="in.data"


f=open(infile,"r")

a=0
data={}
def tonum(ii):
    return [int(i) for i in ii]
t=0
for i in f.readlines():
    a=a+1
    
    if((a-1) %7 == 0):
        ii=t
        t=t+1
    if(len(i)> 10):
        if(data.has_key(ii)):
            data[ii]=data[ii]+tonum(i[:-1])
        else:
            data[ii]=tonum(i[:-1])
            
d=[]
for k in data.iterkeys():
    data[k].append(k)
    d.append(data[k])

d=np.array(d,dtype=np.int32)