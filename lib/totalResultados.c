#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida

int totalResultados (FILE *contenedor){                                                       // Calcula dónde está el final de los resultados, y lo devuelve
  /*
  * Nombre de la función      : Total Resultados
  * Tipo de función           : entero.
  * Parámetros                : contenedor, archivo - lugar desde donde leerá los punteros en busca de un terminador.
  * Dato de retorno           : entero, siendo este cuántos punteros válidos hay en el archivo.
  * Descripción de la función : busca uno a uno los punteros del archivo contenedor, hasta encontrar uno que sea terminador (0xFFFFFFFF)
  */
  int longitud = 0;
  int a = 0;
  int puntero[1];
  fseek(contenedor, 0, SEEK_SET);
  while (a == 0){
    fread(puntero, sizeof(int), 1, contenedor);                                               // Lee hasta que encuentra un 0xFFFFFFFF, si lo hay , se detiene
    if (puntero[0] == 0xFFFFFFFF){
      a = 1;
    } else {
      longitud++;
    };
  };
  return longitud;
}
