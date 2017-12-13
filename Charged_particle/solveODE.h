#include <iostream>
#include <fstream>
#include <math.h>
#include <boost/numeric/odeint.hpp>
#include <vector>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <grvy.h>

typedef std::vector<double> state_type;
void parse(char*, double*, double&, double*, int&, std::string&, bool&, bool&);
void trajectory(const state_type&, state_type&, const double);

