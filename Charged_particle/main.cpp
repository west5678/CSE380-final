#include "solveODE.h"

using namespace boost::numeric::odeint;

int main(){
	double time_steps[] = {0.512, 0.256, 0.128, 0.064, 0.032, 0.016};
	std::vector<double> dt_list (time_steps, time_steps + sizeof(time_steps) / sizeof(double));
	runge_kutta4< state_type > stepper;
	for (auto dt : dt_list){
		double x0[] = {0.0, 0.0, 0.0, 20.0, 0.0, 2.0};
		state_type x (x0, x0 + sizeof(x0) / sizeof(double));
		integrate_const(stepper, trajectory, x, 0.0, 1.024, dt);
		for (std::vector<double>::const_iterator i = x.begin(); i != x.end(); i++){
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
