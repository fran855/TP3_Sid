#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include "lista.h"
#include "caminos.h"

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
  int ** matriz_adyacencia;
  Lista<Lectura> * lista_lecturas;


/*MÉTODOS*/

  
  //post libera la memoria de la matriz de adyacencia
  void liberar_matriz_adyacencia();

  //pre: el peso es mayor o igual 0, origen y destino punteros existentes en lista lecturas
  //post: Ajusta la matriz de adyacencia con el peso ingresado
  void agregar_camino(Lectura* origen, Lectura* destino, int peso);
  
  //pre: lecturas dentro de la lista de lecturas
  //pos: genera camino entre las dos lecturas
  void procesar_datos(Lectura* origen, Lectura* destino);

public:
  //Constructor
  Grafo(Lista<Lectura>* lista_lectura);

  //Mostrar
  //PRE: lista_lecturas no vacía
  //POS: Muestra el grafo
  void mostrar();

  // pre: lista_lecturas != null
  // pos: genera el grafo a partir de la lista
  void generar_grafo();

  //Destructor
  ~Grafo();
};

#endif