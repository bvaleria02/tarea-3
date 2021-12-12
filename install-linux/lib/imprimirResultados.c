#include "libSeparador.h"
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla
#include <stdio.h>          // Librería estándar de entrada y salida

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

extern  int posicionPantalla;
extern  int resultados;
extern  FILE *palabras;

void imprimirResultados (int posicionPantalla, FILE *contenedor, FILE *palabras, int resultados){                                     // Pone los 20 resultados seleccionados en la pantalla
    int puntero[1];
    unsigned char buffer_1[24];
    int a = 0;
    gotoxy(5, 10);
    printf("Resultados: %d", resultados);
    for (int i = 0; i < 20; i++) {
      fseek(contenedor, (posicionPantalla + i) << 2, SEEK_SET);                  // Lee el puntero desde el archivo
      fread(puntero, sizeof(int), 1, contenedor);
      if (puntero[0] == 0xFFFFFFFF){
        i = 20;
      } else {
      fseek(palabras, puntero[0], SEEK_SET);                                    // Almacena la palabra como tal para posteriormente trabajarla
      fread(buffer_1, sizeof(unsigned char), 24, palabras);
      a = 0;
      for (int j = 0; j < 24; j++) {                                            // Elimina todo lo que no sea de la palabra, para quitar la basura que pueda meterse
        if (a == 1){
          buffer_1[j] = 0x0;
        } else if (buffer_1[j] == 0xA){
          a = 1;
          buffer_1[j] = 0x0;
        };
      };
      gotoxy(5, 14 + i);                                                        // Imprime tanto el número como la palabra, una debajo de la anterior hasta llegar a la 20
      printf("%d\t%s", posicionPantalla + i, buffer_1);
      };
    };

}
