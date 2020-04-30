#include "NumSolODE.h"

using namespace std;

ODE::ODE(string nameOfInputFile) {
    ifstream inFile(nameOfInputFile);
    if (!inFile.is_open()) {
        throw "file opening error";
    }
    string line;
    inFile >> method;
    getline(inFile, line);
    inFile >> outputFile;
    getline(inFile, line);
}

ODE::~ODE() {
}

void ODE::printInfo() {
    cout << "method: " << method << endl;
    cout << "outputFile: " << outputFile << endl;
}