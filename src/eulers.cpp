#include "numSolODE.h"

using namespace std;

int ODE::expEul(double t0, double T, int N) {
    double h = (T - t0) / N;
    vector<double> x{initConditions.begin(), initConditions.end()};
	vector<double> tmp_x(x.size());
	vector<double> func(x.size());
	ofstream out(outputFile);
	if (!out.is_open()) {
        throw "output file doesn't open for writing";
    }
	putLineToFile(out, t0, x);
    for (int i = 0; i < N; i++) {
		for (size_t j = 0; j < equations.size(); j++)
		{
			func[j] = equations[j](x);
			tmp_x[j] = x[j] + h * func[j];
		}
		putLineToFile(out, t0 + (i + 1) * h, tmp_x);
		swap(tmp_x, x);
    }
    return 0;
}

int ODE::impEul(double t0, double T, int N) {
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
    return 0;
}
