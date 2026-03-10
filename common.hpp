#ifndef COMMON_HPP
#define COMMON_HPP

#include <set>
#include <string>

using namespace std;

struct Solucion
{
    int n_subcadenas;
    set<int> posiciones;
};

bool esValida(const string& A, int inicio, const set<char>& S);
string imprimirConjunto(const set<char>& S);
string imprimirPosiciones(const set<int>& posiciones);

#endif
