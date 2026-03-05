#include <iostream>
#include "dyv.hpp"
#include "iterativo.hpp"
#include <vector>

using namespace std;

string generarCadena(int longitud) {
    string cadena;
    string caracteres = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < longitud; i++) {
        char c = caracteres[rand() % caracteres.size()];
        cadena += c;
    }

    return cadena;
}

set<char> generarConjunto() {
    set<char> S;
    string caracteres = "abcdefghijklmnopqrstuvwxyz";
    int n = rand() % 4 + 3; // Entre 3 y 6 caracteres

    for (int i = 0; i < n; i++) {
        char c = caracteres[rand() % caracteres.size()];
        S.insert(c);
    }

    return S;
}

int main() {
    srand(time(0)); // Semilla fija para resultados reproducibles

    vector<int> longitudes = {5, 10, 20, 50, 100, 1000};

    for (int longitud : longitudes) {
        string A = generarCadena(longitud);
        set<char> S = generarConjunto();

        cout << "\n===============================================" << endl;
        cout << "TEST - Longitud de la cadena: " << longitud << endl;
        cout << "===============================================" << endl;
        
        // Solo mostrar cadenas cortas completas
        if (longitud <= 50) {
            cout << "Cadena: " << A << endl;
        } else {
            cout << "Cadena: " << A.substr(0, 50) << "... (" << longitud << " caracteres)" << endl;
        }
        
        cout << "Conjunto S: " << imprimirConjunto(S) << endl;
        cout << endl;

        Solucion solucionIterativo = iterativo(A, S);
        cout << "ITERATIVO:" << endl;
        cout << "  Subcadenas válidas: " << solucionIterativo.n_subcadenas << endl;
        cout << "  Posiciones: " << imprimirPosiciones(solucionIterativo.posiciones) << endl;
        cout << endl;

        Solucion solucionDyV = DyV(A, 0, A.length() - 1, S);
        cout << "DIVIDE Y VENCERÁS:" << endl;
        cout << "  Subcadenas válidas: " << solucionDyV.n_subcadenas << endl;
        cout << "  Posiciones: " << imprimirPosiciones(solucionDyV.posiciones) << endl;
    }
    
    cout << "\n===============================================" << endl;
}