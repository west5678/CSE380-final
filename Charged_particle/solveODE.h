#include <iostream>
#include <fstream>
#include <math.h>
#include <boost/numeric/odeint.hpp>
#include <vector>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <grvy.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

typedef std::vector<double> state_type;

//global variables
extern void (*problem)(const state_type&, state_type&, const double);
extern std::ofstream out;	//ofstream for odeint output
extern GRVY::GRVY_Timer_Class gt;

void parse(char*, double*, double&, double*, int&, std::string&, bool&, bool&);
void trajectory(const state_type&, state_type&, const double);
void testEquation(const state_type&, state_type&, const double);
void observer(const state_type&, const double);
void solve(bool, std::string, state_type&, double, double);
void integrate_custom( state_type&, double, double, double, bool);

