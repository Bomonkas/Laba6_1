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

std::vector <std::vector<double>> exp_eu1(eq1 dx, double x0)
{
	std::vector<std::vector<double>> yi; // yj = y(i+1)
	yi.resize(N + 1);
	yi[0].resize(1);
	yi[0][0] = x0;
	double step = (double)(T - T0) / N;
	for (std::size_t i = 1; i < yi.size(); i++)
	{
		yi[i].resize(1);
		yi[i][0] = yi[i - 1][0] + step * dx(T0 + i * step, yi[i - 1][0]);
	}
	return (yi);
}

std::vector <std::vector<double>>	exp_eu(eq2 dy, eq2 dz, double y0, double z0)
{
	std::vector<std::vector<double>> sol;
	sol.resize(N + 1);
	double step = (double)(T - T0) / N;
	sol[0].resize(2);
	sol[0][0] = y0;
	sol[0][1] = z0;
	for (std::size_t i = 1; i < sol.size(); i++)
	{
		sol[i].resize(2);
		sol[i][0] = sol[i - 1][0] + step * dy(T0 + i * step, sol[i - 1][0], sol[i - 1][1]);
		sol[i][1] = sol[i - 1][1] + step * dz(T0 + i * step, sol[i - 1][0], sol[i - 1][1]);
	}
	return (sol);
}