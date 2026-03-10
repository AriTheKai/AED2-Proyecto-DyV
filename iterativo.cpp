#include "iterativo.hpp"

Solucion iterativo(const string& A, const set<char>& S)
{
    int n = A.length();
    Solucion solucion = {0, set<int>()};

    // CASO BASE: Si la longitud de la cadena es menor que 3, no se pueden formar subcadenas válidas
    if (n < 3)
        return solucion;

    // RECORRIDO: Verificar todas las subcadenas de longitud 3
    for (int i = 0; i <= n - 3; i++)
    {
        if (esValida(A, i, S))
        {
            solucion.n_subcadenas++;
            solucion.posiciones.insert(i);
        }
    }

    return solucion;
}