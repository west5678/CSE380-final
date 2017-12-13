#include "solveODE.h"

using namespace boost::numeric::odeint;

std::ofstream out;

void observer( const state_type &x, const double t){
	out << t << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << std::endl;
}

void solve(const std::string solver, const std::vector<double> time_steps, const double* x0, 
		state_type& x, double t1){
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
}
