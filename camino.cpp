#include "camino.h"

Camino::Camino(Lectura* origen, Lectura* destino, int peso){
    this -> origen = origen;
    this -> destino = destino;
    this -> peso = peso;
    this -> transitado = false;
}

Camino::~Camino(){
}

Lectura* Camino::obtener_origen(){
    return this -> origen;
}

Lectura* Camino::obtener_destino(){
    return this -> destino;
}

int Camino::comparar(Camino* camino){
    int resultado;
    if (this -> peso < camino -> obtener_peso())
        resultado = -1;
    else if (this -> peso == camino -> obtener_peso())
        resultado = 0;
    else
        resultado = 1;
    return resultado;
};

int Camino::obtener_peso(){
    return this -> peso;
}

bool Camino::fue_transitado(){
  return this -> transitado;
}

/*
Lista <Camino>* Camino::Lista_minima(Lista <Camino>* lista_completa){
  Lista<Camino>* lista_camino_minimo = new Lista<Camino>[(1+sqrt( 1 + 8 * lista_completa -> obtener_cantidad())/2 - 1)];
  
  lista_camino_minimo -> alta(lista_completa -> obtener_nodo(1) -> obtener_dato());
  Nodo<Camino>* auxiliar = lista_completa -> obtener_nodo(2);
  Camino* agrego;
  
  while(auxiliar != nullptr){
    Lectura* origen = auxiliar -> obtener_dato() -> obtener_origen();
    Lectura* destino = auxiliar -> obtener_dato() -> obtener_destino();
    
    if ()
  
  }
  
}
*/

Lista<Camino>* Camino::Lista_minima(Lista<Camino>* lista_completa){
  Lista<Camino>* lista_minima = new Lista<Camino>();
}


void Camino::imprimir_orden_minimo(Lista <Camino>* lista_minima){
  // Puntero al primer nodo de la lista minima
  Nodo <Camino>* actual = lista_minima -> consulta(1);
  Nodo <Camino>* extremo = nullptr;

  
  
  while (actual != nullptr) {
    
    

    actual = actual -> obtener_siguiente();
  }
  
}