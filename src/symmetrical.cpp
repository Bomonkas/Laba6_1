#include "numSolODE.h"

using namespace std;

int ODE::symmetrical(double t0, double T, int N){
	double h = (T - t0) / N;
	ofstream out(outputFile);
	vector<double> prev(initConditions.begin(), initConditions.end());
	vector<double> init(initConditions.size());
	vector<double> curr{initConditions.begin(), initConditions.end()};
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
	putLineToFile(out, t0, prev);
    for (int i = 0; i < N; i++) {
		curr = newton(h, init, prev, equations, methodFunction);
		prev.assign(curr.begin(), curr.end());
		putLineToFile(out, t0 + (i + 1) * h, curr);
    }
}