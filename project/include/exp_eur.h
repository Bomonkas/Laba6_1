#pragma once

#include "numSolODE.h"

std::vector <std::vector<double>>	exp_eu(std::vector<eq> dx, std::vector<double> x0);
int		exp_eur(double t0, double t, double n, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file);
// std::vector <std::vector<double>>	exp_eu(eq2 dy, eq2 dz, double y0, double z0);
// std::vector <std::vector<double>>	exp_eu1(eq1 dx, double y0);