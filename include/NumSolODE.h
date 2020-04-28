#pragma once
#include <vector>
#include <iostream>
#include <cmath>

//pls use "using namespace std" in cpp file

typedef double(*eq) (double t, std::vector<double> &x);
typedef std::vector<double>(*method_func) (double tau, std::vector<double> &yn, 
		std::vector<double> &ym, std::vector<eq> &functions);
typedef double(*fun) (double t);

class ODE {
    private:
    std::vector<std::vector<double>> Solution;
	std::vector<eq> Equations;
	std::string Method;
	std::string OutputFile;
    public:
    ODE(); //constructor
    ~ODE(); //destructor
};