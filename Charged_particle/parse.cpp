#include "solveODE.h"

using namespace std;
using namespace GRVY;

//Input parsing for solving system of ODE

#define FUNC_BEGIN_TIMER gt.BeginTimer(__func__);
#define FUNC_END_TIMER   gt.EndTimer  (__func__);

void parse(char* filename, double* x, double& t1, double* dt_list, 
		int& problem_type, string& solver, bool& verification, bool& debug){
	FUNC_BEGIN_TIMER;

	GRVY_Input_Class iparse;

	if (! iparse.Open(filename))
		exit(1);
	
	//Read single-valued inputs
	iparse.Read_Var("Problem", &problem_type);
	iparse.Read_Var("Solver", &solver);
	iparse.Read_Var("t1", &t1);
	iparse.Read_Var("Verification", &verification, false);
	iparse.Read_Var("Debug", &debug, false);
	
	//Read vectors
	int n_sizes;
	iparse.Read_Var("n_sizes", &n_sizes);
	iparse.Read_Var_Vec("dt", dt_list, n_sizes);

	int dim;
	iparse.Read_Var("dim", &dim);
	iparse.Read_Var_Vec("x0", x, dim);

	if (debug)	iparse.Fdump("# ", "run.log");
	FUNC_END_TIMER;
}
