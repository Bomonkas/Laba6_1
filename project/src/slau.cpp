#include "numSolODE.h"

int is_zero(double elem)
{
	if (fabs(elem) <= 10e-11)
		return 1;
	return 0;
}

int find_and_swap(std::vector<std::vector<double>> A, std::vector<double> B1, int k)
{
	if (!A.size() || !B1.size())
	{
		std::cout << "Matrix is not exist\n";
		return 1;
	}
	std::vector<double> tmp_a;
	double tmp_b;
	int num_max = 0;
	double max = 0.0;

	for (int i = k; i < A[0].size(); i++)
	{
		if (fabs(A[i][k]) > max)
		{
			max = fabs(A[i][k]);
			num_max = i;
		}
	}
	if (is_zero(max))
	{
		return 1;
	}
	tmp_a = A[num_max];
	A[num_max] = A[k];
	A[k] = tmp_a;
	tmp_b = B1[num_max];
	B1[num_max] = B1[k];
	B1[k] = tmp_b;
	return 0;
}

std::vector<double> reverse_move(std::vector<std::vector<double>> A, std::vector<double> B1)
{
	std::vector<double> result;
	result.resize(A[0].size());
	for (int i = A[0].size() - 1; i >= 0; i--)
	{
		double sum = 0.0;
		if (i != A[0].size() - 1)
			for (int j = i + 1; j < A[0].size(); j++)
			{
				sum += A[i][j] * result[j];
			}
		if (is_zero(A[i][i]))
		{
			std::cout << "0 on the diag\n";
			result.resize(0);
			return result;
		}
		else
		{
			result[i] = (B1[i] - sum) / A[i][i];
		}
		if (is_zero(result[i]))
		{
			result[i] = 0.0;
		}
	}
	return result;
}

std::vector<double> gauss(std::vector<std::vector<double>> A, std::vector<double> C)
{
	double koff = 0;
	for (int k = 0; k < A.size(); k++)
	{
		if (find_and_swap(A, C, k))
		{
			std::cout << "The matrix is degenerate\n";
			C.resize(0);
			return C;
		}
		for (int j = k + 1; j < A.size(); j++)
		{
			koff = A[j][k] / A[k][k];
			for (int i = k; i < A.size(); i++)
			{
				if (i == k)
					A[j][i] = 0.0;
				else
					A[j][i] -= koff * A[k][i];
				if (is_zero(A[i][j]))
					A[i][j] = 0.0;
			}
			C[j] -= koff * C[k];
			if (is_zero(C[j]))
			{
				C[j] = 0.0;
			}
		}
	}
	return reverse_move(A, C);
}

std::vector<std::vector<double>> inverse_matr(std::vector<std::vector<double>> A)
{
	std::vector<std::vector<double>> res_matr;
	res_matr.resize(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		res_matr[i].resize(A[i].size());
	}

	std::vector<std::vector<double>> copy_A;
	copy_A.resize(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		copy_A[i].resize(A[i].size());
	}

	std::vector<std::vector<double>> E;
	E.resize(A.size());
	std::vector<double> tmp;
	for (int i = 0; i < A.size(); i++)
	{
		E[i].resize(A[i].size());
		for (int j = 0; j < A[i].size(); j++)
		{
			if (i == j)
			{
				E[i][j] = 1.;
			}
			else
			{
				E[i][j] = 0.;
			}
		}
	}

	for (int i = 0; i < A.size(); i++)
	{
		for (int k = 0; k < A[i].size(); k++)
		{
			for (int l = 0; l < A[i].size(); l++)
			{
				copy_A[k][l] = A[k][l];
			}
		}

		tmp = gauss(copy_A, E[i]);
		if (!tmp.size())
		{
			res_matr.resize(0);
			return res_matr;
		}
		for (int j = 0; j < A.size(); j++)
		{
			res_matr[j][i] = tmp[j];
		}
		tmp.resize(0);
	}
	copy_A.resize(0);
	E.resize(0);
	return res_matr;
}