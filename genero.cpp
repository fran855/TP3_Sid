#include "genero.h"

genero_t string_to_genero(string genero){
  if (son_iguales(genero, "DRAMA"))
    return DRAMA;
  else if (son_iguales(genero, "COMEDIA"))
    return COMEDIA;
  else if (son_iguales(genero, "FICCION"))
    return FICCION;
  else if (son_iguales(genero, "SUSPENSO"))
    return SUSPENSO;
  else if (son_iguales(genero, "TERROR"))
    return TERROR;
  else if (son_iguales(genero, "ROMANTICA"))
    return ROMANTICA;
  else 
    return HISTORICA;
}


string genero_to_string(genero_t genero){
  if (genero == DRAMA)
    return "DRAMA";
  else if (genero == COMEDIA)
    return "COMEDIA";
  else if (genero == FICCION)
    return "FICCION";
  else if (genero == SUSPENSO)
    return "SUSPENSO";
  else if (genero == TERROR)
    return "TERROR";
  else if (genero == ROMANTICA)
    return "ROMANTICA";
  else
    return "HISTORICA";
}