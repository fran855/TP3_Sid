#include "parser_escritores.h"

using namespace std;

// Constructor
Parser_escritores::Parser_escritores(Lista<Escritor> * lista, char ** argv){
    entrada = argv[1];
    lista_escritores = lista;
}

// Generar escritor anonimo
void Parser_escritores::generar_anonimo(){
    id = 0;
    nombre_apellido = "ANONIMO";
    nacionalidad = "¿?";
    anio_nacimiento = -1;
    anio_fallecimiento = -1;
}

// Procesar datos a partir de un archivo pasado por linea de comandos
void Parser_escritores::procesar_datos(){
    ifstream archivo(entrada);
	
    string auxiliar;
    int i = 1;

    while(!archivo.eof()){
        getline(archivo, auxiliar);
      	auxiliar.replace(0, 1, " ");
		id = stoi(auxiliar);
		getline(archivo, nombre_apellido);
		getline(archivo, nacionalidad);

		getline(archivo, auxiliar);
        if(auxiliar.empty()){
            anio_nacimiento = -1;
            anio_fallecimiento = -1;
        } else{
            anio_nacimiento = stoi(auxiliar);
            getline(archivo, auxiliar);
            if(auxiliar.empty()){
                anio_fallecimiento = -1;
            } else{
                anio_fallecimiento = stoi(auxiliar);
		        getline(archivo, auxiliar); //Apunta al nuevo escritor (o lee el EOF)     
            }
        }

	    Escritor* nuevo_escritor = new Escritor(id, nombre_apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);    
        lista_escritores -> alta(nuevo_escritor, i++);
    }

    return;
}

// Destructor
Parser_escritores::~Parser_escritores(){}