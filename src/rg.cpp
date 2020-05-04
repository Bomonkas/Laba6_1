#include "numSolODE.h"

using namespace std;

int		ODE::rg2(double t0, double T, int N, double tau){
	double h = (T - t0) / N;
    vector<double> x{initConditions.begin(), initConditions.end()};
	vector<double> func{initConditions.begin(), initConditions.end()};
	vector<double> tmp_x{initConditions.begin(), initConditions.end()};
	ofstream out(outputFile);
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
	out << t0 << " ";
	for (const double &elem:x)
		out << elem << " ";
	out << "\n";
	double k1 = 0.5, k2 = 0.5;
	for (int i = 0; i < N; i++) {
        out << t0 + (i + 1) * h << " " << x[0] << " " << x[1] << "\n";
    }
}