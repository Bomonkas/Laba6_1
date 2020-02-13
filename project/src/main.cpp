#include "numSolODE.h"
#include "exp_eur.h"
#include "equations.h"
#include "secondary.h"
#include <iostream>

// need to implement
// 4th order accuracy Runge-Kutta method
// 4th order accuracy Adams-Bashfort method
// forecast-correction method of the 4th order of accuracy
// 2nd order Runge-Kutta method
// Symmetric difference scheme
// Explicit Euler Method
// Implicit Euler Method

int		main() 
{
	std::vector<double> grid;
	std::vector<std::vector<double>> sol;
	eq2 dx1 = dy;
	eq2 dx2 = dz;
	eq1 dx = dy1;
	sol = exp_eu1(dx, 1);
	print_sol(sol);
	v_clean(sol);
	sol = exp_eu(dy, dz, 1, 0);
	print_sol(sol);
	v_clean(sol);
	// if (!get_grid(grid))
	// // 	return (0);
	// print_v(grid);
	std::cout << "Laba #6\nMethods of numerical solution of ODE\n";
	return 0;
}