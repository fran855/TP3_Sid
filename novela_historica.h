#ifndef NOVELA_HISTORICA_H
#define NOVELA_HISTORICA_H

#include <iostream>
#include <string>
#include "novela.h"

using namespace std;

class Novela_historica : public Novela{
  // Atributos
private:
  char* tema;

  // Metodos
public: 
  // Constructor
  // PRE: titulo string no vacío, minutos >= 0, anio > 0, tema puntero valido, autor puntero valido
  // POS: -
  Novela_historica(string titulo, unsigned int minutos, unsigned short int anio, char* tema, Escritor* autor);

  // Mostrar tema
  // PRE: -
  // POS: Muestra el tema de la novela
  void mostrar_tema();

  // Obtener tema
  // PRE: -
  // POS: Obtiene el tema de la novela historica
  char* obtener_tema();

  // Mostrar
  // PRE: -
  // POS: Muestra los datos de la novela historica
  void mostrar();

  // Destructor
  // PRE: -
  // POS: -
  ~Novela_historica();
};

#endif