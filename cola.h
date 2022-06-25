#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "lectura.h"
#include "nodo.h"
#include "lista.h"

using namespace std;

template <class Tipo> 
class Cola {
  // Atributos
private:
  Nodo<Tipo>* primero;
  Nodo<Tipo>* ultimo;

  // Metodos
public:
  // Constructor
  // PRE: -
  // POS: Construye una Cola vacía
  Cola();

  // Alta
  // PRE: elemento es un puntero valido
  // POS: agrega el elemento al final de la Cola
  void alta(Tipo* elemento);

  // Baja
  // PRE: la Cola no puede estar vacía
  // POS: quita el elemento del principio de la Cola.
  void baja();

  // Consulta
  // PRE: la Cola no puede estar vacía
  // POS: muestra los datos del elemento al principio de la Cola
  void consulta();

  // Vacía
  // PRE: -
  // POS: devuelve true si la Cola está vacía, false de lo contrario
  bool vacia();  

  // Toma una lista y arma una cola ordenada
  // PRE: lista debe ser un puntero valido a una lista
  // POS: -
  void encolar(Lista<Tipo>* lista);

  // Destructor
  ~Cola();
};

// Constructor
template <class Tipo>
Cola<Tipo>::Cola(){
  primero = nullptr;
  ultimo = nullptr;
}

// Alta
template <class Tipo>
void Cola<Tipo>::alta(Tipo* elemento){
	Nodo<Tipo>* nuevo = new Nodo<Tipo>(elemento);
	if (primero)
    ultimo -> cambiar_siguiente(nuevo);
  else 
    primero = nuevo;
  ultimo = nuevo;
}

// Baja
template <class Tipo>
void Cola<Tipo>::baja(){
  Nodo<Tipo>* borrar = primero;
  primero = primero -> obtener_siguiente();
  if (ultimo -> obtener_siguiente()){
    ultimo = ultimo -> obtener_siguiente();
  };
  delete borrar;
  
}

// Consulta
template <class Tipo>
void Cola<Tipo>::consulta(){
  primero -> obtener_dato() -> mostrar();
}

// Vacia
template <class Tipo>
bool Cola<Tipo>::vacia(){
  return primero == nullptr;
}

// Destructor
template <class Tipo>
Cola<Tipo>::~Cola(){
  while(!vacia())
    baja();
}

// Lista a Cola
// Toma una lista y arma una cola ordenada de menor a mayor
template <class Tipo>  
void Cola<Tipo>::encolar(Lista<Tipo>* lista){
  Nodo<Tipo>* minimo = nullptr;
  unsigned int minutos_anterior = 0;

  for (int i = 1; i <= lista -> obtener_cantidad(); i++){
    minimo = lista -> encontrar_minimo(minimo);
    alta(minimo -> obtener_dato());
  }
  
};

#endif