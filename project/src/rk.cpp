#include "numSolODE.h"

int	rk2(double t0, double t, double step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file)
{
	std::vector<double> xi, xj; // xj = x(i + 1)
	std::vector<double> k1, k2;
	double b21 = 0.5, a2 = 0.5;
	std::ofstream out(out_file);
	if (!out.is_open())
		return 1;
	xi.resize(equations.size());
	xj.resize(equations.size());
	k1.resize(equations.size());
	k2.resize(equations.size());
	xi = initial_cond;
	int n = (t - t0) / step;
	double tmp_t = t0;
	for (std::size_t i = 0; i <= n; i++)
	{
		for (std::size_t j = 0; j < equations.size(); j++)
			k1[j] = xi[j] + b21 * step * equations[j](tmp_t, xi);
		out << t0 + i * step << " ";
		for (std::size_t j = 0; j < equations.size(); j++)
			k2[j] = equations[j](tmp_t + a2 * step, k1);
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			xj[j] = xi[j] + step * k2[j];
			out << xj[j] << " ";
		}
		out << "\n";
		swap(xi, xj);
		tmp_t += step;
	}
	out.close();
	return 0;
}

int	rk4(double t0, double t, double step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file)
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
	double tmp_t = t0;
	double a2 = 0.5, b21 = 0.5, a3 = 0.5, b3 = 0.5, a4 = 1.0, b4 = 1.0;
	double s1 = 1/6, s2 = 1/3, s3 = 1/3, s4 = 1/6;
	for (std::size_t i = 0; i <= n; i++)
	{
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kn[j] = s1 * equations[j](tmp_t, xi);
			ki[j] = xi[j] + b21 * step * kn[j];
		}
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kj[j] = equations[j](tmp_t + a2 * step, ki);
			kn[j] += s2 * kj[j];
			ki[j] = xi[j] + b3 * step * kj[j];
		}
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kj[j] = equations[j](tmp_t + a3 * step, ki);
			kn[j] += s3 * kj[j];
			ki[j] = xi[j] + b4 * step * kj[j];
		}
		out << tmp_t << " ";
		for (std::size_t j = 0; j < equations.size(); j++)
		{
			kj[j] = equations[j](tmp_t + a4 * step, ki);
			xj[j] = xi[j] + step * (kn[j] + s4 * kj[j]);
			out << xj[j] << " ";
		}
		out << "\n";
		swap(xi, xj);
		tmp_t += step;
	}
	out.close();
	return 0;
}