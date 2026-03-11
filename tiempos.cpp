#include "dyv.hpp"
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const set<char> S = {'a', 'b', 'c', 'd', 'e'};

string generarMejorCaso(int longitud) {

    string cadena;

    for (int i = 0; i < longitud; i++)
    {
        char c = 'a'; // Genera solo el caracter 'a'
        cadena += c;
    }

    return cadena;

}

string generarPeorCaso(int longitud) {

    string cadena;

    for (int i = 0; i < longitud; i++)
    {
        char c = 'a' + (i % 5); // Genera caracteres ciclicos de 'a' a 'e'
        cadena += c;
    }

    return cadena;

}

double medirTiempo(const string& A) {
    auto start = chrono::high_resolution_clock::now();
    Solucion solDyV = DyV(A, 0, A.size() - 1, S);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

double mediana(vector<double> tiempos) {
    sort(tiempos.begin(), tiempos.end());
    int n = tiempos.size();

    if (n % 2 == 0) {
        return (tiempos[n / 2 - 1] + tiempos[n / 2]) / 2.0;
    } else {
        return tiempos[n / 2];
    }
}

int main() {
    vector<int> longitudes;

    for(int i = 0; i < 10; i++) {
        longitudes.push_back(1000*pow(2, i)); // Genera longitudes de 100, 200, 400, ..., 51200
    }

    ofstream csv("resultados.csv");
    csv << "Longitud,Mejor Caso,Peor Caso\n";

    for (int longitud : longitudes) {
        vector<double> tiemposMejorCaso;
        vector<double> tiemposPeorCaso;

        for (int i = 0; i < 10; i++) { // Ejecutar cada caso 10 veces para obtener una mediana
            string mejorCaso = generarMejorCaso(longitud);
            string peorCaso = generarPeorCaso(longitud);

            tiemposMejorCaso.push_back(medirTiempo(mejorCaso));
            tiemposPeorCaso.push_back(medirTiempo(peorCaso));
        }

        double medianaMejor = mediana(tiemposMejorCaso);
        double medianaPeor = mediana(tiemposPeorCaso);

        csv << longitud << "," << medianaMejor << "," << medianaPeor << "\n";
        cout << "Longitud: " << longitud << " - Mejor Caso: " << medianaMejor << " μs, Peor Caso: " << medianaPeor << " μs" << endl;
    }

    csv.close();
    return 0;
}
