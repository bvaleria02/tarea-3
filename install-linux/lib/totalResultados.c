#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida

int totalResultados (FILE *contenedor){                                                       // Calcula dónde está el final de los resultados, y lo devuelve
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
