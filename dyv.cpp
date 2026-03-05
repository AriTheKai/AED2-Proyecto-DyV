#include "dyv.hpp"

using namespace std;

Solucion combinar(Solucion izquierda, Solucion derecha)
{
	Solucion solucion = {0, set<int>()};
	solucion.n_subcadenas = izquierda.n_subcadenas + derecha.n_subcadenas;
	solucion.posiciones = izquierda.posiciones;
	solucion.posiciones.insert(derecha.posiciones.begin(), derecha.posiciones.end());
	return solucion;
}

/* ENTRADA:
*	solucion: referencia a la solución a actualizar con las subcadenas válidas que crucen la mitad
*	A: Cadena de caracteres
*	inicio: Índice de inicio de la subcadena a analizar
*	final: Índice de final de la subcadena a analizar
*	mitad: Índice de la mitad de la cadena
*	S: Conjunto de caracteres que se pueden usar para formar subcadenas

* FUNCIONAMIENTO:
*	Se verifica si las subcadenas que cruzan la mitad (de longitud 3) son válidas y, en caso afirmativo, se actualiza la solución.
*/
void verificarCruzadas(Solucion &solucion, string A, int inicio, int final, int mitad, set<char> S)
{
	for (int i = mitad - 2; i < mitad; i++)
	{
		if (i >= inicio && i + 2 <= final && esValida(A, i, S))
		{
			solucion.n_subcadenas++;
			solucion.posiciones.insert(i);
		}
	}
}

/*
 * ENTRADA:
 *   A: Cadena de caracteres
 *   inicio: Índice de inicio de la subcadena a analizar
 *   final: Índice de final de la subcadena a analizar
 *   S: Conjunto de caracteres que se pueden usar para formar subcadenas
 * SALIDA:
 *   Una Solucion que contiene las subcadenas que cumplen las condiciones y el número de subcadenas encontradas
 */
Solucion DyV(string A, int inicio, int final, set<char> S)
{

	int n = final - inicio + 1;
	Solucion solucion = {0, set<int>()};

	// CASO BASE: Si la cadena tiene menos de 3 caracteres, no se pueden formar subcadenas válidas
	if (n < 3)
		return solucion;

	// DIVIDIR: Se divide la cadena en dos mitades
	int mitad = inicio + n / 2;
	Solucion solucion_izquierda = DyV(A, inicio, mitad - 1, S);
	Solucion solucion_derecha = DyV(A, mitad, final, S);

	// COMBINAR: Se combinan las soluciones de las dos mitades y se verifica si se pueden formar subcadenas válidas que crucen la mitad
	solucion = combinar(solucion_izquierda, solucion_derecha);

	// Verificar subcadenas que cruzan la mitad
	verificarCruzadas(solucion, A, inicio, final, mitad, S);

	return solucion;
}