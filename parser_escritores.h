#ifndef PARSER_ESCRITORES_H_INCLUDED
#define PARSER_ESCRITORES_H_INCLUDED

#include <fstream>
#include <string>
#include <iostream>
#include "escritor.h"
#include "lista.h"

using namespace std;

class Parser_escritores{
    // Atributos
private:
    string entrada;
    Lista<Escritor> * lista_escritores;
    int id;
    string nombre_apellido;
    string nacionalidad;
    short int anio_nacimiento;
    short int anio_fallecimiento;

    // Metodos
public:
    // Constructor
    // PRE: lista puntero valido, argv puntero valido
    // POS: -
    Parser_escritores(Lista<Escritor> * lista, char ** argv);
    
    // Destructor
    // PRE: -
    // POS: -
    ~Parser_escritores();

    // Procesar datos
    // PRE: -
    // POS: Genera una lista de escritores a partir de un archivo
    //      pasado por linea de comandos.
    void procesar_datos();

private:
    // Generar escritor anonimo
    // PRE: -
    // POS: asigna valores a los atributos de un escritor anonimo
    void generar_anonimo();

};


#endif