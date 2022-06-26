#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

template <class Tipo>
class Nodo_arbol{

// Atributos
private:
    Tipo* lectura;
    Nodo_arbol<Tipo>* padre;
    Nodo_arbol<Tipo>* izquierdo; // Hijo izquierdo
    Nodo_arbol<Tipo>* derecho;   // Hijo derecho

// Metodos
public:
    // Constructor
    Nodo_arbol(Tipo* lectura);

    // Devuelve el puntero a la lectura
    Tipo* obtener_lectura();

    // Dado un puntero a un nodo, lo ubica como hijo izquierdo del nodo.
    void setear_izquierdo(Nodo_arbol<Tipo>* izquierdo);

    // Dado un puntero a un nodo, lo ubica como hijo derecho del nodo.
    void setear_derecho(Nodo_arbol<Tipo>* derecho);

    // Devuelve el puntero al nodo hijo izquierdo
    Nodo_arbol<Tipo>* obtener_izquierdo();

    // Devuelve el puntero al nodo hijo derecho
    Nodo_arbol<Tipo>* obtener_derecho();

    // Devuelve el puntero al nodo padre
    Nodo_arbol<Tipo>* obtener_padre();

    // Busca si se encuentra una lectura en el arbol y devuelve el puntero a ella
    Nodo_arbol<Tipo>* busqueda(Nodo_arbol<Tipo>* nodo, Tipo* lectura);


    // Destructor
    ~Nodo_arbol();
}; 

// Constructor
template <class Tipo>
Nodo_arbol<Tipo>::Nodo_arbol(Tipo* lectura){
    this -> lectura = lectura;
    this -> padre = nullptr;
    this -> izquierdo = nullptr;
    this -> derecho = nullptr;
}

// Obtener lectura
template <class Tipo>
Tipo* Nodo_arbol<Tipo>::obtener_lectura(){
    return lectura;
}

// Setear hijo izquierdo
template <class Tipo>
void Nodo_arbol<Tipo>::setear_izquierdo(Nodo_arbol<Tipo>* izquierdo){
    this -> izquierdo = izquierdo;
}

// Setear hijo derecho
template <class Tipo>
void Nodo_arbol<Tipo>::setear_derecho(Nodo_arbol<Tipo>* derecho){
    this -> derecho = derecho;
}

// Obtener hijo izquierdo
template <class Tipo>
Nodo_arbol<Tipo>* Nodo_arbol<Tipo>::obtener_izquierdo(){
    return izquierdo;
}

// Obtener hijo derecho
template <class Tipo>
Nodo_arbol<Tipo>* Nodo_arbol<Tipo>::obtener_derecho(){
    return derecho;
}

// Obtener padre
template <class Tipo>
Nodo_arbol<Tipo>* Nodo_arbol<Tipo>::obtener_padre(){
    return padre;
}



#endif