#pragma once
#include <vector>
#include <iostream>

#define T0 0
#define T 50
#define N 100
#define EPS 1e10-7
typedef double(*equat) (double x1, double x2);

int								get_grid(std::vector<double> grid);
void							print_v(std::vector<double> vec);
double							dx1_1(double x1, double x2);
double							dx2_1(double x1, double x2);
std::vector <double, double>	exp_eu(equat dx1, equat dx2);

