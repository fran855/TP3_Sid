#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include "lista.h"
#include "pesos.h"
#include "camino.h"

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

  //PRE: lista_lecturas != null
  //POS: genera el grafo a partir de la lista
  void generar_grafo();

  //PRE: grafo ya cargado
  //POS: devuelve una lista de caminos (ordenados por peso) que se pueden recorrer
  Lista<Camino>* crear_lista_caminos();

  //PRE: lista_caminos != null
  //POS: muestra la lista de caminos
  void mostrar_lista_caminos(Lista<Camino>* lista_caminos);

  //Destructor
  ~Grafo();
};

#endif