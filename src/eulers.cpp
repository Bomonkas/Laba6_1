#include "numSolODE.h"

using namespace std;

int ODE::expEul(double t0, double T, int N) {
    double h = (T - t0) / N;
    vector<double> x = {initConditions[0], initConditions[1]};
	ofstream out(outputFile);
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
    double f1 = 0.0, f2 = 0.0;
	out << t0 << " " << x[0] << " " << x[1] << "\n";
    for (int i = 0; i < N; i++) {
        f1 = equations[0](x);
        f2 = equations[1](x);
        x[0] = x[0] + h * f1;
        x[1] = x[1] + h * f2;
        out << t0 + (i + 1) * h << " " << x[0] << " " << x[1] << "\n";
    }
    return 0;
}

int ODE::impEul() {
    return 0;
}