#include "numSolODE.h"
#include "equations.h"

int	imp_eur(double t0, double t, double n, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file)
{
	std::vector<double> xi; // xj = x(i + 1)
	std::vector<double> xj;
	method_func F = imp_eur_eq;
	std::ofstream out(out_file);
	double step = (t - t0) / n;
	if (!out.is_open())
		return (1);
	xi.resize(equations.size());
	xj.resize(equations.size());
	xi = initial_cond;
	out << t0 << " ";
	for (std::size_t j = 0; j < xj.size(); j++)
	{
		xj[j] = 3 + j;
		out << xi[j] << " ";
	}
	out << "\n";
	method_func f = test_new;
	equations[0] = equation1_newton;
	equations[1] = equation2_newton;
	print_v(xi);
	std::vector<double> vec = my_newton(step, xi, xj, equations, test_new);
	print_v(vec);
	out.close();
	return 0;
}