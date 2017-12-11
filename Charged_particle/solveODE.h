#include <iostream>
#include <math.h>
#include <boost/numeric/odeint.hpp>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <grvy.h>

typedef std::vector<double> state_type;
void trajectory(const state_type&, state_type&, const double);
void parse(char*, state_type&, double, std::vector<double>&, int&, std::string&);
