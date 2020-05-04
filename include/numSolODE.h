#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

//pls use "using namespace std" in cpp file

typedef double (*eq)(const std::vector<double> &x);
typedef std::vector<double> (*method_func)(double tau, std::vector<double> &yn,
                                           std::vector<double> &ym, std::vector<eq> &functions);
typedef double (*fun)(const double t);

enum Method {
    expEul,
    impEul,
    rg2,
    rg4,
    preCor,
    adams
};

class ODE {
private:
    std::vector<eq> equations;
    std::vector<fun> exactSolution;
    std::vector<double> initConditions;
    Method method;
    std::string outputFile;

public:
    ODE(std::string nameOfInputFile);  //constructor
    ~ODE(); //destructor

    void	printInfo();
    Method	&getMethod();
	double	findError();
    int		expEul(double t0, double T, int N);  // explicit Euler method
    int		impEul();  // implicit Euler method
    int		rg2(double t0, double T, int N, double tau);     // Runge-Kutta method of the 2nd order
    int		rg4();     // Runge-Kutta method of the 4th order
    int		preCor();  // method of prediction and correction
    int		adams();   // adams method
};

void	putLine(std::ofstream &out, double t, const std::vector<double> x);