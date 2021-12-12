#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla

int filtroLongitud (FILE *palabras, int regla, int longitud, int locacion, FILE *separador){   // Con el modo dado, este retorna un 1 si es correcta la longitud a los parámetros
  unsigned char buffer_1[20];
  int largo = 0;
  int a = 0;
  int desplazamiento[1];
  fseek(separador, locacion, SEEK_SET);                                                        // Lee la palabra para posteriormente calcular su longitud
  fread(desplazamiento, sizeof(int), 1, separador);
  locacion = desplazamiento[0];
  fseek(palabras, locacion, SEEK_SET);
  fread(buffer_1, sizeof(unsigned char), 19, palabras);
  largo = __stringlength(buffer_1, 1);
  switch (regla) {                                                                            // Dependiendo el modo, hará cierta clase de comparaciones
    case 0  : if (largo < longitud){                                                          // Menor que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 1  : if (largo == longitud){                                                         // Igual que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 2  : if (largo > longitud){                                                          // Mayor que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 3  : if (largo <= longitud){                                                         // Menor o igual que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 4  : if (largo >= longitud){                                                         // Mayor o igual que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 5  : if (largo != longitud){                                                         // Es distinto que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 6  : a = 1;                                                                          // Todo pasa por acá...
              break;
  };
  //printf("\n%d, %d, %d %d %s", regla, largo, longitud, a, buffer_1);
  return a;
}
