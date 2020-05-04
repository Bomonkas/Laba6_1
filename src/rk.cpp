#include "numSolODE.h"

using namespace std;

int		ODE::rk2(double t0, double T, double tau){
	double n = (T - t0) / tau;
    vector<double> x{initConditions.begin(), initConditions.end()};
	vector<double> k1(x.size());
	vector<double> k2(x.size());
	ofstream out(outputFile);
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
	putLine(out, t0, x);
	double a1 = 0.5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < static_cast<int>(x.size()); j++){
			k1[j] = a1 * tau * equations[j](x) + x[j];
		}
		for (int j = 0; j < static_cast<int>(x.size()); j++){
			k2[j] = tau * equations[j](x) + x[j];
		}	
        putLine(out, t0 + (i + 1) * tau, k2);
		swap(k2, x);
    }
}