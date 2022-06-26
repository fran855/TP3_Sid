#ifndef PARSER_LECTURAS_H
#define PARSER_LECTURAS_H

#include "lectura.h"
#include "lista.h"
#include "escritor.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"
#include "hashing.h"
#include <fstream>
#include <string>


class Parser_lectura {
    // Atributos
private:
    ifstream archivo_lectura;
    string tipo_lectura;
    string auxiliar;

    //Lectura generico
    
    string titulo;
    unsigned int minutos;
    unsigned short int anio;
    Escritor* autor;

    //Especificos
    char* tema;
    string libro;
    unsigned int versos;
    genero_t genero;

    // Metodos
public:
    //Constructor
    //PRE: argv debe ser un puntero valido
    //POS: -
    Parser_lectura(char** argv);
    
    //Procesar datos
    //PRE: lista_escritores y lista_lecturas deben ser punteros validos
    //POS: -
    void procesar_datos(Hashing* tabla, Lista<Lectura>* lista_lecturas);

    //Destructor
    //PRE: -
    //POS: -
    ~Parser_lectura(){};

private:
    // Obtener autor
    // PRE: lista_escritores debe ser un puntero valido
    // POS: devuelve un puntero a un escritor
    Escritor* obtener_autor(Hashing* tabla);

    // Obtener tema
    // PRE: tema debe ser un string no vacio
    // POS: devuelve un puntero a char donde se encuentra almacenado el tema
    char* obtener_tema(string tema);
};

#endif