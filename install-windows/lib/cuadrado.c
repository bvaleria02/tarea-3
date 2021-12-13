#include "libSeparador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

static char* eleccion[]  = {"Menor que          ", "Igual que          ", "Mayor que          ", "Menor o igual que  ", "Mayor o igual que  ", "Distinto que       ", "Todos              "};

void cuadrado(char *texto, int alto, int modo){                                 // Crea un cuadrado en el medio de la pantalla, encima de totalResultados
                                                                                /* Modos:
                                                                                      0: Mostrar solo texto
                                                                                      1: Texto y cuadro de entrada
                                                                                      2: Texto y elección sí/no
                                                                                      3: Texto y elección múltiple
                                                                                      4: Texto y créditos
                                                                                */
    int longitud = __stringlength(texto, 1);                                               // Obtiene la longitud del texto, para calcular el tamaño del cuadro
    if (modo == 3){
        alto += 2;
    };
    int x = (32 - ((longitud + 2) >> 1));
    int y = (15 - (alto >> 1));
    gotoxy(x, y);                                                               // Imprime el borde exterior
    printf("+");
    for (int i = 0; i < longitud + 2; i++) {
      printf("-");
    };
    printf("+");
    for (int i = 0; i < 1; i++) {
      gotoxy(x, (y+i+1));
      printf("|");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("|");
    };

    gotoxy(x, y + 2);
    printf("| %s |", texto);                                                    // Imprime el texto ingresado

    for (int i = 0; i < alto ; i++) {
      gotoxy(x, y + i + 3);
      printf("|");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("|");
    };
    gotoxy(x, y + alto + 3);
    printf("+");
    for (int i = 0; i < longitud + 2; i++) {
      printf("-");
    };
    printf("+");
    switch(modo){                                                               // Rellena con diferentes cosas, dependiendo del modo
      case  0 : gotoxy(1, 32);
                break;
      case  1 : gotoxy(x+2, y + alto +1 );
                for (int i = 0; i < longitud - 1; i++) {
                  printf("\033[0;30;47m ");
                };
                printf("\033[0;0m ");
                gotoxy(x+3, y + alto +1 );
                break;
      case  2 : gotoxy(32 - (longitud >> 2) - 2, y + alto +1 );
                printf("S: Sí");
                gotoxy(32 + (longitud >> 2) + 2, y + alto +1 );
                printf("N: No");
                printf("\033[0;0m ");
                gotoxy(1, 32);
                break;
      case  3 : for (int i = 0; i < alto - 2; i++) {
                gotoxy(x+5, y + 4 + i);
                printf("%s", eleccion[i]);
                };
                break;
      case  4 : gotoxy(x+3, y + 4);
                printf("Diego Jerez");
                gotoxy(x+3, y + 5);
                printf("Benjamín Valeria");
                gotoxy(x+3, y + 7);
                printf("Presione una tecla para cerrar");
                break;
    };

}
