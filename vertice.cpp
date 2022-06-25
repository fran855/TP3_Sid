#include "vertice.h"

Vertice::Vertice(Lectura * lectura) {
    this -> lectura = lectura;
}

Lectura* Vertice::obtener_lectura() {
    return lectura;
}

Vertice::~Vertice() {

}