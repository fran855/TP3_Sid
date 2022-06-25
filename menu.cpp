#include "menu.h"

using namespace std;

Menu::Menu(Lista<Lectura> *lista_lecturas, Lista<Escritor> *lista_escritores)
{
    this->lista_lecturas = lista_lecturas;
    this->lista_escritores = lista_escritores;
    this -> cola_creada = false;

    srand(time(NULL)); // Inicializar semilla
}

void Menu::ejecutar_menu(Cola<Lectura>* cola_lecturas)
{
    string auxiliar;
    do
    {
        cout << MSJ_CABECERA_MENU << endl;
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

        case SALIR:
            return;

        default:
            break;
        }

    } while (eleccion != SALIR);
}

Escritor* Menu::obtener_autor(Lista<Escritor> *lista_escritores)
{
    string nombre_apellido;
    cout << MSJ_INRGESAR_REFERENCIA_AUTOR << endl;
    getline(cin, nombre_apellido, '\n');
    
    if (nombre_apellido == "ANONIMO")
    {
        return nullptr;
    }

    Nodo<Escritor>* nodo_escritor = lista_escritores -> obtener_nodo(1);
    while (nodo_escritor != NULL)
    {
        if (nodo_escritor->obtener_dato()->obtener_nombre_apellido() == nombre_apellido)
        {
            return nodo_escritor -> obtener_dato() -> obtener_direccion();
        }
        nodo_escritor = nodo_escritor->obtener_siguiente();
    }

    return nullptr; //si no lo encuentro es anonimo    
}

char* Menu::obtener_tema(string tema)
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
    tipo_lectura = tolower(tipo_lectura);
    getline(cin, auxiliar, '\n'); // Limpiar buffer

    cout << MSJ_INGRESAR_TITULO << endl;
    getline(cin, titulo, '\n');

    cout << MSJ_INGRESAR_MINUTOS << endl;
    cin >> minutos;
    getline(cin, auxiliar, '\n'); // Limpiar buffer

    cout << MSJ_INGRESAR_ANIO << endl;
    cin >> anio;
    getline(cin, auxiliar, '\n'); // Limpiar buffer

    if (tipo_lectura == 'c')
    {
        cout << MSJ_INGRESAR_LIBRO << endl;
        getline(cin, libro, '\n');
        autor = obtener_autor(lista_escritores);
        nueva_lectura = new Cuento(titulo, minutos, anio, libro, autor);
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
            char* tema = obtener_tema(auxiliar);
            autor = obtener_autor(lista_escritores);
            nueva_lectura = new Novela_historica(titulo, minutos, anio, tema, autor);
            lista_lecturas->alta(nueva_lectura);
        }
        else
        {
            autor = obtener_autor(lista_escritores);
            nueva_lectura = new Novela(titulo, minutos, anio, genero, autor);
            lista_lecturas->alta(nueva_lectura);
        }
    }
    else if (tipo_lectura == 'p')
    {
        cout << MSJ_INGRESAR_VERSOS << endl;
        int versos;        
        cin >> versos;
        getline(cin, auxiliar, '\n'); // Limpiar buffer
        autor = obtener_autor(lista_escritores);
        nueva_lectura = new Poema(titulo, minutos, anio, versos, autor);
        lista_lecturas->alta(nueva_lectura);
    }
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
}

void Menu::agregar_escritor()
{
    int ultimo_id = lista_escritores->obtener_cantidad();
    string auxiliar, nombre_apellido, nacionalidad;
    int anio_nacimiento, anio_fallecimiento;

    cout << MSJ_INGRESAR_NOMBRE << endl;
    getline(cin, nombre_apellido, '\n');
    cout << MSJ_INGRESAR_NACIONALIDAD << endl;
    getline(cin, nacionalidad, '\n');
    cout << MSJ_INGRESAR_NACIMIENTO << endl;
    cin >> anio_nacimiento;
    cout << MSJ_INGRESAR_FALLECIMIENTO << endl;
    cin >> anio_fallecimiento;

    Escritor *nuevo_escritor = new Escritor(ultimo_id + 1, nombre_apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    lista_escritores->alta(nuevo_escritor, ultimo_id + 1);
}

void Menu::cambiar_dato_escritor()
{
    int anio_fallecimiento_actualizado;
    string referencia;
    cout << MSJ_ESCRITOR_FALLECIMIENTO << endl;
    getline(cin, referencia, '\n');
    cout << MSJ_ANIO_FALLECIMIENTO << endl;
    cin >> anio_fallecimiento_actualizado;
    Nodo<Escritor> *nodo_escritor = lista_escritores->obtener_nodo(1);

    while (nodo_escritor->obtener_siguiente() != NULL)
    {
        if (nodo_escritor->obtener_dato()->obtener_nombre_apellido() == referencia)
        {
            nodo_escritor->obtener_dato()->cambiar_fallecimiento(anio_fallecimiento_actualizado);
        }
        nodo_escritor = nodo_escritor->obtener_siguiente();
    }
}

void Menu::listar_escritores()
{
    lista_escritores->mostrar();
}

void Menu::mostrar_lectura_random()
{
    int maximo = lista_lecturas->obtener_cantidad();
    int posicion = rand() % maximo + 1;
    lista_lecturas->consulta(posicion)->mostrar();
}

void Menu::listar_lecturas_todas()
{
    lista_lecturas->mostrar();
}

void Menu::listar_lecturas_anios()
{
    int cota_inferior, cota_superior;
    cout << MSJ_INTERVALO_ANIOS_DESDE << endl;
    cin >> cota_inferior;
    cout << MSJ_INTERVALO_ANIOS_HASTA << endl;
    cin >> cota_superior;

    Nodo<Lectura> *primer_nodo = lista_lecturas->obtener_nodo(1);

    while (primer_nodo->obtener_dato()->obtener_anio() < cota_inferior)
    {
        primer_nodo = primer_nodo->obtener_siguiente();
    }

    while (primer_nodo != NULL && primer_nodo->obtener_dato()-> obtener_anio() <= cota_superior)
    {
        primer_nodo->obtener_dato()->mostrar();
        cout << endl;
        primer_nodo = primer_nodo->obtener_siguiente();
    }
}

void Menu::listar_lecturas_escritor()
{
    string nombre_apellido;
    cout << MSJ_LISTAR_LECTURAS_ESCRITOR << endl;
    getline(cin, nombre_apellido, '\n');
    cout << endl;
    Nodo<Lectura> *nodo_actual = lista_lecturas->obtener_nodo(1);

    if (son_iguales(nombre_apellido, "ANONIMO"))
    {
        while (nodo_actual->obtener_siguiente() != NULL)
        {
            if (nodo_actual->obtener_dato()->obtener_autor() == NULL)
            {
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
                if (son_iguales(nodo_actual->obtener_dato()->obtener_autor()->obtener_nombre_apellido(), nombre_apellido))
                {
                    nodo_actual->obtener_dato()->mostrar();
                    cout << endl;
                }
            }
            nodo_actual = nodo_actual->obtener_siguiente();
        }
    }
}

void Menu::listar_novelas_genero()
{
    string aux;
    cout << MSJ_INGRESAR_GENERO_BUSCAR << endl;
    cin >> aux;
    genero_t genero = string_to_genero(aux);

    Nodo<Lectura> *nodo_actual = lista_lecturas->obtener_nodo(1);

    while (nodo_actual->obtener_siguiente() != NULL)
    {
        nodo_actual->obtener_dato()->mostrar_si_genero(genero);
        nodo_actual = nodo_actual->obtener_siguiente();
    }
}

void Menu::crear_cola(Cola<Lectura>* cola_lecturas){
        string auxiliar;
        char fue_leido;

        if(cola_creada == false){
            cola_lecturas -> encolar(lista_lecturas);
            cola_creada = true;
        }
    
        cout << MSJ_MOSTRAR_COLA << endl;
        cola_lecturas -> consulta();

        cout << MSJ_HA_LEIDO << endl;
        cin >> fue_leido;
        getline(cin, auxiliar, '\n'); // Limpiar buffer

        fue_leido = tolower(fue_leido);

        if(fue_leido == 's'){
            cola_lecturas -> baja();
            if(!cola_lecturas -> vacia()){
                cout << MSJ_MOSTRAR_COLA << endl;
                cola_lecturas -> consulta();
            }else{
                cout << MSJ_COLA_VACIA << endl;
                cola_creada = false;
            }
        }else{
            cout << MSJ_NO_HA_LEIDO << endl;
            cout << MSJ_MOSTRAR_COLA << endl;
            cola_lecturas -> consulta();
        }

}

Menu::~Menu(){
}