#ifndef MENU_H
#define MENU_H

#include <ctime>
#include <iostream>
#include <string>
#include "lista.h"
#include "escritor.h"
#include "lectura.h"
#include "cola.h"
#include "cuento.h"
#include "poema.h"
#include "novela.h"
#include "novela_historica.h"
#include "genero.h"
#include "hashing.h"
#include "grafo.h"

using namespace std;

const string MSJ_CABECERA_MENU = "Bienvenido al club de lectura de Sid!\nIngresa a continuacion la opcion deseada:\n\n1.\tAgregar una lectura a la lista.\n2.\tQuitar una lectura de la lista.\n3.\tAgregar un escritor.\n4.\tCambiar fecha de fallecimiento de un autor.\n5.\tListar los escritores.\n6.\tMostrar una lectura random!\n7.\tMostrar todas las lecturas.\n8.\tMostrar lecturas en un periodo de años.\n9.\tMostrar lecturas segun autor.\n10.\tMostrar novelas segun genero.\n11.\tMostrar el próximo elemento de menor cantidad de minutos sin  leer.\n12.\tMostrar el tiempo mínimo de lectura.\n13.\tSalir del club de lectura.";
const string MSJ_INGRESAR_TIPO_LECTURA = "Ingrese N (Novela), C (Cuento) o P (Poeta):";
const string MSJ_INGRESAR_TITULO = "Ingrese el titulo de la obra:";
const string MSJ_INGRESAR_LIBRO = "Ingrese el libro:";
const string MSJ_INGRESAR_TEMA = "Ingrese el tema:";
const string MSJ_INGRESAR_GENERO = "Ingrese el genero:";
const string MSJ_INGRESAR_VERSOS = "Ingrese la cantidad de versos:";
const string MSJ_INGRESAR_MINUTOS = "Ingrese los minutos estimados de lectura";
const string MSJ_INGRESAR_ANIO = "Ingrese el año de publicacion de la obra:";
const string MSJ_INGRESAR_ISNI = "Ingrese el ISNI:";
const string MSJ_INRGESAR_INFO_LECTURA = "Ingrese la informacion correspondiente segun\nSi es novela, va el género\nSi es novela histórica, va el tema\nSi es cuento, va el título del libro en donde está publicado\nSi es un poema, va la cantidad de versos";
const string MSJ_INRGESAR_REFERENCIA_AUTOR = "Ingrese el nombre y apellido del autor correspondiente:";
const string MSJ_BAJA_LISTA = "Ingrese el nombre de la lectura que quiere quitar:";
const string MSJ_ESCRITOR_FALLECIMIENTO = "Ingrese el nombre y apellido del autor cuyo fallecimiento quiere actualizar:";
const string MSJ_ANIO_FALLECIMIENTO = "Inrgese el año actualizado de fallecimiento:";
const string MSJ_INTERVALO_ANIOS_DESDE = "Ingrese el año de inicio:";
const string MSJ_INTERVALO_ANIOS_HASTA = "Ingrese el año de fin:";
const string MSJ_LISTAR_LECTURAS_ESCRITOR = "Ingrese el nombre y apellido del escritor para ver sus obras:";
const string MSJ_INGRESAR_GENERO_BUSCAR = "Ingrese el genero de las obras que quiere buscar:";
const string MSJ_MOSTRAR_COLA = "La próxima lectura que podrías leer es:\n";
const string MSJ_HA_LEIDO = "\n¿Ha sido leida la obra? (s/n): ";
const string MSJ_INGRESAR_ID = "Ingrese el ID del escritor:";
const string MSJ_INGRESAR_NOMBRE = "Ingrese el nombre y apellido del escritor:";
const string MSJ_INGRESAR_NACIONALIDAD = "Ingrese la nacionalidad del escritor:";
const string MSJ_INGRESAR_NACIMIENTO = "Ingrese el año de nacimiento del escritor:";
const string MSJ_INGRESAR_FALLECIMIENTO = "Ingrese el año de fallecimiento del escritor:";
const string MSJ_COLA_VACIA = "¡No hay más lecturas! Hiciste feliz a Sid :)";
const string MSJ_NO_HA_LEIDO = "\nNo seas perezoso como Sid, lee la obra:\n";
const string MSJ_CONSULTA_MENU = "¿Desea ejecutar el menú? (s/n): ";
const string MSJ_SALIDA = "¡Hasta luego!\nSid.";
const string RAYITAS = "-----------------------------------------------------";

const string MSJ_LECTURA_AGREGADA_OK = "\n¡Lectura agregada con éxito!\n";
const string MSJ_LECTURA_QUITADA_OK = "\n¡Lectura quitada con éxito!\n";
const string MSJ_ESCRITOR_AGREGADO_OK = "\nEscritor agregado con éxito.\n";
const string MSJ_FECHA_CAMBIADA_OK = "\nFecha cambiada con éxito.\n";
const string MSJ_LISTA_ESCRITORES_MOSTRAR = "\nLista de escritores:\n";
const string MSJ_LECTURA_RANDOM = "\nPrueba leyendo:\n";
const string MSJ_LISTA_LECTURAS_MOSTRAR = "\nLista de lecturas:\n";
const string MSJ_LECTURAS_ENTRE_ANIOS = "\nLas lecturas entre aquellos años son:\n";
const string MSJ_LECTURAS_AUTORES = "\nLas lecturas de ";
const string MSJ_LECTURAS_AUTORES_2 = " que tenemos disponibles son:\n";
const string MSJ_NOVELAS_GENERO = "\nLas lecturas pertenecientes a este género que tenemos disponibles son:\n";
const string MSJ_OPCION = "\nOpción:";



enum Opciones_menu {
    NUEVA_LECTURA = 1,
    QUITAR_LECTURA,
    AGREGAR_ESCRITOR,
    CAMBIAR_DATO_ESCRITOR,
    LISTAR_ESCRITORES,
    LECTURA_RANDOM,
    LISTAR_LECTURAS_TODAS,
    LISTAR_LECTURAS_ANIOS,
    LISTAR_LECTURAS_ESCRITOR,
    LISTAR_NOVELAS_GENERO,
    CREAR_COLA,
    TIEMPO_MINIMO_LECTURA,
    SALIR
};

class Menu {
private:
    int eleccion;
    Hashing* tabla_escritores;
    Lista<Lectura>* lista_lecturas;
    Cola<Lectura>* cola_lecturas;
    bool cola_creada;

public:
    // Constructor por defecto
    // PRE: lista_lectura y tabla_escritores son punteros válidos
    // POS: se crea un objeto de tipo Menu
    Menu(Lista<Lectura>* lista_lecturas, Hashing* tabla_escritores);

    // Destructor por defecto
    // PRE: -
    // POS: se elimina el objeto de tipo Menu
    ~Menu();

    // Ejecuta el menu para que el usuario pueda ingresar la accion por realizar
    // PRE: cola_lecturas es un puntero a Cola<Lectura> con memoria reservada
    // POS: se ejecuta el menu
    void ejecutar_menu(Cola<Lectura>* cola_lecturas);
   

private:
    // Encontrar esccritor por nombre
    // PRE: nombre_apellido es un string con el nombre y apellido del escritor existente
    // POS: devuelve un puntero al escritor
    Escritor* encontrar_escritor_nombre(string nombre_apellido);
    
    // Obtener el puntero al escritor en la lista de escritores
    // PRE: tabla_escritores puntero a tabla de hashing válido
    // POS: devuelve un puntero al escritor
    Escritor* obtener_autor(Hashing* tabla_escritores);
    
    // Obtener tema
    // PRE: tema cadena válida
    // POS: devuelve un puntero al tema con memoria creada
    char* obtener_tema(string tema);

    // Nueva lectura
    // PRE: -
    // POS: se agrega una lectura a la lista de lecturas (de forma ordenada)
    void nueva_lectura();

    // Quitar lectura
    // PRE: -
    // POS: se elimina una lectura de la lista de lecturas
    void quitar_lectura();

    // Agregar escritor
    // PRE: -
    // POS: se agrega un escritor a la lista de escritores
    void agregar_escritor();

    // Cambiar dato escritor
    //PRE: -
    //POS: se cambia el dato del escritor
    void cambiar_dato_escritor();

    // Listar escritores
    // PRE: -
    // POS: se listan todos los escritores
    void listar_escritores();

    // Lectura random
    // PRE: -
    // POS: se muestra una lectura aleatoria
    void mostrar_lectura_random();

    // Listar todas las lecturas
    // PRE: -
    // POS: se listan todas las lecturas
    void listar_lecturas_todas();

    // Listar lecturas por años
    // PRE: -
    // POS: se listan todas las lecturas por años
    void listar_lecturas_anios();

    // Listar lecturas por escritor
    // PRE: -
    // POS: se listan todas las lecturas por escritor
    void listar_lecturas_escritor();

    // Listar novelas por genero
    // PRE: -
    // POS: se listan todas las novelas por genero
    void listar_novelas_genero();

    // Crear cola
    // PRE: -
    // POS: se crea una cola de lecturas
    void crear_cola(Cola<Lectura>* cola_lecturas);

    // Tiempo mínimo de lectura
    // PRE: -
    // POS: se crea un árbol de expansión mínima para mostrar el tiempo de lectura mínima de todas las obras y el orden correspondiente
    void tiempo_minimo_lectura();
};

#endif