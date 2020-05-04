#include "numSolODE.h"
#include "equations.h"

using namespace std;

void    putMethod(const string &line, Method &method) {
    if (line == "expEul")
        method = Method::expEul;
    if (line == "impEul")
        method = Method::impEul;
    if (line == "rg2")
        method = Method::rg2;
    if (line == "rg4")
        method = Method::rg4;   
    if (line == "preCor")
        method = Method::preCor;
    if (line == "adams")
        method = Method::adams;
}

void    putTestData(const string &name, std::vector<eq> &equations, 
                    std::vector<fun> &solution, std::vector<double> &init) {
        if (name == "myTest1"){
            equations.resize(2);
            solution.resize(2);
            equations[0] = equation1MyTest1;
            equations[1] = equation2MyTest1;
            solution[0] = solution1MyTest1;
            solution[1] = solution2MyTest1;
            initConditionsMyTest1(init);
        }else if (name == "myTest2") {
            equations.resize(2);
            solution.resize(2);
            equations[0] = equation1MyTest2;
            equations[1] = equation2MyTest2;
            solution[0] = solution1MyTest2;
            solution[1] = solution2MyTest2;
            initConditionsMyTest2(init);
        }
        else{
            throw "There is no such test";
        }
}

Method &ODE::getMethod(){
    return method;
}

ODE::ODE(string nameOfInputFile) {
    ifstream inFile(nameOfInputFile);
    if (!inFile.is_open()) {
        throw "file opening error";
    }
    string line;
    inFile >> line;
    putMethod(line, method);
    getline(inFile, line);
    inFile >> outputFile;
    getline(inFile, line);
    inFile >> line;
    putTestData(line, equations, exactSolution, initConditions);
}

ODE::~ODE() {
}

// if u want to be cool proger u need to implement overlod of << 
void ODE::printInfo() { 
    cout << "method: " << getMethod() << endl;
    cout << "outputFile: " << outputFile << endl;
    cout << "initConditions: x(t0) = " << initConditions[0] << ", y(t0) = " << initConditions[1] << endl;
}