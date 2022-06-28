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


int Grafo::llave_minima(int* llaves, bool* aem_lecturas)
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
	// aem[0] = -1 porque el 0 no tiene ningun padre
	llaves[0] = 0;
	arbol_expansion_minima[0] = -1;
	
	for (int i = 0; i < lista_lecturas -> obtener_cantidad() - 1; i++)
	{
		// obtengo el indice de la llave minima
		int u = llave_minima(llaves, aem_lecturas);

		aem_lecturas[u] = true;

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
	// lista_lecturas -> mostrar();
	mostrar_orden_aem(arbol_expansion_minima);



	// libero memoria
	delete[] arbol_expansion_minima;
	delete[] llaves;
	delete[] aem_lecturas;
};

int Grafo::tiempo_max_lectura(int** arbol_expansion_minima)
{
	int tiempo_maximo = 0;

	// acumulo los tiempos de siestas entre lecturas
	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		tiempo_maximo += matriz_adyacencia[i][(*arbol_expansion_minima)[i]];
	}

	Nodo<Lectura>* actual = lista_lecturas -> obtener_nodo(1);

	while (actual != nullptr)
	{
		tiempo_maximo += actual -> obtener_dato() -> obtener_minutos();
		actual = actual -> obtener_siguiente();
	}
	
	return tiempo_maximo;
};



void Grafo::imprimir_aem(int* arbol_expansion_minima)
{
	cout << "Camino\tTiempo de siesta" << endl;

	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		cout << arbol_expansion_minima[i] << " - " << i << "\t\t" << matriz_adyacencia[i][arbol_expansion_minima[i]] << endl;
	}

	cout << "El tiempo máximo de lectura es: " << tiempo_max_lectura(&arbol_expansion_minima) << endl;
	cout << "El orden recomendado de lectura es el siguiente:" << endl;
};

void Grafo::arbol_expansion_minima()
{
	prim_aem();
};

// devuelve false si todavia hay lecturas por visitar
//			true si ya fueron todos visitados
bool Grafo::todos_visitados(bool* visitados)
{
	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		if (visitados[i] == false)
			return false;
	}
	return true;	
};


void Grafo::mostrar_orden_aem(int* arbol_expansion_minima)
{
	// arreglo que me guarde el estado de los nodos
	bool* visitados = new bool[lista_lecturas -> obtener_cantidad()];

	// me creo una cola usando stl para guardar las lecturas a las que tengo que
	// chequear la adyacencia
	list<int> cola;

	// inicializo el arreglo
	for (int i = 0; i < lista_lecturas -> obtener_cantidad(); i++)
	{
		visitados[i] = false;
	};

	// empiezo por la priemra lectura de la lista
	visitados[0] = true;
	cout << lista_lecturas -> consulta(1) -> obtener_titulo() << endl;	// imprimo la primera lectura

	cola.push_back(0);	// le enchufo el 0 a la cola

	while (todos_visitados(visitados) != true)
	{
		int actual = cola.front();

		//ciclo que recorre el arbol para ver quien tiene de padre a la lectura /actual/
		for (int indice_arbol = 0; indice_arbol < lista_lecturas -> obtener_cantidad(); indice_arbol++)
		{
			// condicion que chequea si la lectura fue visitada y si tiene de padre a /indice lectura/
			if (arbol_expansion_minima[indice_arbol] == actual && visitados[indice_arbol] == false)
			{
				cola.push_back(indice_arbol);	// encola el adyacente encontrado
				visitados[indice_arbol] = true;	// me marca como visitado al adyacente
				string titulo = lista_lecturas -> consulta(indice_arbol + 1) -> obtener_titulo();
				cout << titulo << endl;
			}
		}

		cola.pop_front();	
	}
	delete[] visitados;
};



Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    lista_lecturas = nullptr;
}
