#include "novela_historica.h"

// Constructor
Novela_historica :: Novela_historica(string titulo, unsigned int minutos, unsigned short int anio, char* tema, Escritor* autor): Novela(titulo, minutos, anio, genero, autor){
  this->tema = tema;
  this->genero = HISTORICA;
}

// Obtener tema
char* Novela_historica::obtener_tema(){
  return tema;
}

// Mostrar datos de la novela historica
void Novela_historica::mostrar(){
  cout << "Titulo: " << titulo << endl;
  cout << "Minutos aproximados: " << minutos << endl;
  cout << "Año: " << anio << endl;
  cout << "Genero: " << genero_to_string(genero) << endl;
  cout << "Tema: " << tema << endl;  
  if(!autor){
      cout << "Autor: ANONIMO" << endl;
  }else{
      cout << "Autor: " << autor -> obtener_nombre_apellido() << endl;
  }
}

// Destructor
Novela_historica::~Novela_historica(){
  delete[] tema;
}