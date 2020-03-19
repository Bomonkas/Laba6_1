#include "numSolODE.h"
#include "equations.h"

int		take_param(double &t0, double &t, double &n, double &step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &method, std::string &out_file, std::vector<fun> &functions)
{
	std::string line;
	std::ifstream fin("project/settings/settings.txt");

	if (!fin.is_open())
		return (1);
	fin >> t0;
	getline(fin, line);
	fin >> t;
	getline(fin, line);
	fin >> n;
	getline(fin, line);
	fin >> step;
	getline(fin, line);
	line.clear();
	fin >> line;
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
	else if (line == "pend")
	{
		equations.resize(2);
		initial_cond.resize(2);
		functions.resize(2);
		functions[0] = sol_eq1_pend;
		functions[1] = sol_eq2_pend;
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
		return 1;
	}
	getline(fin, line);
	line.clear();
	fin >> method;
	getline(fin, line);
	line.clear();
	fin >> line;
	line = "project/initial_cond/" + line;
	std::ifstream init (line);
	if (!init.is_open())
	{
		equations.clear();
		initial_cond.clear();
		fin.close();
		return (1);
	}
	for (std::size_t i = 0; i < initial_cond.size(); i++)
		init >> initial_cond[i];
	init.close();
	getline(fin, line);
	line.clear();
	fin >> line;
	out_file = "project/output/" + line;
	fin.close();
//	std::cout << &equations << "\n";
	return 0;
}