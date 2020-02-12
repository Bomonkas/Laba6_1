#include "numSolODE.h"
#include <iostream>

// need to implement
// 4th order accuracy Runge-Kutta method
// 4th order accuracy Adams-Bashfort method
// forecast-correction method of the 4th order of accuracy
// 2nd order Runge-Kutta method
// Symmetric difference scheme
// Explicit Euler Method
// Implicit Euler Method

void	print_sol(std::vector<double> sol)
{
	double step = (double)(T - T0) / N;
	std::cout << "x:         " << "y:\n"; 
	for (std::size_t i = 0; i < sol.size(); i++)
	{
		std::cout << std::setw(10) << T0 + i * step << "    " << sol[i]<< "\n";
	}
	std::cout.flush();
}

int		main() 
{
	std::vector<double> grid;
	std::vector<double> sol;
	equat dx1 = dx1_1;
	equat dx2 = dx2_1;
	eq dx = dy;
	sol = exp_eu1(dx);
	print_sol(sol);
	// if (!get_grid(grid))
	// 	return (0);
	// print_v(grid);
	std::cout << "Laba #6\nMethods of numerical solution of ODE\n";
	return 0;
}