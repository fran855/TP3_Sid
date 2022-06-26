#include "hashing.h"
#include "nodo.h"

Hashing::Hashing(){
    this->n = N;
    tabla = new Lista<Escritor> *[n];
    for (int i = 0; i < n; i++){
        tabla[i] = new Lista<Escritor>();
    }
}

/* Hashing::Hashing(Lista<Escritor>* lista_escritores){
    this->n = N;
    tabla = new Lista<Escritor> *[n];
    for (int i = 0; i < n; i++){
        tabla[i] = new Lista<Escritor>();
    }
    for (int i = 1; i <= lista_escritores -> obtener_cantidad(); i++){
        alta(lista_escritores -> consulta(i));
    }
} */

Hashing::~Hashing(){
    for (int pos = 0; pos < n; pos++){
        Nodo<Escritor> *actual = tabla[pos]->obtener_nodo(1);
        int i = 1;
        while (actual != nullptr){
            actual -> cambiar_dato(nullptr);
            tabla[pos]->baja(i);
            actual = actual->obtener_siguiente();
        }
    }
    delete[] tabla;
}

void Hashing::alta(Escritor *escritor){
    int isni = escritor->obtener_isni();
    int pos = isni % n;
    Nodo<Escritor> *actual = tabla[pos]->obtener_nodo(1);

    int i = 1;
    if (tabla[pos]->vacia()){
        tabla[pos]->alta(escritor, i);
    }
    else{
        while (actual->obtener_siguiente() != nullptr){
            actual = actual->obtener_siguiente();
            i++;
        }
        tabla[pos]->alta(escritor, i);
    }
}

Escritor* Hashing::consulta(int isni){
    int pos = isni % n;
    Nodo<Escritor> *actual = tabla[pos]->obtener_nodo(1);
    Escritor* escritor = nullptr;
 
    while (actual != nullptr){
        if (actual->obtener_dato()->obtener_isni() == isni){
            escritor = actual->obtener_dato();
        }
        actual = actual->obtener_siguiente();
    }
 
    return escritor;
}

void Hashing::baja(int isni){
    int pos = isni % n;
    Nodo<Escritor> *actual = tabla[pos]->obtener_nodo(1);
    int i = 1;
    while (actual != nullptr){
        if (actual->obtener_dato()->obtener_isni() == isni){
            actual -> cambiar_dato(nullptr);
            tabla[pos]->baja(i);
        }
        actual = actual->obtener_siguiente();
        i++;
    }
}

void Hashing::mostrar(){
    for (int i = 0; i < n; i++){
        cout << "Posicion " << i << ":" << endl;
        if(tabla[i]->vacia()){
            cout << "Lista vacia" << endl;
        }
        else{
                Nodo<Escritor> *actual = tabla[i]->obtener_nodo(1);
                while (actual != nullptr){
                    cout << "NOMBRE: " << actual->obtener_dato()->obtener_nombre_apellido() << endl;
                    actual = actual->obtener_siguiente();
                }
        }
    }
}