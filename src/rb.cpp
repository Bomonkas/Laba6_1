
void JacobiNum(TMatrix<double>& M, Vector(*targ_func)(const double, const Vector&), const double t, Vector& y0)
{
double eps = 1e-5;
size_t size = y0.size();
M.set_matrix_size(size, size);
Vector temp(y0), f0, feps;
f0 = targ_func(t,y0);
for (size_t i = 0; i < size; i++)
{
temp[i] += eps; //?????????? ?? i?? ?????????? ( ?????????? ??????? ????? ???? ?? ????????)
feps = targ_func(t,temp);

for (size_t j = 0; j < size; j++)
{
M(j, i) = (feps[j] - f0[j]) / eps;
}
temp[i] -= eps;
}
}

void JacobiNum(TMatrix<double>& M, Vector(*targ_func)(const Vector&, const Vector&, const double, const double, Vector(*f)(const double, const Vector&)),
Vector& y0, Vector& y_prev, const double t, const double tau,
Vector(*f)(const double, const Vector&))
{
double eps = 1e-5;
size_t size = y0.size();
M.set_matrix_size(size, size);
Vector temp(y0), f0, feps;
f0 = targ_func(y0, y_prev, t, tau, f);
for (size_t i = 0; i < size; i++)
{
temp[i] += eps; //?????????? ?? i?? ?????????? ( ?????????? ??????? ????? ???? ?? ????????)
feps = targ_func(temp, y_prev, t, tau, f);

for (size_t j = 0; j < size; j++)
{
M(j, i) = (feps[j] - f0[j]) / eps;
}
temp[i] -= eps;
}
}

Vector solve_system_NXN(Vector(*targ_func)(const Vector&, const Vector&,
const double, const double, Vector(*f)(const double, const Vector&)),
Vector& y0, Vector& y_prev, const double t, const double tau,
Vector(*f)(const double, const Vector&), const double eps)
{
Vector Y;
size_t dim = y0.size();
Vector roots;
Vector x_next;
Vector x_prev(y0);
x_next.resize(dim);
TMatrix<double> Jacobi;
double s;
size_t num_of_itters = 0;
Y.resize(dim);
Jacobi.set_matrix_size(dim, dim);
do
{
if (num_of_itters != 0) //????? ????????? ????????? ??????????? ?? 1 ????????
x_prev = x_next;
JacobiNum(Jacobi, targ_func, x_prev, y_prev, t, tau, f);
Y = Jacobi.FullGaussMethod(-1 * targ_func(x_prev, y_prev, t, tau, f));
x_next = x_prev + Y;
num_of_itters++;
s = find_residue(x_prev, x_next);
} while ((find_residue(x_prev, x_next) > eps) && (num_of_itters < 30));

if (num_of_itters != 30) //(???? ????? ???????, ?? ????????? ? ?????? ???????)
roots = x_next;
else
{
for (size_t i = 0; i < dim; i++)
roots[i] = 0;
}

num_of_itters = 0;

return roots;
}