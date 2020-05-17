#pragma once
#include "numSolODE.h"

//method functions for newton
double impEulFunction(double tau, const std::vector<double> &current, 
		const std::vector<double> &previous, const eq &function, const int i) {
	return current[i] - previous[i] - tau * function(current);
}

//pendulum
double      equation1Pendulum(const std::vector<double> &x) {
    return x[1];
}

double      equation2Pendulum(const std::vector<double> &x) {
    double m = 10;
    double k = 10;
    return -m / k * x[0];
}

//my test1

double      equation1MyTest1(const std::vector<double> &x) {
    return -2 * x[0] + 4 * x[1];
}

double      equation2MyTest1(const std::vector<double> &x) {
    return -x[0] + 3 * x[1];
}

double      solution1MyTest1(const double t) {
    return -exp(-t) * (-4 + exp(3 * t));
}

double      solution2MyTest1(const double t) {
    return -exp(-t) * (-1 + exp(3 * t));
}

void        initConditionsMyTest1(std::vector<double> &init){
    init.resize(2);
    init[0] = 3;
    init[1] = 0;
}

//my test2

double      equation1MyTest2(const std::vector<double> &x) {
    return x[0] - 2 * x[1];
}

double      equation2MyTest2(const std::vector<double> &x) {
    return x[0] - x[1] - 2;
}

double      solution1MyTest2(const double t) {
    return 4 * sin(t) * sin(t) + 5 * sin(t) + 4 * cos(t) * cos(t) - 3 * cos(t);
}

double      solution2MyTest2(const double t) {
    return 2 * sin(t) * sin(t) + sin(t) + 2 * cos(t) * cos(t) - 4 * cos(t);
}

void        initConditionsMyTest2(std::vector<double> &init){
    init.resize(2);
    init[0] = 1;
    init[1] = -2;
}

// rb test

double      equation1RBTest(const std::vector<double> &x) {
    return 2 * x[0] + x[1] * x[1] - 1;
}

double      equation2RBTest(const std::vector<double> &x) {
    return 6 * x[0] - x[1] * x[1] + 1;
}

void        initConditionsRBTest(std::vector<double> &init){
    init.resize(2);
    init[0] = 1;
    init[1] = 0;
}