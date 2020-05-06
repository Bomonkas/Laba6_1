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

int ODE::impEul(double tau) {
	vector<double> current{3, 0};
	vector<double> previous{0, 0};
	newton(tau, current, previous, equations);
    return 0;
}