#include "camino.h"

Camino::Camino(Lectura* origen, Lectura* destino, int peso){
    this -> origen = origen;
    this -> destino = destino;
    this -> peso = peso;
}

Camino::~Camino(){
}

Lectura* Camino::obtener_origen(){
    return this -> origen;
}

Lectura* Camino::obtener_destino(){
    return this -> destino;
}

int Camino::comparar(Camino* camino){
    int resultado;
    if (this -> peso < camino -> obtener_peso())
        resultado = -1;
    else if (this -> peso == camino -> obtener_peso())
        resultado = 0;
    else
        resultado = 1;
    return resultado;
};

int Camino::obtener_peso(){
    return this -> peso;
}