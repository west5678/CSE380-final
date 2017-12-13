#include "solveODE.h"

using namespace boost::numeric::odeint;

void observer( const state_type &x, const double t){
	std::cout << t << "\t" << x[0] << " " << x[1] << " " << x[2] << std::endl;
}

int main(int argc, char** argv){
	//initialization
	GRVY::GRVY_Input_Class iparse;	
	iparse.Open(argv[1]);
	int n_sizes, dim;
	iparse.Read_Var("n_sizes", &n_sizes);		
	iparse.Read_Var("dim", &dim);
	
	double x0[dim];
	double dt_list[n_sizes];
	int problem_type;
	std::string solver;
	double t1;
	
	//input parsing with GRVY
	parse(argv[1], x0, t1, dt_list, problem_type, solver);
	
	//transfer double [] to vector<double>
	std::vector<double> time_steps (dt_list, dt_list + sizeof(dt_list)/sizeof(double));
	
	//ODE solver
	if (solver == "RK4"){
		runge_kutta4< state_type > stepper;
		for (auto dt : time_steps){
			state_type x (x0, x0 + sizeof(x0)/sizeof(double));
			integrate_const(stepper, trajectory, x, 0.0, t1, dt, observer);
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
