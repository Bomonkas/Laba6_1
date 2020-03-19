#pragma once 
#include "numSolODE.h"

double		equation1_pend(double t, std::vector<double> &x); // equations discribing movement of the ball
double		equation2_pend(double t, std::vector<double> &x); // x1(t0) = 1, x2(t0) = 0
double		sol_eq1_pend(double t);
double		sol_eq2_pend(double t);

double		equation1_mytest1(double t, std::vector<double> &x);
double		sol_eq1_mytest1(double t);

double		equation1_mytest2(double t, std::vector<double> &x);
double		equation2_mytest2(double t, std::vector<double> &x);
double		sol_eq1_mytest2(double t);
double		sol_eq2_mytest2(double t);

double		equation1_test1(double t, std::vector<double> &x); // test 1 
double		equation2_test1(double t, std::vector<double> &x); // (1, 0) - saddle, (0, -1) - focus

double		equation1_test2(double t, std::vector<double> &x); // test 2
double		equation2_test2(double t, std::vector<double> &x); // (1, 0) - center, (0, -1) - saddle

double		equation1_test3(double t, std::vector<double> &x); // test 3
double		equation2_test3(double t, std::vector<double> &x);
double		equation3_test3(double t, std::vector<double> &x);


double		equation1_newton(double t, std::vector<double> &x); //for testing newton method
double		equation2_newton(double t, std::vector<double> &x);
std::vector<double>  test_new(double tau, std::vector<double> &yn,
			std::vector<double> &ym, std::vector<eq> &functions);
			
std::vector<double>		imp_eur_eq(double tau, std::vector<double> &yn,
						std::vector<double> &ym, std::vector<eq> &functions);
