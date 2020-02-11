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