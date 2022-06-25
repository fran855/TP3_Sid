#ifndef LECTURA_H
#define LECTURA_H

#include <string>
#include "escritor.h"
#include <iostream>
#include "genero.h"

using namespace std;

class Lectura {
    // Atributos
protected:
    string titulo;
    unsigned int minutos;
    unsigned short int anio;
    Escritor* autor;

    // Metodos
public:

    // Constructor con parametros
    // PRE: minutos >= 0, anio >= 0
    // POS: realiza la carga de los datos al objeto Lectura. 
    //      - en caso de ser proveniente de un autor anonimo, autor = nullptr;
    Lectura(string titulo, unsigned int minutos, unsigned short int anio, Escritor* autor);

    // Constructor por defecto  
    Lectura();

    // Destructor
    // PRE: -
    // POS: -
    virtual ~Lectura();

    // Comparar anios
    // PRE:  lectura debe ser un puntero a Lectura valido
    // POS:  devuelve – 1 si la lectura que llama es menor a la que se pasa por parámetro
    //       devuelve 1 si la que llama es mayor a la que se pasa por parámetro
    //       devuelve 0 si son iguales
    int comparar(Lectura* lectura);

    // Comparar minutos de lectura
    // PRE: lectura debe ser un puntero valido
    // POS: devuelve – 1 si la lectura que llama tiene un tiempo de lectura menor a la que se pasa por parámetro
    //      devuelve 1 si la que llama tiene un tiempo de lectura mayor a la que se pasa por parámetro
    //      devuelve 0 si son iguales
    int comparar(Lectura* lectura, char m);

    // Mostrar
    // PRE: - 
    // POS: muestra los atributos en pantalla
    virtual void mostrar() = 0;

    // Mostrar si una obra pertenece a un genero determinado
    // PRE: -
    // POS: muestra los atributos en pantalla si pertenece a un genero determinado
    virtual void mostrar_si_genero(genero_t genero) = 0;
    
    // Obtener titulo
    // PRE: -
    // POS: devuelve un string con el titulo de la Lectura
    string obtener_titulo();

    // Obtener minutos
    // PRE: -
    // POS: devuelve un entero sin signo con los minutos aproximados de lectura
    unsigned int obtener_minutos();

    // Obtener anio
    // PRE: -
    // POS: devuelve un entero corto sin signo con el año de publicacion
    unsigned short int obtener_anio();

    // Obtener autor
    // PRE: -
    // POS: devulve un puntero a un objeto de tipo Escritor
    Escritor* obtener_autor();

};

#endif