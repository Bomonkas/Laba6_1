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

