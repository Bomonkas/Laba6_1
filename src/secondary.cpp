#include "numSolODE.h"

using namespace std;

void	putLineToFile(ofstream &out, double t, const vector<double> x){
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

double vectorResidual(const vector<double> &first, const vector<double> &second){
	double res = 0.0, local;
	for (size_t i = 0; i < first.size(); i++){
		local = fabs(first[i] - second[i]);
		if (local > res)
			res = local;
	}
	return res;
}

double derivative(eq equation, const vector<double> y, const int i){
	vector<double> x{y.begin(), y.end()};
	vector<double> deltaX{y.begin(), y.end()};
	deltaX[i] += 10e-10;
	return (equation(deltaX) - equation(x)) / 10e-10;
}

vector<vector<double>> getYacobyMatrix(const vector<double> y, const vector<eq> &equations){
	vector<vector<double>> yacoby(y.size());
	for (size_t i = 0; i < y.size(); i++){
		yacoby[i].resize(y.size());
		for (size_t j = 0; j < y.size(); j++){
			yacoby[i][j] = derivative(equations[i], y, j);
		}
	}
	return yacoby;
}

vector<double> newton(double tau, const vector<double> &cur, const vector<double> &prev, 
const vector<eq> &equations) {
	vector<double> res(cur.size());
	vector<double> current{cur.begin(), cur.end()};
	vector<double> previous{prev.begin(), prev.end()};
	vector<vector<double>> inverseYacobyMatr = getYacobyMatrix(current, equations);
	printMatrix(inverseYacobyMatr);
	inverseYacobyMatr = getInverseMatrix(inverseYacobyMatr);
	printMatrix(inverseYacobyMatr);
	// int iter = 0;
	// do {
	// 	for (size_t i = 0; i < current.size(); i++){
	// 		//res[i] = current[i] - multMatrixVector(inverseYacobyMatr, methodFunc);
	// 	}
	// 	iter++;

	// } while (vectorResidual(current, previous) < 10e-7 && iter == 30);
	return res;
}