#include "solveODE.h"

#define FUNC_BEGIN_TIMER gt.BeginTimer(__func__);
#define FUNC_END_TIMER   gt.EndTimer  (__func__);

void observer_standard( const state_type &x, const double t ){
	FUNC_BEGIN_TIMER;
	out << t << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << std::endl;
	FUNC_END_TIMER;
}

void observer_debug( const state_type &x, const double t ){
	FUNC_BEGIN_TIMER;
	out << t << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << "\t" << x[3] << "\t" << x[4] << "\t" << x[5] << std::endl;
	FUNC_END_TIMER;
}

