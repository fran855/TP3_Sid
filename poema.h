#ifndef POEMA_H
#define POEMA_H

#include <iostream>
#include <string>
#include "lectura.h"

class Poema: public Lectura {
  // Atributos
protected:
    unsigned int versos;

  // Metodos
public:
  // Constructor
  // PRE: titulo string no vacío, minutos >= 0, anio > 0, versos > 0, autor puntero valido
  // POS: -
  Poema(string titulo, unsigned int minutos, unsigned short int anio, unsigned int versos, Escritor* autor);
  
  // Mostrar
  // PRE: - 
  // POS: muestra los daots del Poema en pantalla
  void mostrar(); 

  // Mostrar si pertenece a un determinado genero
  // Virtual - Se ejecuta solo en la Novela
  void mostrar_si_genero(genero_t genero){};

  // Destructor
  // PRE: -
  // POS: -
  ~Poema();

};
  
#endif