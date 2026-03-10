#include <iostream>
#include "dyv.hpp"
#include "iterativo.hpp"
#include "common.hpp"
#include <vector>
#include <chrono>
#include <cassert>

using namespace std;

const string caracteres = "abcdefghijklmnopqrstuvwxyz";

string generarCadena(int longitud, set<char> S)
{
    string cadena;

    // Solo usar caracteres del conjunto S para generar la cadena
    vector<char> chars(S.begin(), S.end());

    for (int i = 0; i < longitud; i++)
    {
        char c = chars[rand() % chars.size()];
        cadena += c;
    }

    return cadena;
}

set<char> generarConjunto()
{
    set<char> S;
    int n = rand() % 3 + 3; // Entre 3 y 5 caracteres

    for (int i = 0; i < n; i++)
    {
        char c = caracteres[rand() % caracteres.size()];
        S.insert(c);
    }

    return S;
}

int main()
{
    srand(time(0)); // Semilla para generación aleatoria

    vector<int> longitudes = {3, 10, 25, 50, 100, 500, 1000};

    for (int longitud : longitudes)
    {
        set<char> S = generarConjunto();
        string A = generarCadena(longitud, S);

        // Calculamos tiempos de ejecución para ambos algoritmos
        auto start = chrono::high_resolution_clock::now();
        Solucion solDyV = DyV(A, 0, A.size() - 1, S);
        auto end = chrono::high_resolution_clock::now();
        auto durationDyV = chrono::duration_cast<chrono::microseconds>(end - start).count();

        start = chrono::high_resolution_clock::now();
        Solucion solIterativo = iterativo(A, S);
        end = chrono::high_resolution_clock::now();
        auto durationIterativo = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "Longitud de la cadena: " << longitud << endl;
        cout << "Resultado DyV: " << solDyV.n_subcadenas << " subcadenas" << " (" << durationDyV << " μs)" << endl;
        cout << "Resultado Iterativo: " << solIterativo.n_subcadenas << " subcadenas" << " (" << durationIterativo << " μs)" << endl;
        assert(solDyV.n_subcadenas == solIterativo.n_subcadenas);
        assert(solDyV.posiciones == solIterativo.posiciones);
        cout << "----------------------------------------" << endl;
    }
}