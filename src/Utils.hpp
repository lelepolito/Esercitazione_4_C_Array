#pragma once

#include <iostream>

using namespace std;

/*
// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,const unsigned int* const& v);
*/

// EsportaRisultato export the result obtained in file
// file_name: path name of the output file
// S: initial amount of money
// n: number of assets in the portfolio
// w: weights of the assets in the portfolio
// r: returns of the assets in the portfolio
// V: final amount of money
bool  EsportaRisultato(const string& file_name, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& V);


// CalcolaInteressi calculates the interest rate of a portfolio
// s: initial amount of money
// n: number of assets in the portfolio
// w: weights of the assets in the portfolio
// r: returns of the assets in the portfolio
// return the resulting interest rate
double CalcolaInteressi(const double& s, const size_t& n, const double* const& w, const double* const&  v);



// ImportData reads the input data from file for portfolio calculation
// file_name: path name of the input file
// S: initial amount of money
// n: number of assets in the portfolio
// w: weights of the assets in the portfolio
// r: returns of the assets in the portfolio
// return the result of the reading, true is success, false is error
bool ImportData(const string& file_name, double& S, size_t& n, double*& w, double*& r);