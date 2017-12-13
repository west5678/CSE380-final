#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 12 21:38:35 2017

@author: wei
"""

import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

time_steps = [1, 2, 4, 8, 16, 32, 64]
solver_types = ["RK4", "RK5", "RK"]

data = loadtxt("RK4_64.dat")

mpl.rcParams['legend.fontsize'] = 10

fig = plt.figure()
ax = fig.gca(projection = '3d')
ax.plot(data[:,1], data[:,2], data[:,3], label='RK8_64')
ax.legend()
plt.show()

