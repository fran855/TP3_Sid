#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
#include "lectura.h"

using namespace std;

template <class Tipo>
class Lista{
private:
	Nodo<Tipo>* primero;
	int cantidad;

public:
	// Constructor
	// PRE: -
	// POS: Construye una Lista vacía
	Lista();

	// Alta por posicion                 [tomamos 1 como el inicio]
	// PRE: elemento es un puntero a Tipo valido, 1 <= pos <= cantidad + 1, cantidad > 0
	// POS: agrega el elemento en la posición pos (se empieza por 1)
	void alta(Tipo* elemento, int pos);

	// Alta ordenada
	// PRE: elemento es un puntero valido
	// POS: inserta de manera ordenada el elemento en la lista
	void alta(Tipo* elemento);

	// Baja
	// PRE: 1 <= pos <= cantidad, cantidad > 0
	// POS: da de baja al elemento que está en pos (se empieza por 1)
	void baja(int pos);
	
	// Consulta
	// PRE: 1 <= pos <= cantidad, cantidad > 0
	// POS: devuelve el elemento que está en pos (se empieza por 1)
	Tipo* consulta(int pos);

	// Consulta
	// PRE: 1 <= pos <= cantidad, cantidad > 0
	// POS: devuelve el elemento que está en pos (se empieza por 1)
	Tipo* consulta(int pos, char m);
	
	// Mostrar
	// PRE: la lista debe ser no vacia
	// POS: muestra por pantalla los elementos de la lista
	void mostrar();

    // Obtener_cantidad
    // PRE: -
    // POS: devuelve la cantidad de elementos de la lista
    int obtener_cantidad();

	// Vacía
	// PRE: -
	// POS: devuelve true si la Lista está vacía, false de lo contrario
	bool vacia();

	// Sobrecarga del operador =
	void operator=(Lista<Tipo> lista2);

	// Encuentra el nodo con el menor tiempo de lectura
	// PRE: minimo_anterior tiene que ser un puntero valido.
	// POS: Devuelve un puntero al nodo del menor elemento cuyo parametro
	// 		de comparacion es mayor o igual al de minimo_anterior, pero no
	// 		es minimo_anterior.
	Nodo<Tipo>* encontrar_minimo(Nodo<Tipo>* minimo_anterior);

	// Destructor
	~Lista();

//private:
	// Obtener nodo
	// PRE: 1 <= pos <= obtener_cantidad()
	// POS: devuelve el puntero al nodo que está en pos (se empieza por 1)
	Nodo<Tipo>* obtener_nodo(int pos);

};

//Constructor
template <class Tipo>
Lista<Tipo>::Lista(){
	primero = 0;
	cantidad = 0;
}

//Obtener_nodo (privada)
template <class Tipo>
Nodo<Tipo>* Lista<Tipo>::obtener_nodo(int pos){
	Nodo<Tipo>* aux = primero;
	int contador = 1;
	
	while(contador < pos){
		aux = aux -> obtener_siguiente();
		contador++;
	}

	return aux;
}

//Alta
template <class Tipo>
void Lista<Tipo>::alta(Tipo* elemento, int pos){
	Nodo<Tipo>* nuevo = new Nodo<Tipo>(elemento);
	if(pos == 1){
		nuevo -> cambiar_siguiente(primero);
		primero = nuevo;
	}
	else{
		Nodo<Tipo>* anterior = obtener_nodo(pos - 1);
		nuevo -> cambiar_siguiente(anterior -> obtener_siguiente());
		anterior -> cambiar_siguiente(nuevo);
	}
	cantidad++;
} 

// Alta ordenada
template <class Tipo>
void Lista<Tipo>::alta(Tipo* elemento){
Nodo<Tipo>* nuevo = new Nodo<Tipo>(elemento);
	bool fue_ubicada = false;

	// Caso donde la lista se encuentra vacia
	if (primero == nullptr){
		primero = nuevo;
		cantidad++;
		fue_ubicada = true;
	} else if ((nuevo -> obtener_dato()) -> comparar(primero -> obtener_dato()) == -1 && fue_ubicada == false) {	//caso donde es menor que el primero
		nuevo -> cambiar_siguiente(primero);
		primero = nuevo;
		cantidad++;
		fue_ubicada = true;
	} else if (fue_ubicada == false) {
		// Localizando el nodo antes de la insersion
		Nodo<Tipo>* actual = primero;
		while (actual -> obtener_siguiente() != nullptr && (nuevo -> obtener_dato()) -> comparar(actual -> obtener_siguiente() -> obtener_dato()) == 1 && fue_ubicada == false) {
			actual = actual -> obtener_siguiente();
		};
		// Insersion el nodo en la lista
		if (fue_ubicada == false){
			nuevo -> cambiar_siguiente(actual -> obtener_siguiente());
			actual -> cambiar_siguiente(nuevo);
			cantidad++;
			fue_ubicada = true;
		}
	}
}

//Baja
template <class Tipo>
void Lista<Tipo>::baja(int pos){
	Nodo<Tipo>* borrar = primero;
	if(pos == 1){
		primero = primero -> obtener_siguiente();
	} else{
		Nodo<Tipo>* anterior = obtener_nodo(pos - 1);
		borrar = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(borrar -> obtener_siguiente());
	}
	cantidad--;
	delete borrar -> obtener_dato();	
	delete borrar;
}

//Consulta
template <class Tipo>
Tipo* Lista<Tipo>::consulta(int pos){
	Nodo<Tipo>* aux = primero;
	int contador = 1;
	while(contador < pos){
			aux = aux -> obtener_siguiente();
			contador++;
	}
	return aux -> obtener_dato();
}

//Consulta
template <class Tipo>
Tipo* Lista<Tipo>::consulta(int pos, char m){
	Nodo<Tipo>* aux = primero;
	int contador = 1;
	while(contador < pos){
			aux = aux -> obtener_siguiente();
			contador++;
	}
	return &(aux -> obtener_dato());
}

// Vacia
template <class Tipo>
bool Lista<Tipo>::vacia(){
	return (cantidad == 0);
}

// Obtener_cantidad
template <class Tipo>
int Lista<Tipo>::obtener_cantidad(){
	return cantidad;
}

// Mostrar
template <class Tipo>
void Lista<Tipo>::mostrar(){
	Nodo<Tipo>* aux = primero;
	while(aux -> obtener_siguiente() != 0){
		aux -> obtener_dato() -> mostrar();
		aux = aux -> obtener_siguiente();
		cout << endl;
	}

	aux -> obtener_dato() -> mostrar();
	aux = aux -> obtener_siguiente();

}

//Destructor
template <class Tipo>
Lista<Tipo>::~Lista<Tipo>(){
	while(! vacia())
		baja(1);
}

template <class Tipo>
void Lista<Tipo>::operator=(Lista<Tipo> lista2){
	this -> primero = lista2.primero;
	this -> cantidad = cantidad;
};

template <class Tipo>
Nodo<Tipo>* Lista<Tipo>::encontrar_minimo(Nodo<Tipo>* minimo_anterior){
	Nodo<Tipo>* minimo = nullptr;

	// Caso con el primer minimo / Voy a tener minimo_anterior = nullptr y minutos anterior != 0
	if (minimo_anterior == nullptr) {
		Nodo<Tipo>* cursor = primero;
		Nodo<Tipo>* minimo_auxiliar = primero;

		while (cursor != nullptr) {
			int comparacion = (cursor -> obtener_dato()) -> comparar(minimo_auxiliar -> obtener_dato(), 'm');

			if (comparacion == -1) 
				minimo_auxiliar = cursor;
			
			// Avanza al siguiente nodo
			cursor = cursor -> obtener_siguiente();
		}
		minimo = minimo_auxiliar;
	} else { // Caso donde ya se encontro un minimo previamente / minimo_anterior != nullptr y minutos_anterior != 0
		Nodo<Tipo>* cursor = primero;
		Nodo<Tipo>* minimo_auxiliar = nullptr;

		// Tengo que recorrer la lista hasta que un nodo tenga minutos >= a minutos_anterior y sea != minimo anterior
		while (cursor != nullptr) {
			int comparacion = (cursor -> obtener_dato()) -> comparar(minimo_anterior -> obtener_dato(), 'm');
			
			// Caso donde el apuntado por el cursor es >= a los minutos del minimo anterior Y no es el minimo anterior
			if ((comparacion == 0 || comparacion == 1) && cursor != minimo_anterior && minimo_auxiliar == nullptr){
				minimo_auxiliar = cursor;
			} 
			else if((comparacion == 0 || comparacion == 1) && cursor != minimo_anterior && minimo_auxiliar != nullptr && (cursor -> obtener_dato() -> comparar(minimo_auxiliar -> obtener_dato(), 'm') == -1)) {
				minimo_auxiliar = cursor;
			}
			// Avanza al siguiente nodo
			cursor = cursor -> obtener_siguiente();
		} 
		minimo = minimo_auxiliar;
	}
	return minimo;
}

#endif