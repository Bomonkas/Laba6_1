#include "numSolODE.h"
#include "equations.h"

void	print_v(std::vector<double> vec)
{
	for (std::size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void	print_sol1(std::vector<std::vector<double>> sol)
{
	std::cout << std::setw(8) << "t" << "      |";
	for (std::size_t i = 1; i <= sol[1].size(); i++)
		std::cout << "       x" << i << "     |";
	std::cout << "\n";
	for (std::size_t i = 1; i < sol.size(); i++)
	{
		std::cout << std::setw(14) << sol[0][i - 1] << "|";
		for (std::size_t j = 0; j < sol[i].size(); j++)
			std::cout << std::setw(14) <<  sol[i][j] << "|";
		std::cout << "\n";
	}
	std::cout << "\n";
}

void	print_sol(std::vector<std::vector<double>> sol)
{
	double step = (double)(T - T0) / N;
	std::cout << std::setw(6) << "t" << "    |";
	for (std::size_t i = 0; i < sol[i].size(); i++)
	{
		std::cout << "     x" << i + 1 << "   |";
	}
	std::cout << "\n";
	for (std::size_t i = 0; i < sol.size(); i++)
	{
		std::cout << std::setw(10) << T0 + i * step << "|";
		for (std::size_t j = 0; j < sol[i].size(); j++)
			std::cout << std::setw(10) <<  sol[i][j] << "|";
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void    v_clean(std::vector<std::vector<double>> vec)
{
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		vec[i].clear();
	}
	vec.clear();
}

void	print_vvec(std::vector<std::vector<double>> A)
{
	for (std::size_t i = 0; i < A.size(); i++)
	{
		for(std::size_t j = 0; j < A[i].size(); j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
}

double	v_residual(std::vector<double> vec1, std::vector<double> vec2)
{
	double x = 0.0, max = 0.0;
	for(std::size_t j = 0; j < vec1.size(); j++)
	{
		x = fabs(vec1[j] - vec2[j]);
		if (x > max)
			max = x;
	}
	return (max);
}

double	residual(std::string outfile, std::vector<fun> functions)
{
	std::ifstream set(outfile);
	if (!set.is_open())
		return (-1.0);
	double x = 0.0, max = 0.0, t = 0.0;
	while(set >> t)
	{
		for (std::size_t i = 0; i < functions.size(); i++)
		{
			set >> x;
			x = fabs(x - functions[i](t));
			if (x > max)
				max = x;
		}
	}
	return (max);
}

std::vector<double> 	my_newton(double tau, std::vector<double> yn, 
std::vector<double> ym, std::vector<eq> equations, method_func F)
{
	std::vector<double> xi; //xj = x(i+1)
	std::vector<double> xj;
	std::vector<std::vector<double>> A;
	std::vector<double> tmp_f;
	tmp_f.resize(ym.size());
	int iter = 0;
	xi.resize(ym.size());
	xj.resize(ym.size());
	for (std::size_t j = 0; j < xi.size(); j++)
	{
		xi[j] = 0;
		xj[j] = 0;
	}
	tmp_f = F(tau, yn, xi, equations);
	print_v(tmp_f);
	do
	{
		A = inverse_matr(matr_yac(tau, yn, xi, equations, F));
//		print_v(tmp_f);
//		std::cout << "\n";
		tmp_f = F(tau, yn, xi, equations);
		for (std::size_t j = 0; j < xi.size(); j++)
			for (std::size_t k = 0; k < xi.size(); k++)
				xj[j] -= A[j][k] * tmp_f[k];
		for (std::size_t j = 0; j < xi.size(); j++)
			xi[j] = xj[j];
		iter++;
	} while (v_residual(xi, xj) > 10e-7 || iter < 100);
	if (iter == 100)
	{
		std::cout << "Too many iterations\n";
		xj.resize(0);
	}
	return (xj);
}

std::vector<std::vector<double>> matr_yac(double tau, std::vector<double> yn, 
std::vector<double> ym, std::vector<eq> equations, method_func F)
{
	std::vector<std::vector<double>> res;
	double tmp_x;
	std::vector<double> tmp_f;
	res.resize(yn.size());
	// std::cout << "yn: ";
	// print_v(yn);
	// std::cout << "ym: ";
	// print_v(ym);
	// std::cout << "tau = " << tau;
	// std::cout << "\nF: ";
	// print_v(tmp_f);
	// std::cout << std::endl;
	tmp_f = F(tau, yn, ym, equations);
	for (std::size_t i = 0; i < yn.size(); i++)
	{
		res[i].resize(yn.size());
		for (std::size_t j = 0; j < yn.size(); j++)
		{
			tmp_x = ym[j];
			ym[j] += 10e-10;
			res[i][j] = (-tmp_f[i] + F(tau, yn, ym, equations)[i]) / 10e-10; 
			ym[j] = tmp_x;
		}
	}
	return (res);
}


