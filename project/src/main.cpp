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

int main() {
	std::vector<double> grid;
	equat dx1 = dx1_1;
	equat dx2 = dx2_1;
	if (!get_grid(grid))
		return (0);
	print_v(grid);
	std::cout << "Laba #6\nMethods of numerical solution of ODE\n";
	return 0;
}