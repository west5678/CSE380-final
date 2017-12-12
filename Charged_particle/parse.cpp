#include "solveODE.h"

using namespace std;
using namespace GRVY;

//Input parsing for solving system of ODE

void parse(char* filename, double*& x, double& t1, double*& dt_list, 
		int& problem_type, string& solver){
	GRVY_Input_Class iparse;

	if (! iparse.Open(filename))
		exit(1);
	
	//Read single-valued inputs
	iparse.Read_Var("Problem", &problem_type, 1);
	iparse.Read_Var("Solver", &solver, "RK4");
	iparse.Read_Var("t1", &t1, 1.024);
	
	//Read vectors
	int n_sizes;
	iparse.Read_Var("n_sizes", &n_sizes, 9);
	dt_list = new double[n_sizes];
	iparse.Read_Var_Vec("dt", dt_list, n_sizes);

	int dim;
	iparse.Read_Var("dim", &dim, 6);
	x = new double[dim];
	iparse.Read_Var_Vec("x0", x, dim);
}
