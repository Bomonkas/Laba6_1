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

void	print_sol(std::vector<std::vector<double>> sol)
{
	double step = (double)(T - T0) / N;
	std::cout << std::setw(6) << "t" << "    |";
	for (std::size_t i = 0; i < sol[i].size(); i++)
	{
		std::cout << "     x" << i + 1 << "   |";
	}
	std::cout << "\n";
	for (std::size_t i = 0; i < sol.size(); i++)
	{
		std::cout << std::setw(10) << T0 + i * step << "|";
		for (std::size_t j = 0; j < sol[i].size(); j++)
			std::cout << std::setw(10) <<  sol[i][j] << "|";
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void    v_clean(std::vector<std::vector<double>> vec)
{
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		vec[i].clear();
	}
	vec.clear();
}

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