#include "numSolODE.h"

using namespace std;

int		ODE::rk2(double t0, double T, double tau) {
	double n = (T - t0) / tau;
    vector<double> x{initConditions.begin(), initConditions.end()};
	vector<double> k1(x.size());
	vector<double> k2(x.size());
	ofstream out(outputFile);
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
	putLineToFile(out, t0, x);
	double a1 = 0.5;
	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < x.size(); j++) {
			k1[j] = a1 * tau * equations[j](x) + x[j];
		}
		for (size_t j = 0; j < x.size(); j++) {
			k2[j] = tau * equations[j](k1) + x[j];
		}	
        putLineToFile(out, t0 + (i + 1) * tau, k2);
		swap(k2, x);
    }
	return 0;
}

int		ODE::rk4(double t0, double T, double tau) {
	double n = (T - t0) / tau;
    vector<double> x{initConditions.begin(), initConditions.end()};
	vector<double> k1(x.size());
	vector<double> k2(x.size());
	vector<double> k3(x.size());
	vector<double> k4(x.size());
	vector<double> tmp_1(x.size());
	vector<double> tmp_2(x.size());
	ofstream out(outputFile);
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
	putLineToFile(out, t0, x);
	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < x.size(); j++) {
			k1[j] = equations[j](x);
			tmp_1[j] = x[j] + tau / 2 * k1[j];
		}
		for (size_t j = 0; j < x.size(); j++) {
			k2[j] = equations[j](tmp_1);
			tmp_2[j] = x[j] + tau / 2 * k2[j];
		}
		for (size_t j = 0; j < x.size(); j++) {
			k3[j] = equations[j](tmp_2);
			tmp_1[j] = x[j] + tau / 2 * k3[j];
		}
		for (size_t j = 0; j < x.size(); j++) {
			k4[j] = x[j] + tau / 6 * (equations[j](tmp_1) + k1[j] + 2 * k2[j] + 2 * k3[j]);
		}
        putLineToFile(out, t0 + (i + 1) * tau, k4);
		swap(k4, x);
    }
	return 0;
}