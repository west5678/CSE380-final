#include <iostream>
#include <math.h>
#include <boost/numeric/odeint.hpp>

#include <grvy.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

using namespace boost::numeric::odeint;

// Convenience timer macros for begin/end functions
#define FUNC_BEGIN_TIMER gt.BeginTimer(__func__);
#define FUNC_END_TIMER   gt.EndTimer  (__func__);

GRVY::GRVY_Timer_Class gt;              // GRVY Timer

//Simple ODE(initial value problem): x'(t) = x(t), x(0) = 1
void rhs(const double x, double &dxdt, const double t){
	dxdt = -x;
}

//observer function to print result at each step to screen
void write_cout(const double &x, const double t){
	std::cout << t << '\t' << x << std::endl;
}

int main(){
	double time_steps[] = {1.e-9};
	std::vector<double> dt_list (time_steps, time_steps + sizeof(time_steps) / sizeof(double)); 
	typedef euler<double> stepper_type;
	gt.BeginTimer("Main Program");
	for (auto dt : dt_list){
		double x = 1.0;
		integrate_const(stepper_type(), rhs, x, 0.0, 1.024, dt);	
		std::cout << dt << "\t" << x << std::endl;
	}
	gt.EndTimer("Main Program");
	gt.Finalize();
	gt.Summarize();
	gt.Reset();
	return 0;
}
