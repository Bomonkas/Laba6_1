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
            ode.impEul();
            break;
        // case Method::rg2:
        //     ode.rg2();
        //     break;
        // case Method::rg4:
        //     ode.rg4();
        //     break;
        // case Method::preCor:
        //     ode.preCor();
        //     break;
        // case Method::adams:
        //     ode.adams();
        //     break;
        }
		cout << "maxError = " << ode.findError() << endl;
    }
    catch(const char* e) {
        std::cerr << e << '\n';
        return 1;
    }
    return 0;
}