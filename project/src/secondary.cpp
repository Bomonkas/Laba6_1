#include "numSolODE.h"
#include "equations.h"

void	print_v(std::vector<double> &vec)
{
	for (std::size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

// void	print_sol1(std::vector<std::vector<double>> sol)
// {
// 	std::cout << std::setw(8) << "t" << "      |";
// 	for (std::size_t i = 1; i <= sol[1].size(); i++)
// 		std::cout << "       x" << i << "     |";
// 	std::cout << "\n";
// 	for (std::size_t i = 1; i < sol.size(); i++)
// 	{
// 		std::cout << std::setw(14) << sol[0][i - 1] << "|";
// 		for (std::size_t j = 0; j < sol[i].size(); j++)
// 			std::cout << std::setw(14) <<  sol[i][j] << "|";
// 		std::cout << "\n";
// 	}
// 	std::cout << "\n";
// }

// void	print_sol(std::vector<std::vector<double>> sol)
// {
// 	double step = (double)(T - T0) / N;
// 	std::cout << std::setw(6) << "t" << "    |";
// 	for (std::size_t i = 0; i < sol[i].size(); i++)
// 	{
// 		std::cout << "     x" << i + 1 << "   |";
// 	}
// 	std::cout << "\n";
// 	for (std::size_t i = 0; i < sol.size(); i++)
// 	{
// 		std::cout << std::setw(10) << T0 + i * step << "|";
// 		for (std::size_t j = 0; j < sol[i].size(); j++)
// 			std::cout << std::setw(10) <<  sol[i][j] << "|";
// 		std::cout << "\n";
// 	}
// 	std::cout << std::endl;
// }

void    v_clean(std::vector<std::vector<double>> &vec)
{
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		vec[i].clear();
	}
	vec.clear();
}

void	print_vvec(std::vector<std::vector<double>> &A)
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

double	v_residual(std::vector<double> &vec1, std::vector<double> &vec2)
{
	double x = 0.0, max = 0.0;
	for(std::size_t j = 0; j < vec1.size(); j++)
	{
		x = fabs(vec1[j] - vec2[j]);
		if (x > max)
			max = x;
	}
	return max;
}

double	residual(std::string &outfile, std::vector<fun> &functions)
{
	std::ifstream set(outfile);
	if (!set.is_open())
		return -1.0;
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
	return max;
}

std::vector<double> 	my_newton(double tau, std::vector<double> &y_old,
						std::vector<double> &y_new, std::vector<eq> &equations, method_func F)
{
	std::vector<double> x_old; //xj = x(i+1)
	std::vector<double> x_new;
	std::vector<std::vector<double>> A;
	std::vector<double> tmp_v;
	tmp_v.resize(y_new.size());
	int iter = 0;
	x_old.resize(y_new.size());
	x_new.resize(y_new.size());
	for (std::size_t j = 0; j < x_old.size(); j++)
	{
		x_old[j] = y_new[j];
		x_new[j] = y_new[j];
	}
	//tmp_v = F(tau, y_old, x_old, equations);
	//print_v(tmp_v);
	do
	{
		A = matr_yac(tau, y_old, x_old, equations, F);
		A = inverse_matr(A);
//		print_v(tmp_f);
//		std::cout << "\n";
		tmp_v = mult_m_v(A, F(tau, y_old, x_old, equations));
		for (std::size_t j = 0; j < x_old.size(); j++)
		{
			x_new[j] = x_old[j] - tmp_v[j];
			x_old[j] = x_new[j];
		}
		iter++;
	} while (v_residual(x_old, x_new) > 10e-7 && iter < 100);
	if (iter == 100)
	{
		print_v(x_old);
		print_v(x_new);

		std::cout << "Too many iterations\n";
		x_new.resize(0);
	}
	return x_new;
}

std::vector<std::vector<double>> 	matr_yac(double tau, std::vector<double> &y_old, 
									std::vector<double> &y_new, std::vector<eq> &equations, method_func F)
{
	std::vector<std::vector<double>> res;
	double tmp_x;
	std::vector<double> tmp_f;
	res.resize(y_old.size());
	// std::cout << "yn: ";
	// print_v(yn);
	// std::cout << "ym: ";
	// print_v(ym);
	// std::cout << "tau = " << tau;
	// std::cout << "\nF: ";
	// print_v(tmp_f);
	// std::cout << std::endl;
	tmp_f = F(tau, y_old, y_new, equations);
	for (std::size_t i = 0; i < y_old.size(); i++)
	{
		res[i].resize(y_old.size());
		for (std::size_t j = 0; j < y_old.size(); j++)
		{
			tmp_x = y_new[j];
			y_new[j] += 10e-10;
			res[i][j] = (-tmp_f[i] + F(tau, y_old, y_new, equations)[i]) / 10e-10; 
			y_new[j] = tmp_x;
		}
	}
	return res;
}

std::vector<double>		mult_m_v(std::vector<std::vector<double>> matr, std::vector<double> vec)
{
	std::vector<double> res_vec;
	res_vec.resize(vec.size());

	for (int i = 0; i < vec.size(); i++)
	{
		double sum = 0;
		for (int j = 0; j < vec.size(); j++)
			sum += matr[i][j] * vec[j];
		res_vec[i] = sum;
	}
	return res_vec;
}