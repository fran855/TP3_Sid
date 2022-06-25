#ifndef NOVELA_H
#define NOVELA_H

#include <iostream>
#include <string>
#include "lectura.h"
#include "genero.h"

class Novela : public Lectura{
  // Atributos
protected:
  genero_t genero;

  // Metodos
public:
  // Constructor:
  // PRE: titulo string no vacío, minutos >= 0, anio > 0, genero valido, autor puntero valido
  // POS: -
  Novela(string titulo, unsigned int minutos, unsigned short int anio, genero_t genero, Escritor* autor);

  // Mostrar genero
  // PRE: -
  // POS: Muestra a que genero pertenece la novela
  void mostrar_genero();

  // Mostrar titulo
  // PRE: -
  // POS: Devuelve titulo del libro donde esta el cuento
  genero_t obtener_genero();

  // Mostrar si una obra pertenece a un genero determinado
  // PRE: -
  // POS: Muestra si la obra pertenece al genero indicado
  void mostrar_si_genero(genero_t genero);

  // Mostrar
  // PRE: - 
  // POS: muestra los atributos en pantalla
  void mostrar();

  // Destructor:
  // PRE: -
  // POS: -
  ~Novela();

};

#endif