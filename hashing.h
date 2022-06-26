#ifndef HASHING_H
#define HASHING_H

#include "lista.h"
#include "escritor.h"

using namespace std;

const int N = 29;

class Hashing{
private:
    Lista<Escritor>** tabla;
    int n;
    int* ocupados;
    int n_ocupados;

public:
    Hashing();
    //Hashing(Lista<Escritor>* lista_escritores);
    ~Hashing();
    void alta(Escritor* escritor);
    Escritor* consulta(int isni);
    Escritor* consulta(string nombre_apellido);
    void baja(int isni);
	void mostrar();
};

#endif