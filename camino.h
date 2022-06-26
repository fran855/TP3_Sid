#ifndef CAMINO_H
#define CAMINO_H

#include "lista.h"
#include "lectura.h"

class Camino{
private:
    Lectura* origen;
    Lectura* destino;
    int peso;

public:
    Camino(Lectura* origen, Lectura* destino, int peso);
    ~Camino();
    Lectura* obtener_origen();
    Lectura* obtener_destino();
    int comparar(Camino* camino);
    int obtener_peso();
};












#endif