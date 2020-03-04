#include "numSolODE.h"

std::vector<double>		imp_eur_eq(double tau, std::vector<double> yn,
			std::vector<double> ym, std::vector<eq> functions)
{
	std::vector<double> res;
	res.resize(yn.size());
	for (std::size_t i = 0; i < res.size(); i++)
	{
		res[i] = ym[i] - yn[i] - tau * functions[i](0.0, ym);
	}
	return (res);
}

double		equation1_newton(double t, std::vector<double> x) 
{
	return (x[0] * x[0] - x[1] * x[1] - 15);
}

double		equation2_newton(double t, std::vector<double> x) 
{
	return (x[0] * x[1] + 4);
}	


std::vector<double>  test_new(double tau, std::vector<double> yn,
			std::vector<double> ym, std::vector<eq> functions)
{
	std::vector<double> res;
	res.resize(yn.size());
	for (std::size_t i = 0; i < res.size(); i++)
	{
		res[i] = functions[i](0.0, ym);
	}
	return (res);
}