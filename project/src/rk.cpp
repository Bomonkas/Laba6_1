#include "numSolODE.h"

int	rk2(double t0, double t, double step, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file)
{
	std::vector<double> xi, xj; // xj = x(i + 1)
	std::vector<double> k1, k2;
	std::ofstream out(out_file);
	if (!out.is_open())
		return 1;
	xi.resize(equations.size());
	xj.resize(equations.size());
	k1.resize(equations.size());
	k2.resize(equations.size());
	xi = initial_cond;
	int n = (t - t0) / step;
	for (std::size_t i = 0; i <= n; i++)
	{
		for (std::size_t j = 0; j < equations.size(); j++)
			k1[j] = xi[j] + 0.5 * step * equations[j](t0 + i * step, xi);
		out << t0 + i * step << " ";
		for (std::size_t j = 0; j < equations.size(); j++)
			k2[j] = equations[j](t0 + i * step + 0.5 * step, k1);
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			xj[j] = xi[j] + step * k2[j];
			out << xj[j] << " ";
		}
		out << "\n";
		swap(xi, xj);
	}
	out.close();
	return 0;
}

int	rk4(double t0, double t, double step, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file)
{
	std::vector<double> xi, xj; // xj = x(i + 1)
	std::vector<double> ki, kj, kn;
	std::ofstream out(out_file);
	if (!out.is_open())
		return 1;
	xi.resize(equations.size());
	xj.resize(equations.size());
	ki.resize(equations.size());
	kj.resize(equations.size());
	kn.resize(equations.size());
	xi = initial_cond;
	int n = (t - t0) / step;
	for (std::size_t i = 0; i <= n; i++)
	{
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kn[j] = equations[j](t0 + i * step, xi);
			ki[j] = xi[j] + step / 2 * kn[j];
		}
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kj[j] = equations[j](t0 + i * step + step / 2, ki);
			kn[j] += 2 * kj[j];
			ki[j] = xi[j] + step / 2 * kj[j];
		}
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kj[j] = equations[j](t0 + i * step + step / 2, ki);
			kn[j] += 2 * kj[j];
			ki[j] = xi[j] + step * kj[j];
		}
		out << t0 + i * step << " ";
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kj[j] = equations[j](t0 + i * step + step, ki);
			xj[j] = xi[j] + step / 6 * (kn[j] + kj[j]);
			out << xj[j] << " ";
		}
		out << "\n";
		swap(xi, xj);
	}
	out.close();
	return 0;
}