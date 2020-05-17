#include "numSolODE.h"
#include "constants.h"

using namespace std;

int     main() {
    try {
        ODE ode("set.txt");
        ode.printInfo();
        switch(ode.getMethod()) {
        case Method::expEul:
            ode.expEul(t0, T, N);
            break;
        case Method::impEul:
            ode.impEul(t0, T, N);
            break;
        case Method::rk2:
            ode.rk2(t0, T, tau);
            break;
        case Method::rk4:
            ode.rk4(t0, T, tau);
            break;
        // case Method::preCor:
        //     ode.preCor();
        //     break;
        // case Method::adams:
        //     ode.adams();
        //     break;
        }
		cout << "maxError = " << setprecision(15) << ode.findError() << endl;
    }
    catch(const char* e) {
        std::cerr << e << '\n';
        return 1;
    }
    return 0;
}