#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <iomanip>

//pls use "using namespace std" in cpp file

typedef double (*eq)(const std::vector<double> &x);
typedef std::vector<double> (*method_func)(double tau, std::vector<double> &current,
                                           std::vector<double> &previous, const std::vector<eq> &functions);
typedef double (*fun)(const double t);

enum Method {
    expEul,
    impEul,
    rk2,
    rk4,
    preCor,
    adams
};

class ODE {
private:
    std::vector<eq> equations;
    std::vector<fun> exactSolution;
    std::vector<double> initConditions;
	method_func methodFunction;
    Method method;
    std::string outputFile;

public:
    ODE(std::string nameOfInputFile);  //constructor
    ~ODE(); //destructor

    void	printInfo();
    Method	&getMethod();
	double	findError();
    int		expEul(double t0, double T, int N);  // explicit Euler method
    int		impEul(double tau);  // implicit Euler method
    int		rk2(double t0, double T, double tau);     // Runge-Kutta method of the 2nd order
    int		rk4();     // Runge-Kutta method of the 4th order
    int		preCor();  // method of prediction and correction
    int		adams();   // adams method
};

void	putLineToFile(std::ofstream &out, double t, const std::vector<double> x);
std::vector<std::vector<double>> getInverseMatrix(std::vector<std::vector<double>> &A);
void printMatrix(const std::vector<std::vector<double>> &A);
std::vector<double> newton(double tau, const std::vector<double> &cur,
const std::vector<double> &prev, const std::vector<eq> &equations, const method_func &methodFunction);