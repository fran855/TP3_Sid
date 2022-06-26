#include "hashing.h"
#include "nodo.h"

Hashing::Hashing(){
    this->n = N;
    tabla = new Lista<Escritor> *[n];
    for (int i = 0; i < n; i++){
        tabla[i] = new Lista<Escritor>();
    }
    ocupados = new int[n];
    for(int i = 0; i < n; i++){
        ocupados[i] = -1;
    }
    n_ocupados = 0;
}

Hashing::~Hashing(){
    for (int pos = 0; pos < n; pos++){
        delete tabla[pos];
    }
    delete[] tabla;
    delete[] ocupados;
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
    int j;
    for(j = 0; j < n_ocupados && ocupados[j] != pos; j++){
    }
    if(j == n_ocupados){
        ocupados[n_ocupados] = pos;
        n_ocupados++;
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

Escritor* Hashing::consulta(string nombre_apellido){
    Escritor* escritor = nullptr;
    for(int i = 0; i < n_ocupados; i++){

        Nodo<Escritor> *actual = tabla[ocupados[i]]->obtener_nodo(1);
        while (actual != nullptr){
            if (actual->obtener_dato()->obtener_nombre_apellido() == nombre_apellido){
                escritor = actual->obtener_dato();
            }
            actual = actual->obtener_siguiente();
        }
    }

    return escritor;
}

void Hashing::baja(int isni){
    int pos = isni % n;
    Nodo<Escritor> *actual = tabla[pos]->obtener_nodo(1);
    int i = 1;
    while (actual != nullptr){
        if (actual->obtener_dato()->obtener_isni() == isni){
            tabla[pos]->baja(i);
        }
        actual = actual->obtener_siguiente();
        i++;
    }
}

void Hashing::mostrar(){
    for(int i = 0; i < n_ocupados; i++){

        Nodo<Escritor> *actual = tabla[ocupados[i]]->obtener_nodo(1);
        while (actual != nullptr){
            actual -> obtener_dato() -> mostrar();
            actual = actual -> obtener_siguiente();
            cout << endl;
        }
    }
}