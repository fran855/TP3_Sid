#include "novela_historica.h"

// Constructor
Novela_historica :: Novela_historica(char tipo, string titulo, unsigned int minutos, unsigned short int anio, char* tema, Escritor* autor): Novela(tipo, titulo, minutos, anio, HISTORICA, autor){
  this->tema = tema;
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


void Novela_historica::mostrar_si_genero(genero_t genero){
    if(genero == HISTORICA){
        this -> mostrar();
      }
}

// Destructor
Novela_historica::~Novela_historica(){
  delete[] tema;
}