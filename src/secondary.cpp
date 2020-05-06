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

double derivative(double tau, const vector<double> &cur, const vector<double> &prev, 
const eq &equation,const int numOfEquat, const int numOfVar, const method_func &methodFunction){
	vector<double> deltaCurrent{cur.begin(), cur.end()};
	deltaCurrent[numOfVar] += 10e-10;
	return (methodFunction(tau, deltaCurrent, prev, equation, numOfEquat) - methodFunction(tau, cur, prev, equation, numOfEquat)) / 10e-10;
}

// vector<vector<double>> getYacobyMatrix(const vector<double> y, const vector<eq> &equations){
// 	vector<vector<double>> yacoby(y.size());
// 	for (size_t i = 0; i < y.size(); i++){
// 		yacoby[i].resize(y.size());
// 		for (size_t j = 0; j < y.size(); j++){
// 			yacoby[i][j] = derivative(equations[i], y, j);
// 		}
// 	}
// 	return yacoby;
// }

vector<vector<double>> getYacobyMatrix(double tau, const vector<double> &cur, const vector<double> &prev, 
const vector<eq> &equations, const method_func &methodFunction){
	vector<vector<double>> yacoby(cur.size());
	for (size_t i = 0; i < cur.size(); i++){
		yacoby[i].resize(cur.size());
		for (size_t j = 0; j < cur.size(); j++){
			yacoby[i][j] = derivative(tau, cur, prev, equations[i], i, j, methodFunction);
		}
	}
	return yacoby;
}

vector<double> multMatrixVector(const vector<vector<double>> &matr, const vector<double> &vec){
	vector<double> res(vec.size());
	for (size_t i = 0; i < vec.size(); i++){
		res[i] = 0;
		for (size_t j = 0; j < vec.size(); j++){
			res[i] += vec[j] * matr[i][j];
		}
	}
	return res;
}

vector<double> getFullMethodFunction(double tau, const vector<double> &cur, const vector<double> &prev, 
const vector<eq> &equations, const method_func &methodFunction){
	vector<double> res(cur.size());
	for (size_t i = 0; i < cur.size(); i++){
		res[i] = methodFunction(tau, cur, prev, equations[i], i);
	}
	return res;
}

vector<double> newton(double tau, const vector<double> &cur, const vector<double> &prev, 
const vector<eq> &equations, const method_func &methodFunction){
	vector<double> mult(cur.size());
	vector<double> next{prev.begin(), prev.end()};
	vector<double> current{cur.begin(), cur.end()};
	vector<double> previous{prev.begin(), prev.end()};
	vector<vector<double>> inverseYacobyMatr;
	int iter = 0;
	do {
		swap(next, previous);
		inverseYacobyMatr = getYacobyMatrix(tau, current, previous, equations, methodFunction);
		inverseYacobyMatr = getInverseMatrix(inverseYacobyMatr);
		mult = multMatrixVector(inverseYacobyMatr,
			getFullMethodFunction(tau, current, previous, equations, methodFunction));
		for (size_t i = 0; i < current.size(); i++){
			next[i] = current[i] - mult[i];
		}
		iter++;
		swap(next, current);
	} while (vectorResidual(current, next) < 10e-7 && iter == 30);
	if (iter == 30){
		cout << "too much iterations" << endl;
	}
	return current;
}