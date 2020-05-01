#include "numSolODE.h"

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
}

ODE::~ODE() {
}

// if u want to be cool proger u need to implement overlod of << 
// void ODE::printInfo() { 
//     cout << "method: " << getMethod() << endl;
//     cout << "outputFile: " << outputFile << endl;
// }