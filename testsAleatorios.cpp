#include <iostream>
#include "dyv.hpp"
#include "iterativo.hpp"
#include "common.hpp"
#include <vector>
#include <chrono>

using namespace std;

string generarCadena(int longitud)
{
    string cadena;
    string caracteres = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < longitud; i++)
    {
        char c = caracteres[rand() % caracteres.size()];
        cadena += c;
    }

    return cadena;
}

set<char> generarConjunto()
{
    set<char> S;
    string caracteres = "abcdefghijklmnopqrstuvwxyz";
    int n = rand() % 4 + 3; // Entre 3 y 6 caracteres

    for (int i = 0; i < n; i++)
    {
        char c = caracteres[rand() % caracteres.size()];
        S.insert(c);
    }

    return S;
}

int main()
{
    srand(time(0));

    vector<int> longitudes = {5, 10, 20, 50, 100, 1000};

    cout << "TESTS ALEATORIOS" << endl
         << endl;

    for (int longitud : longitudes)
    {
        string A = generarCadena(longitud);
        set<char> S = generarConjunto();

        cout << "Longitud " << longitud << ":" << endl;

        if (longitud <= 50)
        {
            cout << "\t" << "Cadena: \"" << A << "\"" << endl;
        }
        else
        {
            cout << "\t" << "Cadena: \"" << A.substr(0, 47) << "...\" (" << longitud << " caracteres)" << endl;
        }

        cout << "\t" << "Conjunto S: " << imprimirConjunto(S) << endl;

        // Medir tiempo iterativo
        auto inicio_it = chrono::high_resolution_clock::now();
        Solucion solucionIterativo = iterativo(A, S);
        auto fin_it = chrono::high_resolution_clock::now();
        auto duracion_it = chrono::duration_cast<chrono::microseconds>(fin_it - inicio_it).count();

        // Medir tiempo DyV
        auto inicio_dyv = chrono::high_resolution_clock::now();
        Solucion solucionDyV = DyV(A, 0, A.length() - 1, S);
        auto fin_dyv = chrono::high_resolution_clock::now();
        auto duracion_dyv = chrono::duration_cast<chrono::microseconds>(fin_dyv - inicio_dyv).count();

        cout << "\t" << "Resultado iterativo: " << solucionIterativo.n_subcadenas << ", "
             << imprimirPosiciones(solucionIterativo.posiciones) << " (" << duracion_it << " us)" << endl;
        cout << "\t" << "Resultado DyV: " << solucionDyV.n_subcadenas << ", "
             << imprimirPosiciones(solucionDyV.posiciones) << " (" << duracion_dyv << " us)" << endl;
        cout << endl;
    }

    cout << "✓ Tests aleatorios completados" << endl;
    return 0;
}