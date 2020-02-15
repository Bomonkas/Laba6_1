#include "numSolODE.h"

double		equation1_mytest1(double t, std::vector<double> x)
{
	return (2 * (t * t + x[0]));
}

double		equation1_mytest2(double t, std::vector<double> x)
{
	return (x[1]);
}

double		equation2_mytest2(double t, std::vector<double> x)
{
	return (-2 * x[1] - x[0] + t);
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

// ////////////////////////////////////////////////////////////////////////////////////////////
// // test1
// double		d1test1(double t, double x1, double x2) 
// {
// 	return (2 * x1 + x2 * x2 - 1);
// }	

// double		d2test1(double t, double x1, double x2)
// {
// 	return (6 * x1 - x2 * x2 + 1);
// }												

// ////////////////////////////////////////////////////////////////////////////////////////////
// // test2
// double		d1test2(double t, double x1, double x2) 
// {
// 	return (1 - x1 * x1 - x2 * x2);
// }	

// double		d2test2(double t, double x1, double x2)
// {
// 	return (2 * x1);
// }													

// ////////////////////////////////////////////////////////////////////////////////////////////
// // test3
// double		d1test3(double t, double x1, double x2, double x3) 
// {
// 	return (S * (x2 - x1));
// }	

// double		d2test3(double t, double x1, double x2, double x3)
// {
// 	return (x1 * (R - x3) - x2);
// }	

// double		d3test3(double t, double x1, double x2, double x3)
// {
// 	return (x1 * x2 - B * x3);
// }	

