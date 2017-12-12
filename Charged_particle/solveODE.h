#include <iostream>
#include <math.h>
#include <boost/numeric/odeint.hpp>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <grvy.h>

typedef std::vector<double> state_type;
void parse(char*, double*&, double&, double*&, int&, std::string&);
void trajectory(const state_type&, state_type&, const double);
