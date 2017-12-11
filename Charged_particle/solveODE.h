#include <iostream>
#include <math.h>
#include <boost/numeric/odeint.hpp>
#include <vector>

typedef std::vector<double> state_type;
void trajectory(const state_type&, state_type&, const double);
