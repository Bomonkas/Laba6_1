#include "numSolODE.h"

using namespace std;

void	putLine(ofstream &out, double t, const vector<double> x){
	out << t << " ";
	for (const double &elem:x){
		out << elem << " ";
	}
	out << "\n";
}

double	ODE::findError(){
	double maxError = 0;
	double localError = 0;
	ifstream in(outputFile);
	if (!in.is_open()){
		throw "output file doesn't open for reading";
	}
	double t = 0.0;
	double x = 0;
	while (in >> t) {
		for (const auto &func:exactSolution){
			in >> x;
			localError = fabs(func(t) - x);
			if (localError > maxError)
				maxError = localError;
		}
	}
	return maxError;
}