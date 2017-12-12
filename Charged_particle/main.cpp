#include "solveODE.h"

using namespace boost::numeric::odeint;

int main(int argc, char** argv){
	
	double* x0;
	double* dt_list;
	int problem_type;
	std::string solver;
	double t1;
	parse(argv[1], x0, t1, dt_list, problem_type, solver);
	state_type x (x0, x0 + sizeof(x0)/sizeof(double));
	std::vector<double> time_steps (dt_list, dt_list + sizeof(dt_list)/sizeof(double));
/*	
	double time_steps[] = {0.512, 0.256, 0.128, 0.064, 0.032, 0.016};
	std::vector<double> dt_list (time_steps, time_steps + sizeof(time_steps) / sizeof(double));*/
	runge_kutta4< state_type > stepper;
	for (auto dt : time_steps){
		/*
		double x0[] = {0.0, 0.0, 0.0, 20.0, 0.0, 2.0};
		state_type x (x0, x0 + sizeof(x0) / sizeof(double));
		*/
		integrate_const(stepper, trajectory, x, 0.0, t1, dt);
		for (std::vector<double>::const_iterator i = x.begin(); i != x.end(); i++){
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
