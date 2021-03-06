#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

const int M = 10; // mass 
const int K = 10; // redigity

const int S = 10;
const int R = 28;
const int B = 8/3;

typedef double(*eq) (double t, std::vector<double> &x);
typedef std::vector<double>(*method_func) (double tau, std::vector<double> &yn, 
		std::vector<double> &ym, std::vector<eq> &functions);
typedef double(*fun) (double t);

void	print_v(std::vector<double> &vec);
void	v_clean(std::vector<std::vector<double>> &vec);
void	print_sol(std::vector<std::vector<double>> &sol);
void	print_sol1(std::vector<std::vector<double>> &sol);
int		take_param(double &t0, double &t, double &n, double &step,
		std::vector<eq> &equations, std::vector<double> &initial_cond,
		std::string &method, std::string &out_file, std::vector<fun> &functions);
double	residual(std::string &outfile, std::vector<fun> &functions);
void	print_vvec(std::vector<std::vector<double>> &A);

std::vector<std::vector<double>>	inverse_matr(std::vector<std::vector<double>> &A);
std::vector<std::vector<double>>	matr_yac(double tau, std::vector<double> &yn, 
									std::vector<double> &ym, std::vector<eq> &equations, method_func F);
std::vector<double>					mult_m_v(std::vector<std::vector<double>> matr, std::vector<double> vec);
std::vector<double>					my_newton(double tau, std::vector<double> &yn, 
std::vector<double> 				&ym, std::vector<eq> &equations, method_func F);

int		exp_eur(double t0, double t, double n, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file);

int		imp_eur(double t0, double t, double n, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file);

int		rk2(double t0, double t, double step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file);
int		rk4(double t0, double t, double step, std::vector<eq> &equations, 
		std::vector<double> &initial_cond, std::string &out_file);

