#include "menu.h"

using namespace std;

Menu::Menu(Lista<Lectura> *lista_lecturas, Hashing *tabla_escritores)
{
    this->lista_lecturas = lista_lecturas;
    this->tabla_escritores = tabla_escritores;
    this->cola_creada = false;

    srand((unsigned int)time(NULL)); // Inicializar semilla
}

void Menu::ejecutar_menu(Cola<Lectura> *cola_lecturas)
{
    string auxiliar;
    do
    {        
        cout << MSJ_CABECERA_MENU << endl;
        cout << MSJ_OPCION;
        cin >> eleccion;
        cout << endl;
        getline(cin, auxiliar, '\n'); // Limpiar buffer
        cout << RAYITAS << endl;

        switch (eleccion)
        {

        case NUEVA_LECTURA:
            nueva_lectura();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case QUITAR_LECTURA:
            quitar_lectura();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case AGREGAR_ESCRITOR:
            agregar_escritor();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case CAMBIAR_DATO_ESCRITOR:
            cambiar_dato_escritor();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case LISTAR_ESCRITORES:
            listar_escritores();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case LECTURA_RANDOM:
            mostrar_lectura_random();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case LISTAR_LECTURAS_TODAS:
            listar_lecturas_todas();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case LISTAR_LECTURAS_ANIOS:
            listar_lecturas_anios();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case LISTAR_LECTURAS_ESCRITOR:
            listar_lecturas_escritor();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case LISTAR_NOVELAS_GENERO:
            listar_novelas_genero();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case CREAR_COLA:
            crear_cola(cola_lecturas);
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case TIEMPO_MINIMO_LECTURA:
            tiempo_minimo_lectura();
            cout << RAYITAS << endl;
            cout << endl;
            break;

        case SALIR:
            cout << MSJ_SALIDA << endl;
            return;

        default:
            break;
        }

        cout << MSJ_CONSULTA_MENU;
        getline(cin, auxiliar);
        if(auxiliar == "s")
            cout << endl;
        else
            eleccion = SALIR;

    } while (eleccion != SALIR);

    cout << MSJ_SALIDA << endl;
}

Escritor *Menu::obtener_autor(Hashing *tabla_escritores)
{
    string nombre_apellido;
    cout << MSJ_INRGESAR_REFERENCIA_AUTOR << endl;
    getline(cin, nombre_apellido, '\n');

    if (nombre_apellido == "ANONIMO")
    {
        return nullptr;
    }

    return tabla_escritores->consulta(nombre_apellido);
}

char *Menu::obtener_tema(string tema)
{
    char *copia = new char[tema.size() + 1];
    copy(tema.begin(), tema.end(), copia);
    copia[tema.size()] = '\0';
    return copia;
}

void Menu::nueva_lectura()
{
    char tipo_lectura;
    string auxiliar, titulo, libro;
    unsigned int minutos;
    unsigned short int anio;
    Escritor *autor;
    Lectura *nueva_lectura;

    cout << MSJ_INGRESAR_TIPO_LECTURA << endl;
    cin >> tipo_lectura;
    cin.ignore(256, '\n'); // limpio buffer
    tipo_lectura = (char)tolower(tipo_lectura);

    cout << MSJ_INGRESAR_TITULO << endl;
    getline(cin, titulo, '\n');

    cout << MSJ_INGRESAR_MINUTOS << endl;
    cin >> minutos;
    cin.ignore(256, '\n'); // limpio buffer

    cout << MSJ_INGRESAR_ANIO << endl;
    cin >> anio;
    cin.ignore(256, '\n'); // limpio buffer

    if (tipo_lectura == 'c')
    {
        cout << MSJ_INGRESAR_LIBRO << endl;
        getline(cin, libro, '\n');
        autor = obtener_autor(tabla_escritores);
        nueva_lectura = new Cuento('C', titulo, minutos, anio, libro, autor);
        lista_lecturas->alta(nueva_lectura);
    }
    else if (tipo_lectura == 'n')
    {
        cout << MSJ_INGRESAR_GENERO << endl;
        getline(cin, auxiliar, '\n');
        genero_t genero = string_to_genero(auxiliar);

        if (genero == HISTORICA)
        {
            cout << MSJ_INGRESAR_TEMA << endl;
            getline(cin, auxiliar, '\n');
            char *tema = obtener_tema(auxiliar);
            autor = obtener_autor(tabla_escritores);
            nueva_lectura = new Novela_historica('H', titulo, minutos, anio, tema, autor);
            lista_lecturas->alta(nueva_lectura);
        }
        else
        {
            autor = obtener_autor(tabla_escritores);
            nueva_lectura = new Novela('N', titulo, minutos, anio, genero, autor);
            lista_lecturas->alta(nueva_lectura);
        }
    }
    else if (tipo_lectura == 'p')
    {
        cout << MSJ_INGRESAR_VERSOS << endl;
        int versos;
        cin >> versos;
        cin.ignore(256, '\n'); // limpio buffer
        autor = obtener_autor(tabla_escritores);
        nueva_lectura = new Poema('P', titulo, minutos, anio, versos, autor);
        lista_lecturas->alta(nueva_lectura);
    }
    cout << MSJ_LECTURA_AGREGADA_OK << endl;
}

void Menu::quitar_lectura()
{
    string referencia;
    cout << MSJ_BAJA_LISTA << endl;
    getline(cin, referencia, '\n');
    int posicion = 1;
    Nodo<Lectura> *nodo_lectura = lista_lecturas->obtener_nodo(1);

    while (nodo_lectura->obtener_siguiente() != NULL && nodo_lectura->obtener_dato()->obtener_titulo() != referencia)
    {
        nodo_lectura = nodo_lectura->obtener_siguiente();
        posicion++;
    }

    lista_lecturas->baja(posicion);
    cout << MSJ_LECTURA_QUITADA_OK ;
}

void Menu::agregar_escritor()
{
    string auxiliar, nombre_apellido, nacionalidad;
    int isni;
    short int anio_nacimiento, anio_fallecimiento;

    cout << MSJ_INGRESAR_ISNI << endl;
    cin >> isni;
    cin.ignore(256, '\n'); // limpio buffer
    cout << MSJ_INGRESAR_NOMBRE << endl;
    getline(cin, nombre_apellido, '\n');
    cout << MSJ_INGRESAR_NACIONALIDAD << endl;
    getline(cin, nacionalidad, '\n');
    cout << MSJ_INGRESAR_NACIMIENTO << endl;
    cin >> anio_nacimiento;
    cin.ignore(256, '\n'); // limpio buffer
    cout << MSJ_INGRESAR_FALLECIMIENTO << endl;
    cin >> anio_fallecimiento;
    cin.ignore(256, '\n'); // limpio buffer

    Escritor *nuevo_escritor = new Escritor(isni, nombre_apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    tabla_escritores->alta(nuevo_escritor);

    cout << MSJ_ESCRITOR_AGREGADO_OK;
}

void Menu::cambiar_dato_escritor()
{
    short int anio_fallecimiento_actualizado;
    string referencia;
    cout << MSJ_ESCRITOR_FALLECIMIENTO << endl;
    getline(cin, referencia, '\n');
    cout << MSJ_ANIO_FALLECIMIENTO << endl;
    cin >> anio_fallecimiento_actualizado;
    cin.ignore(256, '\n');  // limpio buffer
    Escritor *escritor = tabla_escritores->consulta(referencia);

    if (escritor != nullptr)
    {
        escritor->cambiar_fallecimiento(anio_fallecimiento_actualizado);
    }
}

void Menu::listar_escritores()
{
    cout << MSJ_LISTA_ESCRITORES_MOSTRAR << endl;
    tabla_escritores->mostrar();
}

void Menu::mostrar_lectura_random()
{
    cout << MSJ_LECTURA_RANDOM << endl;
    int maximo = lista_lecturas->obtener_cantidad();
    int posicion = rand() % maximo + 1;
    lista_lecturas->consulta(posicion)->mostrar();
}

void Menu::listar_lecturas_todas()
{
    cout << MSJ_LISTA_LECTURAS_MOSTRAR << endl;
    lista_lecturas->mostrar();
}

void Menu::listar_lecturas_anios()
{
    int cota_inferior, cota_superior;
    bool encontro = false;
    cout << MSJ_INTERVALO_ANIOS_DESDE << endl;
    cin >> cota_inferior;
    cin.ignore(256, '\n'); // limpio buffer
    cout << MSJ_INTERVALO_ANIOS_HASTA << endl;
    cin >> cota_superior;
    cin.ignore(256, '\n'); // limpio buffer

    Nodo<Lectura> *primer_nodo = lista_lecturas->obtener_nodo(1);

    while (primer_nodo->obtener_dato()->obtener_anio() < cota_inferior)
    {
        primer_nodo = primer_nodo->obtener_siguiente();
    }

    cout << MSJ_LECTURAS_ENTRE_ANIOS << endl;
    
    while (primer_nodo != NULL && primer_nodo->obtener_dato()->obtener_anio() <= cota_superior)
    {
        encontro = true;
        primer_nodo->obtener_dato()->mostrar();
        cout << endl;
        primer_nodo = primer_nodo->obtener_siguiente();
    }

    if(!encontro){
        cout << MSJ_NO_LECTURAS_ENTRE_ANIOS << endl;
    }
}

void Menu::listar_lecturas_escritor()
{
    string nombre_apellido;
    bool encontro = false;
    cout << MSJ_LISTAR_LECTURAS_ESCRITOR << endl;
    getline(cin, nombre_apellido, '\n');
    cout << endl;
    Nodo<Lectura> *nodo_actual = lista_lecturas->obtener_nodo(1);

    cout << MSJ_LECTURAS_AUTORES << nombre_apellido << MSJ_LECTURAS_AUTORES_2 << endl;
    if (nombre_apellido == "ANONIMO")
    {
        while (nodo_actual->obtener_siguiente() != NULL)
        {
            if (nodo_actual->obtener_dato()->obtener_autor() == NULL)
            {
                encontro = true;
                nodo_actual->obtener_dato()->mostrar();
            }
            nodo_actual = nodo_actual->obtener_siguiente();
        }
    }
    else
    {
        while (nodo_actual->obtener_siguiente() != NULL)
        {
            if (nodo_actual->obtener_dato()->obtener_autor() != NULL)
            {
                if (nodo_actual->obtener_dato()->obtener_autor()->obtener_nombre_apellido() == nombre_apellido)
                {
                    encontro = true;
                    nodo_actual->obtener_dato()->mostrar();
                    cout << endl;
                }
            }
            nodo_actual = nodo_actual->obtener_siguiente();
        }
    }

    if(!encontro){
        cout << MSJ_NO_LECTURAS_AUTOR << endl;
    }
}

void Menu::listar_novelas_genero()
{
    string aux;
    cout << MSJ_INGRESAR_GENERO_BUSCAR << endl;
    cin >> aux;
    cin.ignore(256, '\n'); // limpio buffer
    genero_t genero = string_to_genero(aux);

    Nodo<Lectura> *nodo_actual = lista_lecturas->obtener_nodo(1);

    cout << MSJ_NOVELAS_GENERO << endl;
    while (nodo_actual != NULL)
    {
        nodo_actual->obtener_dato()->mostrar_si_genero(genero);
        nodo_actual = nodo_actual->obtener_siguiente();
    }
}

void Menu::crear_cola(Cola<Lectura> *cola_lecturas)
{
    string auxiliar;
    char fue_leido;

    if (cola_creada == false)
    {
        cola_lecturas->encolar(lista_lecturas);
        cola_creada = true;
    }

    cout << MSJ_MOSTRAR_COLA << endl;
    cola_lecturas->consulta();

    cout << MSJ_HA_LEIDO;
    cin >> fue_leido;
    cin.ignore(256, '\n'); // limpio buffer

    fue_leido = (char)tolower(fue_leido);

    if (fue_leido == 's')
    {
        cola_lecturas->baja();
        if (!cola_lecturas->vacia())
        {
            cout << MSJ_MOSTRAR_COLA << endl;
            cola_lecturas->consulta();
        }
        else
        {
            cout << MSJ_COLA_VACIA << endl;
            cola_creada = false;
        }
    }
    else
    {
        cout << MSJ_NO_HA_LEIDO << endl;
        cout << MSJ_MOSTRAR_COLA << endl;
        cola_lecturas->consulta();
    }
}

void Menu::tiempo_minimo_lectura()
{
    Grafo grafo(lista_lecturas);
    grafo.generar_grafo();
    grafo.arbol_expansion_minima();
}

Menu::~Menu()
{
}