#ifndef CAMINO_H
#define CAMINO_H

#include "lista.h"
#include "lectura.h"
#include <cmath>

class Camino{
private:
    Lectura* origen;
    Lectura* destino;
    int peso;
    bool transitado;

public:
    Camino(Lectura* origen, Lectura* destino, int peso);
    ~Camino();
    Lectura* obtener_origen();
    Lectura* obtener_destino();
    int comparar(Camino* camino);
    int obtener_peso();
    bool fue_transitado();
    Lista <Camino>* Lista_minima(Lista <Camino>* lista_completa);
    void imprimir_orden_minimo(Lista <Camino>* lista_minima);
};












#endif