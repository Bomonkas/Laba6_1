#include "numSolODE.h"

int		get_grid(std::vector<double> grid)
{
	if (T - T0 <= 0)
	{
		std::cout << "Error with interval\n";
		return (0);
	}
	grid.resize(N + 1);
	double step = (double)(T - T0) / N;
	for (std::size_t i = 0; i < grid.size(); i++)
		grid[i] = T0 + i * step;
	print_v(grid);
	return (1);
}

void	print_v(std::vector<double> vec)
{
		for (std::size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
}

std::vector <double> exp_eu1(equat dx)
{
	std::vector<double> yi; // yj = y(i+1)
	std::vector<double> yj;
	yi.resize(N + 1);
	yj.resize(N + 1);
	yi[0] = dx(0, 0);
	double step = (double)(T0 - T) / N;
	for (std::size_t i = 1; i < yi.size(); i++)
	{
		yi[i] = dx(T0 + i * step, yi[i - 1]);
	}
	return (yi);
}

std::vector <std::pair<double, double>>	exp_eu(equat dx1, equat dx2)
{
	std::vector<std::pair<double, double>> sol;

	return (sol);
}