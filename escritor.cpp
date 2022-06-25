#include "escritor.h"

// Constructor de la clase Escritor
Escritor::Escritor(int id, string nombre_apellido, string nacionalidad, short int anio_nacimiento, short int anio_fallecimiento){
    this -> id = id;
    this -> nombre_apellido = nombre_apellido;
    this -> nacionalidad = nacionalidad;
    this -> anio_nacimiento = anio_nacimiento;
    this -> anio_fallecimiento = anio_fallecimiento;
}

// Mostrar los datos del escritor
void Escritor::mostrar(){
    cout << "ID: " << id << endl;
    cout << "Nombre y apellido: "<< nombre_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Año de nacimiento: " << anio_nacimiento << endl;
    cout << "Año de fallecimiento: " << anio_fallecimiento << endl;
}

// Obtener el ID del escritor
int Escritor::obtener_id(){
    return id;
}

// Obtener el nombre y apellido del escritor
string Escritor::obtener_nombre_apellido(){
    return nombre_apellido;
}

// Obtener la nacionalidad del escritor
string Escritor::obtener_nacionalidad(){
    return nacionalidad;
}

// Obtener el año de nacimiento del escritor
short int Escritor::obtener_anio_nacimiento(){
    return anio_nacimiento;
}

// Obtener el año de fallecimiento del escritor
short int Escritor::obtener_anio_fallecimiento(){
    return anio_fallecimiento;
}

// Cambiar el año de fallecimiento del escritor
void Escritor::cambiar_fallecimiento(short int nuevo_anio){
    anio_fallecimiento = nuevo_anio;
}

// Obtener la dirección del escritor
Escritor* Escritor::obtener_direccion(){
    return this;
}

// Destrcutor de la clase Escritor
Escritor::~Escritor(){
}

// Sobrecarga del operador asignacion
void Escritor::operator=(Escritor escritor2){
	this -> id = escritor2.id;
	this -> nombre_apellido = escritor2.nombre_apellido;
    this -> nacionalidad = escritor2.nacionalidad;
	this -> anio_nacimiento = escritor2.anio_nacimiento;
	this -> anio_fallecimiento = escritor2.anio_fallecimiento;
}