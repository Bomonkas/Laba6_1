#include "numSolODE.h"

using namespace std;

int     main() {
    try
    {
        ODE ode("set.txt");
        switch(ode.getMethod()) {
        case Method::expEul:
            ode.expEul();
            break;
        case Method::impEul:
            ode.impEul();
        // case Method::rg2:
        //     ode.rg2();
        // case Method::rg4:
        //     ode.rg4();
        // case Method::preCor:
        //     ode.preCor();
        // case Method::adams:
        //     ode.adams();
        }
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
        return 1;
    }
    return 0;
}