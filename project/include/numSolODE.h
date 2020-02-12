#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

#define T0 0
#define T 1
#define N 10
#define EPS 1e10-7
typedef double(*equat) (double x1, double x2);
typedef double(*eq) (double x, double yi);

int								get_grid(std::vector<double> grid);
void							print_v(std::vector<double> vec);
double							dx1_1(double x1, double x2);
double							dx2_1(double x1, double x2);
double							dy(double x, double yi);
std::vector <std::pair<double, double>>	exp_eu(equat dx1, equat dx2);
std::vector <double>			exp_eu1(equat dx);

