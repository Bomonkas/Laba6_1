#pragma once

#include "numSolODE.h"

int		rk2(double t0, double t, double step, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file);
int		rk4(double t0, double t, double step, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file);