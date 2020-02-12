#include "numSolODE.h"

double	dx1_1(double x1, double x2)
{
	if (fabs(x1) < EPS && fabs(x2) > EPS)
		return (-2.1 + x2);
	if (fabs(x1) < EPS && fabs(x2) < EPS)
		return (-0.1);
	if (fabs(x1) > EPS && fabs(x2) < EPS)
		return (0.4 - 2.5 * x1 + 2 * x1 * x1);
	return (0.4 - 2.5 * x1 + x1 * x1 * x2);
}
double	dx2_1(double x1, double x2)
{
	if (fabs(x1) < EPS && fabs(x2) > EPS)
		return (1.5 - x2);
	if (fabs(x1) < EPS && fabs(x2) < EPS)
		return (-0.5);
	if (fabs(x1) > EPS && fabs(x2) < EPS)
		return (1.5 * x1 - 2 * x1 * x1);
	return (1.5 * x1 - x1 * x1 * x2);
}

double							dy(double x, double yi)
{
	if (fabs(x) < EPS)
	{
		std::cout << x << " " << EPS << "\n";
		return (2);
	}
	return (2 * (x * x + yi));
}
