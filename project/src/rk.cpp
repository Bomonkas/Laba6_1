#include "numSolODE.h"

int	rk2(double t0, double t, double step, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file)
{
	std::vector<double> xi, xj; // xj = x(i + 1)
	std::vector<double> k1, k2;
	std::ofstream out(out_file);
	if (!out.is_open())
		return (1);
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
	xi.clear();
	k1.clear();
	k2.clear();
	xj.clear();
	return (0);
}

// int	rk4_1(double t0, double t, double step, std::vector<eq> equations, 
// 		std::vector<double> initial_cond, std::string out_file)
// {
// 	std::vector<double> xi, xj; // xj = x(i + 1)
// 	std::vector<double> k1, k2, k3, k4, kn;
// 	std::ofstream out(out_file);
// 	if (!out.is_open())
// 		return (1);
// 	xi.resize(equations.size());
// 	xj.resize(equations.size());
// 	k1.resize(equations.size());
// 	k2.resize(equations.size());
// 	k3.resize(equations.size());
// 	k4.resize(equations.size());
// 	kn.resize(equations.size());
// 	xi = initial_cond;
// 	int n = (t - t0) / step;
// 	for (std::size_t i = 0; i <= n; i++)
// 	{
// 		for (std::size_t j = 0; j < equations.size(); j++)
// 		{
// 			k1[j] = equations[j](t0 + i * step, xi);
// 			kn[j] = k1[j];
// 			k1[j] = xi[j] + step / 2 * k1[j];
// 		}
// 		for (std::size_t j = 0; j < equations.size(); j++)
// 		{
// 			k2[j] = equations[j](t0 + i * step + step / 2, k1);
// 			kn[j] += 2 * k2[j];
// 			k2[j] = xi[j] + step / 2 * k2[j];
// 		}
// 		for (std::size_t j = 0; j < equations.size(); j++)
// 		{
// 			k3[j] = equations[j](t0 + i * step + step / 2, k2);
// 			kn[j] += 2 * k3[j];
// 			k3[j] = xi[j] + step * k3[j];
// 		}
// 				out << t0 + i * step << " ";
// 		for (std::size_t j = 0; j < equations.size(); j++)
// 		{
// 			k4[j] = equations[j](t0 + i * step + step, k3);
// 			xj[j] = xi[j] + step / 6 * (kn[j] + k4[j]);
// 			out << xj[j] << " ";
// 		}
// 		out << "\n";
// 		swap(xi, xj);
// 	}
// 	out.close();
// 	k1.clear();
// 	k2.clear();
// 	k3.clear();
// 	k4.clear();
// 	kn.clear();
// 	xi.clear();
// 	xj.clear();
// 	return (0);
// }

int	rk4(double t0, double t, double step, std::vector<eq> equations, 
		std::vector<double> initial_cond, std::string out_file)
{
	std::vector<double> xi, xj; // xj = x(i + 1)
	std::vector<double> ki, kj, kn;
	std::ofstream out(out_file);
	if (!out.is_open())
		return (1);
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
			ki[j] = xi[j] + step / 2 * kj[j];
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
	ki.clear();
	kj.clear();
	kn.clear();
	xi.clear();
	xj.clear();
	return (0);
}

// std::vector <std::vector<double>>	RK_2(eq1 dx, double x0)
// {
// 	std::vector<std::vector<double>> yi;
// 	yi.resize(N + 1);
// 	yi[0].resize(1);
// 	yi[0][0] = x0;
// 	double step = (double)(T - T0) / N;
// 	double k1(0), k2(0);
// 	for (std::size_t i = 1; i < yi.size(); i++)
// 	{
// 		yi[i].resize(1);
// 		k1 = dx(T0 + i * step,  yi[i - 1][0]);
// 		k2 = dx(T0 + (i + 1) * step, yi[i - 1][0] + step * k1);
// 		yi[i][0] = yi[i - 1][0] + step * (0.5 * k1 + 0.5 * k2);
// 	}
// 	return (yi);
// }

// std::vector <std::vector<double>>	RK_4(eq1 dx, double x0)
// {
// 	std::vector<std::vector<double>> yi;
// 	yi.resize(N + 1);
// 	yi[0].resize(1);
// 	yi[0][0] = x0;
// 	double step = (double)(T - T0) / N;
// 	double k1(0), k2(0), k3(0), k4(0);
// 	for (std::size_t i = 1; i < yi.size(); i++)
// 	{
// 		yi[i].resize(1);
// 		k1 = dx(T0 + i * step,  yi[i - 1][0]);
// 		k2 = dx(T0 + i * step / 2, yi[i - 1][0] + step / 2 * k1);
// 		k3 = dx(T0 + i * step / 2, yi[i - 1][0] + step / 2 * k2);
// 		k4 = dx(T0 + i * step, yi[i - 1][0] + step * k3);
// 		yi[i][0] = yi[i - 1][0] + step * (k1 + 3 * k2 + 2 * k3 + k4) / 6;
// 	}
// 	return (yi);
// }