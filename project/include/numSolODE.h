#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

#define T0 0
#define T 1
#define N 5
#define EPS 1e-10
typedef double(*eq2) (double t, double x1, double x2);
typedef double(*eq1) (double x, double yi);

int									get_grid(std::vector<double> grid);
void								print_v(std::vector<double> vec);
double								dx1_1(double x1, double x2);
double								dx2_1(double x1, double x2);
double								dy(double x1, double x2);
double								dz(double x, double yi, double zi);
double								dy(double x, double yi, double zi);
double								dy1(double x, double yi);
std::vector <std::vector<double>>	exp_eu(eq2 dy, eq2 dz, double y0, double z0);
std::vector <std::vector<double>>	exp_eu1(eq1 dx, double y0);

