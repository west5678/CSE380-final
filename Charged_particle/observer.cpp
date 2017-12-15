#include "solveODE.h"

#define FUNC_BEGIN_TIMER gt.BeginTimer(__func__);
#define FUNC_END_TIMER   gt.EndTimer  (__func__);

void observer( const state_type &x, const double t ){
	FUNC_BEGIN_TIMER;
	out << t;
	for (auto c : x){ 
		out << "\t" << c;
	}
	out << std::endl;
	FUNC_END_TIMER;
}


