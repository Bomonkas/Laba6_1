#include "numSolODE.h"

int	imp_eur(double t0, double t, double n, std::vector<eq> equations, 
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
	// std::vector<std::vector<double>> F; //it was test of work inv & matr_yac func
	// F = matr_yac(equations, xi); //you need to implement Newton method for solving non-linear
	// print_vvec(F);				//equations, & implicit euler method
	// std::cout << "\n";
	// print_vvec(inverse_matr(F));
	out.close();
	xi.clear();
	xj.clear();
	return (0);
}