#include "solveODE.h"

using namespace boost::numeric::odeint;

int main(int argc, char** argv){
	
	int n_sizes = argv[2][0] - '0';
	int dim = argv[3][0] - '0';	
	double x0[dim];
	double dt_list[n_sizes];
	int problem_type;
	std::string solver;
	double t1;
	
	//input parsing with GRVY
	parse(argv[1], x0, t1, dt_list, problem_type, solver);
	
	//transfer double [] to vector<double>
	state_type x (x0, x0 + sizeof(x0)/sizeof(double));
	std::vector<double> time_steps (dt_list, dt_list + sizeof(dt_list)/sizeof(double));
	
	//ODE solver
	if (solver == "RK4"){
		runge_kutta4< state_type > stepper;
		for (auto dt : time_steps){
			integrate_const(stepper, trajectory, x, 0.0, t1, dt);
			for (std::vector<double>::const_iterator i = x.begin(); 
			i != x.end(); i++){
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}
	}else if (solver == "RK5"){
		runge_kutta_dopri5< state_type > stepper;
	}else if (solver == "RK8"){
		runge_kutta_fehlberg78< state_type > stepper;
	}else{
		exit(1);
	}
	
	//Problem type

	return 0;
}
