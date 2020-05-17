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

double	YacobyElem(double tau, const vector<double> &prev, const vector<double> preprev,
const int numOfEquat, const int numOfVar, const vector<eq> &equations,
const method_func &methodFunction){
	vector<double> deltaPrev(prev.begin(), prev.end());
	deltaPrev[numOfVar] += 10e-10;
	return (methodFunction(tau, deltaPrev, preprev, equations[numOfEquat], numOfEquat) -
			methodFunction(tau, prev, preprev, equations[numOfEquat], numOfEquat)) / 10e-10;
	return 0;
}

vector<vector<double>> getYacobyMatrix(double tau, const vector<double> &prev,
const vector<double> &preprev, const vector<eq> &equations, 
const method_func &methodFunction){
	vector<vector<double>> Yacoby(prev.size());
	for (size_t numOfEquat = 0; numOfEquat < prev.size(); numOfEquat++){
		Yacoby[numOfEquat].resize(prev.size());
		for (size_t numOfVar = 0; numOfVar < prev.size(); numOfVar++){
			Yacoby[numOfEquat][numOfVar] = -YacobyElem(tau, prev, preprev, numOfEquat,
			numOfVar, equations, methodFunction);
		}
	}
	return Yacoby;
}

vector<double> newton(double tau, const vector<double> &prev_, 
const vector<double> &preprev_, const vector<eq> &equations, 
const method_func &methodFunction){
	vector<double> mult(prev_.size());
	vector<double> prev(prev_.begin(), prev_.end());
	vector<double> preprev(preprev_.begin(), preprev_.end());
	vector<double> curr(prev_.size());
	vector<vector<double>> inverseYacobyMatr;
	int iter = 0;
	do {
		if (iter != 0){
			preprev.assign(prev.begin(), prev.end());
			prev.assign(curr.begin(), curr.end());
		}
		inverseYacobyMatr = getYacobyMatrix(tau, prev, preprev, equations,
							methodFunction);
		inverseYacobyMatr = getInverseMatrix(inverseYacobyMatr);
		mult = multMatrixVector(inverseYacobyMatr,
			getFullMethodFunction(tau, prev, preprev, equations, methodFunction));
		for (size_t i = 0; i < prev.size(); i++){
			curr[i] = prev[i] + mult[i];
		}
		iter++;
	} while (vectorResidual(prev, curr) < 10e-7 && iter == 30);
	if (iter == 30){
		throw "too much iter in newton";
	}
	return curr;
}