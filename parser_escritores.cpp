#include "parser_escritores.h"

using namespace std;

// Constructor
Parser_escritores::Parser_escritores(Hashing * tabla, char ** argv){
    entrada = argv[1];
    this -> tabla = tabla;
}

// Generar escritor anonimo
void Parser_escritores::generar_anonimo(){
    isni = 0;
    nombre_apellido = "ANONIMO";
    nacionalidad = "¿?";
    anio_nacimiento = -1;
    anio_fallecimiento = -1;
}

// Procesar datos a partir de un archivo pasado por linea de comandos
void Parser_escritores::procesar_datos(){
    ifstream archivo(entrada);
	
    string auxiliar;

    while(!archivo.eof()){
        getline(archivo, auxiliar);
      	auxiliar.replace(0, 1, " ");
		isni = stoi(auxiliar);
		getline(archivo, nombre_apellido);
		getline(archivo, nacionalidad);

		getline(archivo, auxiliar);
        if(auxiliar.empty()){
            anio_nacimiento = -1;
            anio_fallecimiento = -1;
        } else{
            anio_nacimiento = (short int)stoi(auxiliar);
            getline(archivo, auxiliar);
            if(auxiliar.empty()){
                anio_fallecimiento = -1;
            } else{
                anio_fallecimiento = (short int)stoi(auxiliar);
		        getline(archivo, auxiliar); //Apunta al nuevo escritor (o lee el EOF)     
            }
        }

	    Escritor* nuevo_escritor = new Escritor(isni, nombre_apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);    
        tabla -> alta(nuevo_escritor);
    }

    return;
}

// Destructor
Parser_escritores::~Parser_escritores(){}