#include "numSolODE.h"

double		equation1_mytest1(double t, std::vector<double> x)
{
	return (2 * (t * t + x[0]));
}

double		sol_eq1_mytest1(double t)
{
	return (1.5 * exp (2 * t) - t * t - t - 0.5);
}

/////////////////////////////////////////
double		equation1_mytest2(double t, std::vector<double> x)
{
	return (x[1]);
}

double		equation2_mytest2(double t, std::vector<double> x)
{
	return (-2 * x[1] - x[0] + t);
}

double		sol_eq1_mytest2(double t)
{
	return (exp(-t) * (3 - 2 * exp(t) + 2 * t + exp(t) * t));
}

double		sol_eq2_mytest2(double t)
{
	return (exp(-t) * (-1 + exp(t) - 2 * t));
}

// equations discribing movement of the ball
double		equation1_pend(double t, std::vector<double> x)
{
	return (x[1]);
}

double		equation2_pend(double t, std::vector<double> x)
{
	return (-M / K * x[0]);
}												   

double		sol_eq1_pend(double t)
{
	return (cos(sqrt(K) / sqrt(M) * t));
}

double		sol_eq2_pend(double t)
{
	return (-sqrt(K) / sqrt(M) * sin(sqrt(K) / sqrt(M) * t));
}

// ////////////////////////////////////////////////////////////////////////////////////////////
// test1
double		equation1_test1(double t, std::vector<double> x) 
{
	return (2 * x[0] + x[1] * x[1] - 1);
}	

double		equation2_test1(double t, std::vector<double> x)
{
	return (6 * x[0]- x[1] * x[1] + 1);
}												

////////////////////////////////////////////////////////////////////////////////////////////
// test2
double		equation1_test2(double t, std::vector<double> x) 
{
	return (1 - x[0] * x[0] - x[0] * x[1]);
}	

double		equation2_test2(double t, std::vector<double> x)
{
	return (2 * x[0]);
}													

// ////////////////////////////////////////////////////////////////////////////////////////////
// test3
double		equation1_test3(double t, std::vector<double> x) 
{
	return (S * (x[1] - x[0]));
}	

double		equation2_test3(double t, std::vector<double> x)
{
	return (x[0] * (R - x[2]) - x[1]);
}	

double		equation3_test3(double t, std::vector<double> x)
{
	return (x[0] * x[1] - B * x[2]);
}	

