#pragma once

#include "numSolODE.h"

std::vector <std::vector<double>>	exp_eu(eq2 dy, eq2 dz, double y0, double z0);
std::vector <std::vector<double>>	exp_eu1(eq1 dx, double y0);