#include "novela.h"
using namespace std;

//Constructor
Novela :: Novela(string titulo, unsigned int minutos, unsigned short int anio, genero_t genero, Escritor* autor) : Lectura(titulo, minutos, anio, autor) {
   this->genero = genero;
}

// Mostrar datos de la novela
void Novela::mostrar(){ 
    cout << "Titulo: " << titulo << endl;
    cout << "Minutos aproximados: " << minutos << endl;
    cout << "Año: " << anio << endl;
    cout << "Genero: " << genero_to_string(genero) << endl;
    if(!autor){
      cout << "Autor: ANONIMO" << endl;
    }else{
      cout << "Autor: " << autor -> obtener_nombre_apellido() << endl;
    }
}

//Mostrar genero
void Novela :: mostrar_genero(){
  cout << "Genero: " << genero_to_string(genero) << endl;
}

// Mostrar si una obra pertenece a un genero determinado
void Novela::mostrar_si_genero(genero_t genero){
  if(this->genero == genero){
    mostrar();
  }
}

//Obtener genero
genero_t Novela :: obtener_genero(){
  return genero;
}

//Destructor
Novela :: ~Novela(){}