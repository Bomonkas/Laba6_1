#include "exp_eur.h"
#include "secondary.h"
#include <fstream>

int	exp_eur(double t0, double t, double n, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file)
{
	std::vector<double> xi; // xj = x(i + 1)
	std::vector<double> xj;
	std::ofstream out(out_file);
	if (!out.is_open())
		return (1);
	xi.resize(equations.size());
	xj.resize(equations.size());
	double step = (t - t0) / n;
	xi = initial_cond;
	out << t0 << " ";
	for (std::size_t j = 0; j < xj.size(); j++)
			out << xi[j] << " ";
	out << "\n";
	for (std::size_t  i = 1; i <= n; i++)
	{
		for (std::size_t j = 0; j < xi.size(); j++)
			xj[j] = xi[j] + step * equations[j](t0 + i * step, xi);
		out << t0 + i * step << " ";
		for (std::size_t j = 0; j < xj.size(); j++)
			out << xj[j] << " ";
		out << "\n";
		swap(xi, xj);
	}
	out.close();
	xi.clear();
	xj.clear();
	return (0);
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
