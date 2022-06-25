#include "grafos.h"

Grafo::Grafo(Lista<Lectura>* lista_lectura) {
    matriz_adyacencia = nullptr;
    this->lista_lecturas = lista_lectura;
}



void Grafo::agregar_camino(Lectura* origen, Lectura* destino, int peso) {
    int posicion_origen = lista_lecturas -> obtener_posicion(origen);
    int posicion_destino = lista_lecturas -> obtener_posicion(destino);

    matriz_adyacencia[posicion_origen][posicion_destino] = peso; 
    matriz_adyacencia[posicion_destino][posicion_origen] = peso;
}


void Grafo::procesar_datos(Lectura* Lectura1, Lectura* Lectura2){
  char tipo_lec_1 = Lectura1 -> obtener_tipo();
  char tipo_lec_2 = Lectura2 -> obtener_tipo();

  if((tipo_lec_1 == 'C' && tipo_lec_2 == 'N') || (tipo_lec_2 == 'C' && tipo_lec_1 == 'N'))
    agregar_camino(Lectura1, Lectura2, CUENTO_A_NOVELA);
  
  if((tipo_lec_1 == 'C' && tipo_lec_2 == 'H') || (tipo_lec_2 == 'C' && tipo_lec_1 == 'H'))
    agregar_camino(Lectura1, Lectura2, CUENTO_A_NOVELA_HISTORICA);
  
  if((tipo_lec_1 == 'C' && tipo_lec_2 == 'P') || (tipo_lec_2 == 'C' && tipo_lec_1 == 'P'))
    agregar_camino(Lectura1, Lectura2, CUENTO_A_POEMA);
  
  if((tipo_lec_1 == 'P' && tipo_lec_2 == 'N') || (tipo_lec_2 == 'N' && tipo_lec_1 == 'P'))
    agregar_camino(Lectura1, Lectura2, POEMA_A_NOVELA);
  
  if((tipo_lec_1 == 'P' && tipo_lec_2 == 'H') || (tipo_lec_2 == 'H' && tipo_lec_1 == 'P'))
    agregar_camino(Lectura1, Lectura2, POEMA_A_NOVELA_HISTORICA);

  if((tipo_lec_1 == 'N' && tipo_lec_2 == 'H') || (tipo_lec_2 == 'H' && tipo_lec_1 == 'N'))
    agregar_camino(Lectura1, Lectura2, NOVELA_A_NOVELA_HISTORICA);

  if (tipo_lec_1 == 'C' && tipo_lec_2 == 'C')
    agregar_camino(Lectura1, Lectura2, CUENTO_A_CUENTO);
  
  if (tipo_lec_1 == 'P' && tipo_lec_2 == 'P')
    agregar_camino(Lectura1, Lectura2, POEMA_A_POEMA);
  
  if (tipo_lec_1 == 'N' && tipo_lec_2 == 'N')
    agregar_camino(Lectura1, Lectura2, NOVELA_A_NOVELA);

  if (tipo_lec_1 == 'H' && tipo_lec_2 == 'H')
    agregar_camino(Lectura1, Lectura2, NOVELA_HISTORICA_A_NOVELA_HISTORICA);
}




void Grafo::generar_grafo(){
  Nodo<Lectura>* actual = lista_lecturas -> obtener_nodo(1);
  
  Nodo<Lectura>* siguiente = actual -> obtener_siguiente();
  
  matriz_adyacencia = new int*[lista_lecturas -> obtener_cantidad()];  

  for(int i = 0; i < lista_lecturas -> obtener_cantidad(); i++){
    matriz_adyacencia[i] =  new int[lista_lecturas -> obtener_cantidad()];
    for (int j = 0;  j < lista_lecturas -> obtener_cantidad(); j++ ){
      matriz_adyacencia[i][j] = -1;
    }
  }
  
  while (siguiente != nullptr){   
    procesar_datos(actual -> obtener_dato(), siguiente -> obtener_dato());
    actual = siguiente;
    siguiente = actual -> obtener_siguiente();
  }
  
}




void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < lista_lecturas -> obtener_cantidad(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}


Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    lista_lecturas = nullptr;
}
