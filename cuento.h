#ifndef CUENTO_H
#define CUENTO_H

#include "lectura.h"

class Cuento : public Lectura {
  // Atributos
private: 
  string libro;

  // Metodos
public:
  // Constructor
  // PRE: titulo string no vacío, minutos >= 0, anio > 0, libro string no vacío, autor puntero valido
  // POS: -
  Cuento (string titulo, unsigned int minutos, unsigned short int anio, string libro, Escritor* autor);

  // Mostrar titulo
  // PRE: -
  // POS: Muestra titulo del libro donde esta el cuento
  void mostrar_libro();

  // Obtener titulo
  // PRE: -
  // POS: Devuelve titulo del libro donde esta el cuento
  string obtener_libro();

  // Mostrar
  // PRE: - 
  // POS: muestra los atributos en pantalla
  void mostrar(); 

  // Mostrar si una obra pertenece a un genero determinado
  // PRE: -
  // POS: Muestra si la obra pertenece al genero indicado
  void mostrar_si_genero(genero_t genero){};

  //Destructor
  ~ Cuento();
};

#endif