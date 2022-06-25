#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

#include <string>
#include "funciones.h"

using namespace std;

typedef enum genero {DRAMA, COMEDIA, FICCION, SUSPENSO, 
TERROR, ROMANTICA, HISTORICA} genero_t;

//PRE: genero debe ser una sola palabra y estar dentro de las posibilidades que el enum
//POS: devuelve el genero_t asociado
genero_t string_to_genero(string genero);

//PRE: genero es un genero válido
//POS: devuelve la string asociada
string genero_to_string(genero_t genero);

#endif
