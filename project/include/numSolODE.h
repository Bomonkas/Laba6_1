#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define T0 0 
#define T 1
#define N 10
#define EPS 1e-10

#define M 10 // mass 
#define K 10 // redigity

#define S 10 
#define R 28
#define B 8/3


typedef double(*eq) (double t, std::vector<double> x);
// typedef double(*eq3) (double t, double x1, double x2, double x3);
// typedef double(*eq2) (double t, double x1, double x2);
// typedef double(*eq1) (double t, double x);

