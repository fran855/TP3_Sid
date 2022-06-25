#ifndef GRAFOS_H
#define GRAFOS_H

#include <string>
#include "Lista.h"
#include "Vertice.h"
using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
  int ** matrizDeAdyacencia;
  Lista<Vertice> * vertices;


/*MÉTODOS*/

	//pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

  //post: agranda dinamicamente la matriz de adyacencia
  void agrandarMatrizDeAdyacencia();

    //post libera la memoria de la matriz de adyacencia
  void liberarMatrizAdyacencia();

public:
  //Constructor
  Grafo();

  //pre: No hay vertices repetidos en nombre
  //post: agrega un nuevo vertice al grafo
  void agregarVertice(string nuevoVertice);

  //pre: el peso es un valor positivo
  //post: Ajusta la matriz de adyacencia con el peso ingresado
  void agregarCamino(string origen, string destino, int peso);

  //Destructor
  ~Grafo();
};

#endif