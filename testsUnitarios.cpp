#include <iostream>
#include "dyv.hpp"
#include "iterativo.hpp"
#include "common.hpp"
#include <vector>
#include <chrono>
#include <cassert>

using namespace std;

set<char> S = {'a', 'b', 'c', 'd', 'e'};

void ejecutarTest(string nombreTest, string A, Solucion esperada)
{
    cout << nombreTest << ":" << endl;
    cout << "\t" << "Cadena A: \"" << A << "\"" << endl;
    cout << "\t" << "Resultado esperado: " << esperada.n_subcadenas << ", "
         << imprimirPosiciones(esperada.posiciones) << endl;

    // Medir tiempo algoritmo iterativo
    auto inicio_it = chrono::high_resolution_clock::now();
    Solucion solucionIterativo = iterativo(A, S);
    auto fin_it = chrono::high_resolution_clock::now();
    auto duracion_it = chrono::duration_cast<chrono::microseconds>(fin_it - inicio_it).count();

    // Medir tiempo algoritmo DyV
    auto inicio_dyv = chrono::high_resolution_clock::now();
    Solucion solucionDyV = DyV(A, 0, A.size() - 1, S);
    auto fin_dyv = chrono::high_resolution_clock::now();
    auto duracion_dyv = chrono::duration_cast<chrono::microseconds>(fin_dyv - inicio_dyv).count();

    cout << "\t" << "Resultado iterativo: " << solucionIterativo.n_subcadenas << ", "
         << imprimirPosiciones(solucionIterativo.posiciones) << " (" << duracion_it << " us)" << endl;
    cout << "\t" << "Resultado DyV: " << solucionDyV.n_subcadenas << ", "
         << imprimirPosiciones(solucionDyV.posiciones) << " (" << duracion_dyv << " us)" << endl;

    // Verificar resultados
    assert(solucionIterativo.n_subcadenas == esperada.n_subcadenas && "Error: iterativo n_subcadenas incorrecto");
    assert(solucionIterativo.posiciones == esperada.posiciones && "Error: iterativo posiciones incorrectas");
    assert(solucionDyV.n_subcadenas == esperada.n_subcadenas && "Error: DyV n_subcadenas incorrecto");
    assert(solucionDyV.posiciones == esperada.posiciones && "Error: DyV posiciones incorrectas");

    cout << "\t" << "Test " << nombreTest << " pasado correctamente" << endl
         << endl;
}

int main()
{
    cout << "Conjunto S: {a, b, c, d, e}" << endl
         << endl;

    ejecutarTest("MEJOR CASO", "abc", {1, {0}});
    ejecutarTest("PEOR CASO", "aaabbc", {0, {}});
    ejecutarTest("CASO PROMEDIO", "aabbde", {1, {3}});
    ejecutarTest("CASO TOTAL", "abcde", {3, {0, 1, 2}});

    cout << "✓ Todos los tests unitarios pasaron correctamente." << endl;
    return 0;
}