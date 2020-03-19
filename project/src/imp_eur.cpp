#include "numSolODE.h"
#include "equations.h"

int	imp_eur(double t0, double t, double n, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file)
{
	std::vector<double> x_old; // x_new = x(i + 1)
	std::vector<double> x_new;
	method_func F = imp_eur_eq;
	std::ofstream out(out_file);
	double step = (t - t0) / n;
	if (!out.is_open())
		return (1);
	x_old.resize(equations.size());
	x_new.resize(equations.size());
	x_old = initial_cond;
	out << t0 << " ";
	for (std::size_t j = 0; j < x_new.size(); j++)
	{
		out << x_old[j] << " ";
	}
	out << "\n";
	double tmp_t = t0;
	for (std::size_t  i = 1; i <= n; i++)
	{
		tmp_t += step;
		out << tmp_t << " ";
		std::vector<double> tmp_v(x_new.size());
		for (std::size_t j = 0; j < x_old.size(); j++)
			tmp_v[j] = x_old[j] + step * equations[j](tmp_t, x_old);
		x_new = my_newton(step, x_old, tmp_v, equations, F);
		for (std::size_t j = 0; j < x_new.size(); j++)
			out << x_new[j] << " ";
		out << "\n";
		swap(x_old, x_new);
	}
	out.close();
	return 0;
}