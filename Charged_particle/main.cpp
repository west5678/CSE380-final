#include "solveODE.h"

using namespace boost::numeric::odeint;

std::ofstream out;
GRVY::GRVY_Timer_Class gt;

void (*problem)(const state_type&, state_type&, const double);

// observer for performance timing
void observer_timer(const state_type& x, const double t){
}

// compute error for verification
void computeError( const int problem_type, const state_type x, const state_type x_exact, const double dt )
{
	//l2 error for charged particle trajectory
	if ( problem_type == 1)
	{
		double err = sqrt(pow(x[0]-x_exact[0], 2.0) + pow(x[1]-x_exact[1], 2.0)
				+ pow(x[2]-x_exact[2], 2.0));
		std::cout << dt << "\t" << err << std::endl;
	}
	//error for x'=-x
	else if (problem_type == 0)
	{
		double err = std::abs(x[0]-x_exact[0]);
		std::cout << dt << "\t" << err << std::endl;
	}
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
	bool verification;
	bool debug;
	bool timing_flag;
	iparse.Read_Var("Timing", &timing_flag, false);
	if (timing_flag)
		std::cout << "timing" << std::endl;

	gt.Init("ODE solver performance");
	
	gt.BeginTimer("Main Program");
	//input parsing with GRVY
	parse(argv[1], x0, t1, dt_list, problem_type, solver, verification, debug);
	
	//transfer double [] to vector<double>
	std::vector<double> time_steps (dt_list, dt_list + sizeof(dt_list)/sizeof(double));
	std::vector<double> x;	

	//problem type
	if (problem_type == 0)
	{
		problem = testEquation;
	}
	else if (problem_type == 1)
	{
		problem = trajectory;
	}

	//Verification - compute exact solution
	state_type x_exact;
	if (verification){
		std::cout << "Verification On" << std::endl;
		//compute "exact" solution with highest order
		runge_kutta_fehlberg78< state_type > stepper;
		state_type temp_exact (x0, x0 + sizeof(x0)/sizeof(double));
		x_exact = temp_exact;
		integrate_const(stepper, problem, x_exact, 0.0, t1, 1e-5);
	}
	
	
	//ODE solver
	for (auto dt : time_steps){
		std::string filename = "data/" + solver + "_" + std::to_string(int(dt*1000)) + ".dat";
		out.open(filename, std::fstream::out);
		std::vector<double> temp (x0, x0+sizeof(x0)/sizeof(double));
		x = temp;
		solve(timing_flag, solver, x, t1, dt);
		out.close();
		if (verification)
			computeError(problem_type, x, x_exact, dt);
	}
	gt.EndTimer("Main Program");
	gt.Finalize();
	gt.Summarize();
	gt.Reset();
	return 0;
}
