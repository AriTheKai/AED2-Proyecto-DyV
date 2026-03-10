#ifndef DYV_HPP
#define DYV_HPP

#include "common.hpp"

Solucion combinar(Solucion izquierda, Solucion derecha);
void verificarCruzadas(Solucion &solucion, const string& A, int inicio, int final, int mitad, const set<char>& S);
Solucion DyV(const string& A, int inicio, int final, const set<char>& S);

#endif