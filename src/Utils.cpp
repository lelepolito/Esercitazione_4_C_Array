
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Utils.hpp"
#include <iomanip> 
using namespace std;
/*
string ArrayToString(const size_t& n,
    const double* const& v)
{
string str;
ostringstream toString;
toString << "[ ";
for (unsigned int i = 0; i < n; i++)
toString<< v[i]<< " ";
toString << "]";

return toString.str();
}
*/

double CalcolaInteressi(const double& s, const size_t& n, const double* const& w, const double* const& r) {
    double out;
    for (unsigned int i = 0; i < n; i++) {
        out += s * w[i] * (r[i] + 1);
    }
    return out;
}
bool  EsportaRisultato(const string& file_name, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& V)
{ 

    ofstream file;
    file.open(file_name);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }
    file << fixed << setprecision(2) ;
    file << "S = "<< S  <<", n = " << n << endl;
    file << defaultfloat << setprecision(6);   
    file << "w = [ " ;
    for (unsigned int i = 0; i < n; i++){
        file << (i != 0 ? " " : "") << w[i];
    }
    file << " ]" << endl;

    file << "r = [" ;
    for (unsigned int i = 0; i < n; i++){
        file << (i != 0 ? " " : "") << r[i];
    }
    file << "]" << endl;

    file << "Rate of return of the portfolio: " << (V-S)/S << endl;

    file << fixed << setprecision(2) << "V: "<< V << endl;

    file.close();

    return true;
}

bool ImportData(const string& file_name, double& S, size_t& n, double*& w, double*& r) {
    ifstream file(file_name);
    string g;
    size_t pos;
    getline(file, g);
    S = stod(g.erase(0, 2));
    getline(file, g);
    n = stoi(g.erase(0, 2));
    getline(file, g);
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i < n; i++) {
        getline(file, g);
        pos = g.find(";");
        r[i] = stod(g.substr(pos +1 , g.length() - 1));
        g.erase(pos, g.length() - 1);
        w[i] = stod(g);
    }
    file.close();
    if (file.fail()) {
        cerr << "file open failed" << endl;
        return false;
    }
    return true;
}
