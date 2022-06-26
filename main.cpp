#include "parser_escritores.h"
#include "parser_lecturas.h"
#include <fstream>
#include <iostream>
#include "grafo.h"
#include "escritor.h"
#include "lista.h"
#include "menu.h"
#include "cola.h"
#include "hashing.h"

int main(int argc, char * argv[]){
  Lista<Escritor>* lista_escritores = new Lista<Escritor>;
	Lista<Lectura>* lista_lecturas = new Lista<Lectura>;
  Cola<Lectura>* cola_lecturas = new Cola<Lectura>;
  
  Parser_escritores parser_escritores(lista_escritores, argv);
	parser_escritores.procesar_datos();
  Parser_lectura parser_lecturas(argv);
  parser_lecturas.procesar_datos(lista_escritores, lista_lecturas);
	
  //Menu menu(lista_lecturas, lista_escritores);
  //menu.ejecutar_menu(cola_lecturas);
  
  
  //Grafo grafo(lista_lecturas);
  //grafo.generar_grafo();
  //grafo.mostrar();

  Hashing hashing(lista_escritores);
  hashing.mostrar();

  Menu menu(lista_lecturas, lista_escritores);
  menu.ejecutar_menu(cola_lecturas);

  delete lista_escritores;
  delete lista_lecturas;
  delete cola_lecturas;

  return 0;
}