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
	Lista<Lectura>* lista_lecturas = new Lista<Lectura>;
  Cola<Lectura>* cola_lecturas = new Cola<Lectura>;
  Hashing* tabla_escritores = new Hashing;
  
  Parser_escritores parser_escritores(tabla_escritores, argv);
	parser_escritores.procesar_datos();
  Parser_lectura parser_lecturas(argv);
  parser_lecturas.procesar_datos(tabla_escritores, lista_lecturas);
  
  
  Grafo grafo(lista_lecturas);
  grafo.generar_grafo();
  grafo.mostrar();
  
  // lista_lecturas -> mostrar();

  grafo.arbol_expansion_minima();


  // tabla_escritores -> mostrar();
/*   Menu menu(lista_lecturas, tabla_escritores);
  menu.ejecutar_menu(cola_lecturas);
 */
  delete tabla_escritores;
  delete lista_lecturas;
  delete cola_lecturas;

  return 0;
}