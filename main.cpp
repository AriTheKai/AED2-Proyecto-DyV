#include <iostream>
#include <set>
#include <list>

using namespace std;

struct Solucion
{
	int n_subcadenas;
	set<int> posiciones;
};

// PRECONDICIÓN: A tiene solo 3 caracteres
bool esValida(string A, int inicio, set<int> S)
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

// Combina dos soluciones (izquierda y derecha)
Solucion combinar(Solucion izquierda, Solucion derecha)
{
	Solucion solucion = {0, set<int>()};
	solucion.n_subcadenas = izquierda.n_subcadenas + derecha.n_subcadenas;
	solucion.posiciones = izquierda.posiciones;
	solucion.posiciones.insert(derecha.posiciones.begin(), derecha.posiciones.end());
	return solucion;
}

// Verifica y añade subcadenas que cruzan la mitad
void verificarCruzadas(Solucion &solucion, string A, int inicio, int final, int mitad, set<int> S)
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
Solucion DyV(string A, int inicio, int final, set<int> S)
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

int main()
{
	string A = "amievilarchivist?";
	set<int> S = {'a', 'm', 'i', 'e', 'v', 'l', 'r', 'c', 'h', 's', 't'};
	Solucion resultado = DyV(A, 0, A.size() - 1, S);

	cout << "Número de subcadenas válidas: " << resultado.n_subcadenas << endl;
	cout << "Posiciones de las subcadenas válidas: ";
	for (int pos : resultado.posiciones)
	{
		cout << pos << " ";
	}
	cout << endl;

	return 0;
}