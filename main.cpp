
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/Utils.hpp"


using namespace std;

int main()
{
    string file_name = "./data.txt";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double V = 0;
    if (!ImportData(file_name, S, n, w, r))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }
    else
        cout << "Import successful" << endl;
    V = CalcolaInteressi(S, n, w, r);
    string outputFileName = "./result.txt";   
    if (!EsportaRisultato(outputFileName, S, n, w, r, V))
    {
        cerr << "Something goes wrong with export" << endl;
        return -1;
    }
    else
        cout << "Export successful" << endl;
    delete[] w;
    delete[] r;

    return 0;
}

