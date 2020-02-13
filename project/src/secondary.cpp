#include "numSolODE.h"

void	print_v(std::vector<double> vec)
{
		for (std::size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
}

int		get_grid(std::vector<double> grid) // delete later
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
