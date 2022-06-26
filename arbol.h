#include "nodo_arbol.h"
#include "lectura.h"

#ifndef ARBOL_H
#define ARBOL_H

template <class Tipo>
class Arbol{

private:
// Atributos
    Nodo_arbol<Tipo>* raiz;

// Métodos
    Nodo_arbol<Tipo>* insertar(Nodo_arbol<Tipo>* nodo, Tipo* lectura);

    void imprimir_en_orden();

    Nodo_arbol<Tipo>* encontrar_extremo();


public:
// Metodos
    // Constructor
    Arbol();

    // Inserta la lectura en el arbol
    void insertar(Tipo* lectura);

    // Imprime en orden el arbol de un extremo al otro
    void imprimir_en_orden();

    // Devuelve el puntero a la raiz
    Nodo_arbol<Tipo>* obtener_raiz();

    // Encuentra el extremo
    Nodo_arbol<Tipo>* encontrar_extremo();

};

// Constructor
template <class Tipo>
Arbol<Tipo>::Arbol(){
    this -> raiz = nullptr;
}

// Privador
template <class Tipo>
Nodo_arbol<Tipo>* Arbol<Tipo>::insertar(Nodo_arbol<Tipo>* nodo, Tipo* lectura){
    
    // condicion de corte
    if (nodo == NULL) {
        nodo = new Nodo_arbol<Tipo>(lectura);
    }

   /*  else if (lectura > node->get_data()) {
        node->set_right(insert(node->get_right(), data), node);
    }

    else {
        node->set_left(insert(node->get_left(), data), node);
    } */

    if ()

    return nodo;
};


// Publico
template <class Tipo>
void Arbol<Tipo>::insertar(Tipo* lectura){
    this -> raiz = insertar();
};

// busqueda recursiva
template <class Tipo>
Nodo_arbol<Tipo>* Nodo_arbol<Tipo>::busqueda(Nodo_arbol<Tipo>* nodo, Tipo* lectura)
{
    // caso de corte
    if (nodo == nullptr || nodo -> obtener_lectura() == lectura)
        return nodo;

    return busqueda(nodo -> obtener_izquierdo(), lectura);
}



#endif