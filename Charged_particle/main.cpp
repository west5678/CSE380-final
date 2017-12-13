#include "solveODE.h"

using namespace boost::numeric::odeint;
std::ofstream out;

void observer_standard( const state_type &x, const double t ){
	out << t << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << std::endl;
}

void observer_debug( const state_type &x, const double t ){
	out << t << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << "\t" << x[3] << "\t" << x[4] << "\t" << x[5] << std::endl;
}


/*void solve(const std::string solver, const std::vector<double> time_steps, const double* x0, 
		state_type x, double t1){
	
}*/

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
	bool verification;
	bool debug;
	
	//input parsing with GRVY
	parse(argv[1], x0, t1, dt_list, problem_type, solver, verification, debug);
	
	//transfer double [] to vector<double>
	std::vector<double> time_steps (dt_list, dt_list + sizeof(dt_list)/sizeof(double));
	std::vector<double> x;	
	//ODE system
	void (*problem)(const state_type&, state_type&, const double);
	if (problem_type == 1)
	{
		problem = &trajectory;
	}
	else if (problem_type == 0)
	{
		problem = &testEquation;
	}

	//standard/debug
	void (*observer)(const state_type&, const double);
	if (debug)
	{
		observer = observer_debug;
	}
	else
	{
		observer = observer_standard;
	}
	
	//ODE solver
	//solve(solver, time_steps, x0, x, t1);
	if (solver == "RK4")
	{
		runge_kutta4< state_type > stepper;
		for (auto dt : time_steps)
		{
			std::string filename = "data/" + solver + "_" + std::to_string(int(dt*1000)) + ".dat";
			out.open(filename, std::fstream::out);
			if (!out.is_open())
				exit(1);
			std::vector<double> temp (x0, x0+sizeof(x0)/sizeof(double));
			x = temp;
			integrate_const(stepper, trajectory, x, 0.0, t1, dt, observer);
			out.close();
			std::cout << filename << std::endl;
		}
	}
	else if (solver == "RK5")
	{
		runge_kutta_dopri5< state_type > stepper;
		for (auto dt : time_steps)
		{
			std::string filename = "data/" + solver + "_" + std::to_string(int(dt*1000)) + ".dat";
			out.open(filename, std::fstream::out);
			if (!out.is_open())
				exit(1);
			std::vector<double> temp (x0, x0+sizeof(x0)/sizeof(double));
			x = temp;
			integrate_const(stepper, trajectory, x, 0.0, t1, dt, observer);
			out.close();
			std::cout << filename << std::endl;
		}
	}
	else if (solver == "RK8")
	{
		runge_kutta_fehlberg78< state_type > stepper;
		for (auto dt : time_steps)
		{			
			std::string filename = "data/" + solver + "_" + std::to_string(int(dt*1000)) + ".dat";
			out.open(filename, std::fstream::out);
			if (!out.is_open())
				exit(1);
			std::vector<double> temp (x0, x0+sizeof(x0)/sizeof(double));
			x = temp;
			integrate_const(stepper, trajectory, x, 0.0, t1, dt, observer);
			out.close();
			std::cout << filename << std::endl;
		}
	}

	else{
		exit(1);
	}

	
	//Verification
	if (verification){
		std::cout << "Verification On" << std::endl;
		//compute "exact" solution with highest order
		runge_kutta_fehlberg78< state_type > stepper;
		state_type x_exact (x0, x0 + sizeof(x0)/sizeof(double));
		integrate_const(stepper, trajectory, x_exact, 0.0, t1, 1e-5);
		std::cout << x_exact[0] << "\t" << x_exact[1] << "\t" << x_exact[2] << std::endl;
		std::vector<double> error_list;
		std::ofstream error_out("error.out");
		for (int i=0; i<n_sizes; i++){
			double err = sqrt(pow(x[0]-x_exact[1], 2.0) + pow(x[1]-x_exact[1], 2.0)
					+ pow(x[2]-x_exact[2], 2.0));
			error_out << err << " ";
		}
		error_out.close();
	}

	return 0;
}
