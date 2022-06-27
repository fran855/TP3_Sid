#include "grafo.h"

Grafo::Grafo(Lista<Lectura>* lista_lectura) {
    matriz_adyacencia = nullptr;
    this->lista_lecturas = lista_lectura;
}



void Grafo::agregar_camino(Lectura* origen, Lectura* destino, int peso) {
    int posicion_origen = lista_lecturas -> obtener_posicion(origen);
    int posicion_destino = lista_lecturas -> obtener_posicion(destino);

    matriz_adyacencia[posicion_origen - 1][posicion_destino - 1] = peso; 
    matriz_adyacencia[posicion_destino - 1][posicion_origen - 1] = peso;
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
  
  if((tipo_lec_1 == 'P' && tipo_lec_2 == 'N') || (tipo_lec_2 == 'P' && tipo_lec_1 == 'N'))
    agregar_camino(Lectura1, Lectura2, POEMA_A_NOVELA);
  
  if((tipo_lec_1 == 'P' && tipo_lec_2 == 'H') || (tipo_lec_2 == 'P' && tipo_lec_1 == 'H'))
    agregar_camino(Lectura1, Lectura2, POEMA_A_NOVELA_HISTORICA);

  if((tipo_lec_1 == 'N' && tipo_lec_2 == 'H') || (tipo_lec_2 == 'N' && tipo_lec_1 == 'H'))
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



void Grafo::mostrar(){
  cout << "Matriz de adyacencia:" << endl;
  for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++) {
    for (int j = 0; j < lista_lecturas -> obtener_cantidad(); j++) {
      cout << matriz_adyacencia[i][j] << '\t';
    }
    cout << endl;
  }
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

  while (actual -> obtener_siguiente() != nullptr){   
    siguiente = actual -> obtener_siguiente();
    
    while(siguiente != nullptr){
     procesar_datos(actual -> obtener_dato(), siguiente -> obtener_dato());
     siguiente = siguiente -> obtener_siguiente();
    }
        
    actual = actual -> obtener_siguiente();
  }
  
}


void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < lista_lecturas -> obtener_cantidad(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}


int Grafo::llave_minima(int llaves[], bool aem_lecturas[])
{
	int minimo = INFINITO;
	int indice_minimo;

	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		// chequeo si el elemento ya esta en el AEM y si la llave
		// es mas pequeña que el minimo, entonces ese el el nuevo minimo
		if (aem_lecturas[i] == false && llaves[i] < minimo)
		{
			minimo = llaves[i];
			indice_minimo = i;
		}
	}
	return indice_minimo;
};



void Grafo::prim_aem()
{
	// arreglo que contiene al arbol de expansion minima (AEM)
	int* arbol_expansion_minima = new int[lista_lecturas -> obtener_cantidad()];

	// valores de pesos que uso para elegir el minimo
	int* llaves = new int[lista_lecturas -> obtener_cantidad()];

	// arreglo para ver si la lectura se encuentra en el AEM
	bool* aem_lecturas = new bool[lista_lecturas -> obtener_cantidad()];

	// inicializamos las llaves en infinito (valor muy grande,
	// teoricamente podria ser mas grande que la siesta mayor)
	// y las lecturas del AEM en false.
	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		llaves[i] = INFINITO;
		aem_lecturas[i] = false;
	}

	// vamos a empezar por la primer lectura, para esto pongo la llave[0]
	// en 0 para que se elija primero. 
	llaves[0] = 0;
	arbol_expansion_minima[0] = -1;
	
	for (int i = 0; i < lista_lecturas -> obtener_cantidad() - 1; i++)
	{
		// obtengo el indice de la llave minima
		int u = llave_minima(llaves, aem_lecturas);

		aem_lecturas[i] = true;

		// ahora tengo que actualizar las llaves de las lecturas adyacentes
		// al minimo encontrado, solo considerando los vertices que no estan
		// en el AEM
		for (int v = 0; v < lista_lecturas -> obtener_cantidad(); v++)
		{	
			// chequeo:
			//	- no sea de la diagonal (-1)
			//	- que no pertenezca al AEM
			//	- que el peso del camino sea menor a la llave ubicada previamente
			if (matriz_adyacencia[u][v] != -1 && aem_lecturas[v] == false && matriz_adyacencia[u][v] < llaves[v])
			{
				arbol_expansion_minima[v] = u;
				llaves[v] = matriz_adyacencia[u][v];
			}
		}
	}
	imprimir_aem(arbol_expansion_minima);
};


void Grafo::imprimir_aem(int* arbol_expansion_minima)
{
	cout << "Camino \tTiempo de siesta" << endl;

	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		cout << arbol_expansion_minima[i] << "-\t" << i << matriz_adyacencia[i][arbol_expansion_minima[i]] << endl;
	}
	
};

void Grafo::arbol_expansion_minima()
{
	prim_aem();
};




Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    lista_lecturas = nullptr;
}
