#include "numSolODE.h"
#include "exp_eur.h"
#include "equations.h"
#include "secondary.h"
#include "rk.h"

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
	std::vector<fun> functions;
	double t0 = -1.0;
	double t = -1.0;
	double n = -1.0;
	double step = -1.0;
	std::string method;
	std::string out_file;

	if (take_param(&t0, &t, &n, &step, equations, initial_cond, method, out_file, functions))
	{
		std::cout << "Error with file work\n";
		return (0);
	}
	if (method == "exp_eur")
	{
		if (exp_eur(t0, t, n, equations, initial_cond, out_file))
		{
			std::cout << "Error with output file\n";
			return (0);
		}
	}
	else if (method == "rk2")
	{
		if (rk2(t0, t, step, equations, initial_cond, out_file))
		{
			std::cout << "Error with output file\n";
			return (0);
		}
	}
	else if (method == "rk4")
	{
		if (rk4(t0, t, step, equations, initial_cond, out_file))
		{
			std::cout << "Error with output file\n";
			return (0);
		}
	}
	double max = residual(out_file, functions);
	std::cout << "residual = " << max;
	v_clean(sol);
	return (0);
}