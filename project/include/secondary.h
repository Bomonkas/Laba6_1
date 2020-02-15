#pragma once
#include "numSolODE.h"

int		get_grid(std::vector<double> grid); //trash
void	print_v(std::vector<double> vec);
void	v_clean(std::vector<std::vector<double>> vec);
void	print_sol(std::vector<std::vector<double>> sol);
void	print_sol1(std::vector<std::vector<double>> sol);
int		take_param(double *t0, double *t, double *n, double *step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &method);