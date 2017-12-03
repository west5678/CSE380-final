from numpy import *
from scipy.integrate import odeint
import matplotlib.pyplot as plt

def rhs(x, t):
	dxdt = x
	return dxdt

x0 = 1.0
t = linspace(0, 10.24, 17)
sol = odeint(rhs, x0, t)
