#include "numSolODE.h"

int	exp_eur(double t0, double t, double n, std::vector<eq> &equations, 
	std::vector<double> &initial_cond, std::string &out_file)
{
	std::vector<double> x_old;
	std::vector<double> x_new;
	std::ofstream out(out_file);
	if (!out.is_open())
		return (1);
	x_old.resize(equations.size());
	x_new.resize(equations.size());
	double step = (t - t0) / n;
	x_old = initial_cond;
	out << t0 << " ";
	for (std::size_t j = 0; j < x_old.size(); j++)
			out << x_old[j] << " ";
	out << "\n";
	double tmp_t = t0;
	for (std::size_t  i = 1; i <= n; i++)
	{
		tmp_t += step;
		out << tmp_t << " ";
		for (std::size_t j = 0; j < x_old.size(); j++)
			{
				x_new[j] = x_old[j] + step * equations[j](tmp_t, x_old);
				out << x_new[j] << " ";
			}
		out << "\n";
		swap(x_old, x_new);
	}
	out.close();
	return 0;
}

// std::vector <std::vector<double>>	exp_eu(std::vector<eq> equations,
// 									std::vector<double> intial_cond)
// {
// 	std::vector<std::vector<double>> sol;
// 	double step = (double)(T - T0) / N;
// 	sol.resize(N + 2);
// 	sol[0].resize(N + 1);
// 	for (std::size_t j = 0; j < sol[0].size(); j++)
// 		sol[0][j] = T0 + j * step; 
// 	sol[1].resize(equations.size());
// 	for (std::size_t j = 0; j < sol[1].size(); j++)
// 		sol[1][j] = intial_cond[j];
// 	std::vector<double> means; 
// 	means.resize(equations.size() + 1);
// 	for (std::size_t i = 2; i < sol.size(); i++)
// 	{
// 		sol[i].resize(equations.size());
// 		means[0] = sol[0][i - 1];
// 		for (std::size_t j = 1; j < means.size(); j++)
// 			means[j] = sol[i - 1][j - 1];
// 		for (std::size_t j = 0; j < sol[i].size(); j++)
// 			sol[i][j] = sol[i - 1][j] + step * equations[j](T0 + (i - 1) * step, means);
// 	}
// 	return (sol);
// }
