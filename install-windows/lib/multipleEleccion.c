#include "libSeparador.h"
#include <stdio.h>
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla
#include <conio.h>

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

static char* eleccion[]  = {"Menor que          ", "Igual que          ", "Mayor que          ", "Menor o igual que  ", "Mayor o igual que  ", "Distinto que       ", "Todos              "};

int multipleEleccion(int cantidad){                                             // Gestiona las entradas de elecciones múltiples
  int posicion = 0;
  int c = 0;
  char tecla = 0;
  int x = 19;
  int y = 15;
  getch();                                                                      // Limpieza de la parte de los controles
  gotoxy(3, 7);
  printf("                                        ");
  gotoxy(3, 8);
  printf("                                        ");
  gotoxy(3, 7);
  printf("\033[0;30;47mENTER:\033[0;0m Aceptar");
  while (c == 0){
    for (int i = 0; i < cantidad; i++) {                                        // Limpia la entrada, para después resaltar
      gotoxy(x, y + i);
      printf("\033[0;0;0m  %s", eleccion[i]);
    }
    gotoxy(x, y + posicion);                                                    // Resalta la opción elegida
    printf("\033[0;30;47m» %s", eleccion[posicion]);
    gotoxy(1, 32);
    tecla = teclado(1);                                                         // Lee el teclado, para irse hacia arriba o abajo
    switch(tecla){
      case  0x1 : if (posicion == 0){
                      posicion = cantidad - 1;
                    } else {
                      posicion--;
                    };
                    break;
      case  0x2 :  if (posicion == cantidad - 1){
                      posicion = 0;
                    } else {
                      posicion++;
                    };
                    break;
      case  0x7F :  c = 1;
                    break;
    };
  };
  printf("\033[0;0;0m");                                                        // Devuelve la terminal a la normalidad
  return posicion;
}
