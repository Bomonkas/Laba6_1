#include "numSolODE.h"
#include <iostream>

// need to implement
// метод Рунге-Кутты 4-го порядка точности
// метод Адамса-Башфорта 4-го порядка точности 
// метод прогноз-коррекция 4-го порядка точности
// метод Рунге-Кутты 2-го порядка
// Симметричную разностную схему
// Явный Эйлер
// Неявный Эйлер

int main() {
	std::vector<double> grid;
	if (!get_grid(grid))
		return (0);
	print_v(grid);
	std::cout << "Laba #6\nMethods of numerical solution of ODE\n";
	return 0;
}