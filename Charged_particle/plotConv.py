from numpy import *
import matplotlib as plt

data = loadtxt("data.txt")
plt.figure()
plt.loglog(data[:,0], abs(data[:,1] - exp(-4.096)))
plt.axis('equal')
plt.xlabel('dt')
plt.ylabel('error')
