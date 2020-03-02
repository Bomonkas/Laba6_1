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
	// out << t0 << " ";
	// for (std::size_t j = 0; j < xj.size(); j++)
	// 		out << xi[j] << " ";
	// out << "\n";
	std::vector<std::vector<double>> A;
	A.resize(2);
	A[0].resize(2);
	A[1].resize(2);
	A[0][0] = 10;
	A[0][1] = 3;
	A[1][0] = 2;
	A[1][1] = 5;
	print_vvec(A);
	std::cout << "\n";
	print_vvec(inverse_matr(A));
	out.close();
	xi.clear();
	xj.clear();
	return (0);
}