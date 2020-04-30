#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

//pls use "using namespace std" in cpp file

typedef double (*eq)(double t, std::vector<double> &x);
typedef std::vector<double> (*method_func)(double tau, std::vector<double> &yn,
                                           std::vector<double> &ym, std::vector<eq> &functions);
typedef double (*fun)(double t);

class ODE {
private:
    std::vector<eq> equations;
    std::string method;
    std::string outputFile;

public:
    ODE(std::string nameOfInputFile);  //constructor
    ~ODE(); //destructor

    void printInfo();

    int expEul();  // explicit Euler method
    int impEul();  // implicit Euler method
    int rg2();     // Runge-Kutta method of the 2nd order
    int rg4();     // Runge-Kutta method of the 4th order
    int preCor();  // method of prediction and correction
    int adams();   // adams method
};