#ifndef VERTICE_H
#define VERTICE_H

#include "lectura.h"

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    Lectura* lectura;

/*MÉTODOS*/
public:
    Vertice(Lectura* lectura);

    //post: obtiene el nombre del vertice
    Lectura* obtener_lectura();

    ~Vertice();
};


#endif //VERTICE_H