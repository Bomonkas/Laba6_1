#pragma once
#include "numSolODE.h"

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