#ifndef GRAFO_H
#define GRAFO_H

#include <list>
#include <string>
#include "lista.h"
#include "caminos.h"
#include "cola.h"
#include "nodo.h"

using namespace std;

const int INFINITO = 999999;

class Grafo {

private:

/*ATRIBUTOS*/

  int ** matriz_adyacencia;
  Lista<Lectura> * lista_lecturas;
  int n_elementos;

/*MÉTODOS*/
  // Liberar matriz de adyacencia
  // PRE: matriz_adyacencia != nullptr
  // POS: libera la memoria de la matriz de adyacencia
  void liberar_matriz_adyacencia();

  // Agregar camino en grafo
  // PRE: el peso es mayor o igual 0, origen y destino punteros existentes en lista lecturas
  // POS: Ajusta la matriz de adyacencia con el peso ingresado
  void agregar_camino(Lectura* origen, Lectura* destino, int peso);

  // Procesar datos
  // PRE: lecturas dentro de la lista de lecturas
  // POS: genera camino entre las dos lecturas
  void procesar_datos(Lectura* origen, Lectura* destino);

  // Llave minima - AEM
  // PRE: llaves y aem_lecturas deben ser arreglos inicializados
  // POS: devuelve la llave minima de una lectura que no se encuentra en el AEM 
  int llave_minima(int* llaves, bool* aem_lecturas);

  // Tiempo maximo de lectura - AEM
  // PRE: arbol_expansion_minima != nullptr
  // POS: devuelve un entero >= 0 con el tiempo maximo
  int tiempo_max_lectura(int** arbol_expansion_minima);

  // Implementacion del algoritmo de Prim - AEM
  // pre: -
  // pos: construye el arbol de expansion minima a partir del grafo
  //      utilizando el algoritmo de Prim y los muestra en pantalla
  void prim_aem();

  // Imprime el tiempo máximo de lectura y el orden - AEM
  // PRE: arbol_expansion_minima debe ser un puntero válido
  // POS: imprime el tiempo máximo de lectura y el orden
  void imprimir_aem(int* arbol_expansion_minima);

  // Mostrar orden - AEM
  // PRE: arbol_expansion_minima debe ser un puntero válido
  // POS: muestra el orden de lectura del AEM
  void mostrar_orden_aem(int* arbol_expansion_minima);

  // Chequea si todos las lecturas fueron visitadas - AEM
  // PRE: visitados debe ser un puntero valido
  // POS: devuelve true si todos los elementos son true
  //      devuelve false de lo contrario
  bool todos_visitados(bool* visitados);

public:
  // Constructor
  Grafo(Lista<Lectura>* lista_lectura);

  // Mostrar
  // PRE: lista_lecturas no vacía
  // POS: Muestra el grafo
  void mostrar();

  // Generador de grafo
  // PRE: lista_lecturas != nullptr
  // POS: genera el grafo a partir de la lista
  void generar_grafo();

  // Arbol de expansion minima
  // PRE: lista_lecturas != nullptr, matriz_adyacencia != nullptr
  // POS: imprime el arbol de expansion minima
  void arbol_expansion_minima();
  
  //Destructor
  ~Grafo();
};

#endif