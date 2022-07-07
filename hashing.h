#ifndef HASHING_H
#define HASHING_H

#include "lista.h"
#include "escritor.h"

using namespace std;

const int N = 29;

class Hashing{
//ATRIBUTOS
private:
    Lista<Escritor>** tabla;
    int n;
    int* ocupados;
    int n_ocupados;


//MÉTODOS
public:
    // Constructor:
    Hashing();

    //Alta:
    // PRE: Recibe un objeto escritor válida
    // POS: Da de alta un objeto escritor en la tabla de hashing
    void alta(Escritor* escritor);

    // Baja
    // PRE: Recibe un isni válido ya presente en la tabla.
    // POS: Da de baja el escritor asociado a ese código isni
    void baja(int isni);

    // Mostrar
    // PRE: -
    // POS: Muestra la tabla de hashing
	  void mostrar();

        // Consulta
    // PRE: Recibe el código isni de un escritor
    // POS: Devuelve el objeto escritor asociado a ese código ISNI
    Escritor* consulta(int isni);

    // Consulta
    // PRE: Recibe el nombre y apellido de un escritor
    // POS: Devuelve el objeto escritor que tiene ese nombre y apellido
    Escritor* consulta(string nombre_apellido);

    // Destructor
    ~Hashing();
};

#endif