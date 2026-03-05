#include "common.hpp"

/*
 * ENTRADA:
 *   A: Cadena de caracteres (pre: que su longitud sea 3)
 *   inicio: Índice de inicio de la subcadena a analizar
 *   S: Conjunto de caracteres que se pueden usar para formar subcadenas
 * SALIDA:
 *   Un booleano que indica si la subcadena de A es válida (3 caracteres distintos y pertenecientes a S)
 */
bool esValida(string A, int inicio, set<char> S)
{
	char c1 = A[inicio];
	char c2 = A[inicio + 1];
	char c3 = A[inicio + 2];

	// Verificar que los caracteres sean distintos
	if (c1 == c2 || c1 == c3 || c2 == c3)
		return false;

	// Verificar que los caracteres estén en el conjunto S
	if (S.find(c1) == S.end() || S.find(c2) == S.end() || S.find(c3) == S.end())
		return false;

	return true;
}

string imprimirConjunto(const set<char>& S) {
    string resultado = "{ ";
    bool primero = true;
    for (char c : S) {
        if (!primero) resultado += ", ";
        resultado += c;
        primero = false;
    }
    resultado += " }";
    return resultado;
}

string imprimirPosiciones(const set<int>& posiciones) {
    string resultado = "{ ";
    bool primero = true;
    for (int pos : posiciones) {
        if (!primero) resultado += ", ";
        resultado += to_string(pos);
        primero = false;
    }
    resultado += " }";
    return resultado;
}
