#include "solveODE.h"

void integrate_custom( state_type& x, double t0, double t1, double dt){
	int n = (t1-t0) / dt;
	state_type dxdt(x.size(), 0);
	double t;
	for (int i = 0; i < n; i ++){
		t = (i + 1) * dt;
		testEquation(x, dxdt, t);
		for (int j = 0; j < x.size(); j++){
			x[j] += dt * dxdt[j];
		}
		observer(x, t);
	}
}
		
