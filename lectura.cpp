
#include "lectura.h"

// Constructor con parametros
Lectura::Lectura (string titulo, unsigned int minutos, unsigned short int anio, Escritor* autor) {
    this -> titulo = titulo;
    this -> minutos = minutos;
    this -> anio = anio;
    this -> autor = autor;
}

// Constructor por defecto
Lectura::Lectura () {
    this -> titulo = "¿?";
    this -> minutos = 0;
    this -> anio = 0;
    this -> autor = nullptr;
}

// Destructor
Lectura::~Lectura(){}

// Comaparar anios
int Lectura::comparar(Lectura* lectura){
    int resultado;
    if (this -> anio < lectura -> obtener_anio())
        resultado = -1;
    else if (this -> anio == lectura -> obtener_anio())
        resultado = 0;
    else
        resultado = 1;
    return resultado;
};

// Comparar minutos de lectura
int Lectura::comparar(Lectura* lectura, char m){
    int resultado;
    if (this -> minutos < lectura -> obtener_minutos())
        resultado = -1;
    else if (this -> minutos == lectura -> obtener_minutos())
        resultado = 0;
    else
        resultado = 1;
    return resultado;
};

// Obtener titulo
string Lectura::obtener_titulo() {
    return this -> titulo;
}

// Obtener minutos
unsigned int Lectura::obtener_minutos() {
    return this -> minutos;
}

// Obtener anio
unsigned short int Lectura::obtener_anio() {
    return this-> anio;
}

// Obtener autor 
Escritor* Lectura::obtener_autor() {
    return this -> autor;
}