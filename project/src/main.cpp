#include "numSolODE.h"
#include "exp_eur.h"
#include "equations.h"
#include "secondary.h"

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
	std::vector<std::vector<double>> sol;
	std::vector<eq> equations;
	std::vector<double> initial_cond;
	double t0 = -1.0;
	double t = -1.0;
	double n = -1.0;
	double step = -1.0;
	std::string method;

	if (take_param(&t0, &t, &n, &step, equations, initial_cond, method))
	{
		std::cout << "Error with file work\n";
		return (0);
	}
	if (method == "exp_eur")
	{
		if (exp_eur(t0, t, n, equations, initial_cond))
		{
			std::cout << "Error with output file\n";
			return (0);
		}
		// sol = exp_eu(equations, initial_cond);
		// print_sol1(sol);
		// v_clean(sol);
	}

	// if (!get_grid(grid))
	// // 	return (0);
	// print_v(grid);
	return 0;
}