#include "numSolODE.h"

using namespace std;

int ODE::expEul(double t0, double T, int N) {
    double h = (T - t0) / N;
    vector<double> x = {initConditions[0], initConditions[1]};
    double f1 = 0.0, f2 = 0.0;
    cout << "Explicit Euler method:\n";
    for (int i = 0; i < N; i++) {
        f1 = equations[0](x);
        f2 = equations[1](x);
        x[0] = x[0] + h * f1;
        x[1] = x[1] + h * f2;
        cout << "i: " << i + 1 << endl;
        cout << "method : " << " x = " << x[0] << ", y = " << x[1] << endl;
        cout << "exact  : " << " x = " << exactSolution[0](t0 + (i + 1) * h) << //
        ", y = " << exactSolution[1](t0 + (i + 1) * h) << endl << endl;
    }
    return 0;
}

int ODE::impEul() {
    return 0;
}