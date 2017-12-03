#include <iostream>
#include <math.h>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

//Simple ODE(initial value problem): x'(t) = x(t), x(0) = 1
void rhs(const double x, double &dxdt, const double t){
	dxdt = -x;
}

//observer function to print result at each step to screen
void write_cout(const double &x, const double t){
	std::cout << t << '\t' << x << std::endl;
}

int main(){
	double x = 1.0;
	typedef euler<double> stepper_type;
	integrate_const(stepper_type(), rhs, x, 0.0, 10.24, 0.16, write_cout);
	return 0;
}
