#include "solveODE.h"

//Simple ODE (test problem for absolute stability): x'(t) = x(t), x(0) = 1
void testEquation(const state_type& x, state_type &dxdt, const double t){
	dxdt[0] = -x[0];
}

const double omega = 5, tau = 5;

//Charged particle
void trajectory(const state_type &x, state_type &dxdt, const double t){
	dxdt[0] = x[3];
	dxdt[1] = x[4];
	dxdt[2] = x[5];
	dxdt[3] = - 0.2 * x[3] + 5 * x[4];
	dxdt[4] = - 5 * x[3] - 0.2 * x[4];
	dxdt[5] = - 0.2 * x[5];
}
