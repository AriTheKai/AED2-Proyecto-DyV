#include <iostream>
#include "dyv.hpp"
#include "iterativo.hpp"
#include "common.hpp"
#include <vector>
#include <chrono>
#include <cassert>

using namespace std;

set<char> S = {'a', 'b', 'c', 'd', 'e'};

void ejecutarTest(string nombreTest, const string& A, Solucion esperada)
{

    Solucion solucionIterativo = iterativo(A, S);
    Solucion solucionDyV = DyV(A, 0, A.size() - 1, S);

    // Verificar resultados
    assert(solucionIterativo.n_subcadenas == esperada.n_subcadenas && "Error: iterativo n_subcadenas incorrecto");
    assert(solucionIterativo.posiciones == esperada.posiciones && "Error: iterativo posiciones incorrectas");
    assert(solucionDyV.n_subcadenas == esperada.n_subcadenas && "Error: DyV n_subcadenas incorrecto");
    assert(solucionDyV.posiciones == esperada.posiciones && "Error: DyV posiciones incorrectas");

    cout << "Test " << nombreTest << " pasado correctamente" << endl;
}

int main()
{

    ejecutarTest("MEJOR CASO", "abc", {1, {0}});
    ejecutarTest("PEOR CASO", "aaabbc", {0, {}});
    ejecutarTest("CASO PROMEDIO", "aabbde", {1, {3}});
    ejecutarTest("CASO TOTAL", "abcde", {3, {0, 1, 2}});

    cout << "✓ Todos los tests unitarios pasaron correctamente." << endl;
    return 0;
}