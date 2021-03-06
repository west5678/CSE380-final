#include "solveODE.h"

using namespace boost::numeric::odeint;

#define FUNC_BEGIN_TIMER gt.BeginTimer(__func__);
#define FUNC_END_TIMER   gt.EndTimer  (__func__);

void solve(bool timing_flag, std::string solver, state_type& x, double t1, double dt){
	FUNC_BEGIN_TIMER;
	if(timing_flag){
		if (solver == "RK4"){
			runge_kutta4< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt );
		}
		else if (solver == "RK5"){
			runge_kutta_dopri5< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt );
		}
		else if (solver == "RK8"){
			runge_kutta_fehlberg78< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt );
		}
		else if (solver == "Euler_tpl"){
			euler< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt );
		}
		else if (solver == "Euler_custom"){
			integrate_custom( x, 0.0, t1, dt, timing_flag );
		}
	}
	else{
		if (solver == "RK4"){
			runge_kutta4< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt, observer );
		}
		else if (solver == "RK5"){
			runge_kutta_dopri5< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt, observer );
		}
		else if (solver == "RK8"){
			runge_kutta_fehlberg78< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt, observer );
		}
		else if (solver == "Euler_tpl"){
			euler< state_type > stepper;
			integrate_const( stepper, problem, x, 0.0, t1, dt, observer );
		}
		else if (solver == "Euler_custom"){
			integrate_custom( x, 0.0, t1, dt, timing_flag );
		}
	}

	FUNC_END_TIMER;
}
