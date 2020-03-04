#include "numSolODE.h"
#include "equations.h"

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
	if (line == "test1")
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