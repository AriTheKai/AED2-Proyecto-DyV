#ifndef DYV_HPP
#define DYV_HPP

#include "common.hpp"

Solucion combinar(Solucion izquierda, Solucion derecha);
void verificarCruzadas(Solucion &solucion, string A, int inicio, int final, int mitad, set<char> S);
Solucion DyV(string A, int inicio, int final, set<char> S);

#endif