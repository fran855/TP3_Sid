#ifndef NODO_TEMPLATE_INCLUDED
#define NODO_TEMPLATE_INCLUDED

#include <iostream>
using namespace std;
template <class Tipo>

class Nodo{
	// Atributos
private:
	Tipo* dato;
	Nodo* siguiente;             

	// Metodos
public:
	// Constructor
	// PRE: -
	// POS: construye un nodo con d como dato y siguiente en nullptr
	Nodo(Tipo* d);

	// Cambiar siguiente
	// PRE: n es un puntero válido
	// POS: cambia el puntero siguiente por n
	void cambiar_siguiente(Nodo<Tipo>* n);
	
	// Obtener dato
	// PRE: -
	// POS: devuelve el dato del nodo
	Tipo* obtener_dato();

	// Obtener siguiente
	// PRE: -
	// POS: devuelve el puntero al siguiente nodo
	Nodo<Tipo>* obtener_siguiente();

	// Destructor
	// PRE: -
	// POS: destruye el nodo
	~Nodo<Tipo>();

};

// Constructor
template <class Tipo>
Nodo<Tipo>::Nodo(Tipo* d){
    dato = d;
    siguiente = nullptr;
}

// Cambiar siguiente
template <class Tipo>
void Nodo<Tipo>::cambiar_siguiente(Nodo<Tipo>* n){
	siguiente = n;
}

// Obtener dato
template <class Tipo>
Tipo* Nodo<Tipo>::obtener_dato(){
	return dato;
}

// Obtener siguiente nodo
template <class Tipo>
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente(){
	return siguiente;
}

// Destructor
template <class Tipo>
Nodo<Tipo>::~Nodo<Tipo>(){
}


#endif