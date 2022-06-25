#include "grafos.h"

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
}




void Grafo::agregar_vertice(string nuevo_vertice) {
    agrandar_matriz_adyacencia();
    vertices -> agregar(nuevo_vertice);
}



// A MODIFICAR
void Grafo::agregar_camino(string origen, string destino, int peso) {
    int posicion_origen = vertices ->obtener_posicion(origen);
    int posicion_destino = vertices ->obtener_posicion(destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA)) {
        matriz_adyacencia[posicion_origen][posicion_destino] = peso;
        matriz_adyacencia[posicion_destino][posicion_origen] = peso;
    }
}


void Grafo::unir(Nodo<Lectura>* Lectura1, Nodo<Lectura>* Lectura1){
  char tipo_lec_1 = Lectura1 -> obtener_dato() -> obtener_tipo_lectura();
  char tipo_lec_2 = Lectura2 -> obtener_dato() -> obtener_tipo_lectura();

  if((tipo_lec_1 == 'C' && tipo_lec_2 == 'N') || (tipo_lec_1 == 'C' && tipo_lec_2 == 'N')){
    

    
  }
  

  
}




void Grafo::agrandar_matriz_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_vertices = vertices->obtenerCantidadDeElementos() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_vertices];
    for(int i = 0; i < nueva_cantidad_vertices; i++){
        matriz_auxiliar[i] = new int[nueva_cantidad_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matriz_auxiliar;
}


void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        nueva_adyacente[vertices -> obtener_cantidad_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad_elementos()][vertices -> obtenerCantidadDeElementos()] = 0;
}



void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}


void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}