#include <iostream>
#include <math.h>
#include <vector>

//Simple ODE(initial value problem): x'(t) = x(t), x(0) = 1
void rhs(const double x, double &dxdt, const double t){
	dxdt = -x;
}

//observer function to print result at each step to screen
void write_cout(const double &x, const double t){
	std::cout << t << '\t' << x << std::endl;
}

//Self-implemented explicit Euler solver
void solveODE(double& x, double t0, double t1, double dt)
{
	for (double t=t0; t<t1; t += dt){
		double dxdt = 0.0;
		rhs(x, dxdt, t);
		x = x + dt * dxdt;	//forward Euler step
		//write_cout(x,t+dt);
	}
}

int main(){
	double time_steps[] = {0.512, 0.256, 0.128, 0.064, 0.032, 0.016};
	std::vector<double> dt_list (time_steps, time_steps + sizeof(time_steps) / sizeof(double)); 
	for (auto dt : dt_list){
		double x = 1.0;
		solveODE(x, 0.0, 1.024, dt);
		std::cout << dt << "\t" << x << std::endl;
	}
	return 0;
}
