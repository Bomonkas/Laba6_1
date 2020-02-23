#include "numSolODE.h"
#include "equations.h"

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

int		take_param(double *t0, double *t, double *n, double *step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &method, std::string &out_file, std::vector<fun> &functions)
{
	std::string line;
	std::ifstream set("project/settings/settings.txt");

	if (!set.is_open())
		return (1);
	set >> *t0;
	getline(set, line);
	set >> *t;
	getline(set, line);
	set >> *n;
	getline(set, line);
	set >> *step;
	getline(set, line);
	char c = char(set.get());
	line.clear();
	while (c != ' ' && c != '\t')
	{
		line += c;
		c = char(set.get());
	}
	if (line == "myte5st1")
	{
		equations.resize(1);
		functions.resize(1);
		initial_cond.resize(1);
		functions[0] = sol_eq1_mytest1;
		equations[0] = equation1_mytest1;
	}
	else if (line == "mytest2")
	{
		equations.resize(2);
		initial_cond.resize(2);
		functions.resize(2);
		functions[0] = sol_eq1_mytest2;
		functions[1] = sol_eq2_mytest2;
		equations[0] = equation1_mytest2;
		equations[1] = equation2_mytest2;
	}
	else if (line == "test1")
	{
		equations.resize(2);
		initial_cond.resize(2);
		functions.resize(2);
		// functions[0] = sol_eq1_test1;
		// functions[1] = sol_eq2_test1;
		equations[0] = equation1_test1;
		equations[1] = equation2_test1;
	}
	else if (line == "test2")
	{
		equations.resize(2);
		initial_cond.resize(2);
		functions.resize(2);
		// functions[0] = sol_eq1_test2;
		// functions[1] = sol_eq2_test2;
		equations[0] = equation1_test2;
		equations[1] = equation2_test2;
	}
	else if (line == "test3")
	{
		equations.resize(3);
		functions.resize(3);
		initial_cond.resize(3);
		// functions[0] = sol_eq1_test3;
		// functions[1] = sol_eq2_test3;
		// functions[2] = sol_eq_test3;
		equations[0] = equation1_test3;
		equations[1] = equation2_test3;
		equations[2] = equation3_test3;
	}
	else 
	{
		return (1);
	}
	getline(set, line);
	c = char(set.get());
	while (c != ' ' && c != '\t')
	{
		method += c;
		c = char(set.get());
	}
	getline(set, line);
	c = char(set.get());
	line = "project/initial_cond/";
	while (c != ' ' && c != '\t')
	{
		line += c;
		c = char(set.get());
	}
	std::ifstream init (line);
	if (!init.is_open())
	{
		equations.clear();
		initial_cond.clear();
		set.close();
		return (1);
	}
	for (std::size_t i = 0; i < initial_cond.size(); i++)
		init >> initial_cond[i];
	init.close();
	getline(set, line);
	c = char(set.get());
	out_file = "project/output/";
	while (c != ' ' && c != '\t')
	{
		out_file += c;
		c = char(set.get());
	}
	set.close();
	return (0);
}

