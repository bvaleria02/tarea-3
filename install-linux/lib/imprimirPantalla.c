#include "libSeparador.h"
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla
#include <stdio.h>          // Librería estándar de entrada y salida

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

static char* eleccion[]  = {"Menor que          ", "Igual que          ", "Mayor que          ", "Menor o igual que  ", "Mayor o igual que  ", "Distinto que       ", "Todos              "};

void imprimirPantalla (int estado, unsigned char Letras[12], int longitud[2], int regla){       // Refresca la pantalla. Disponde de distintos modos que cambian ligeramente los mensajes mostrados
  clear();
  printf("╔════════════════════ Busca Palabras v0.1 ════════════════════╗ ");                   // Crea el marco
  for (int i = 0; i < 7; i++) {
    printf("\n║                                                             ║");
  };
  printf("\n╠═════════════════════════════════════════════════════════════╣");
  for (int i = 0; i < 2; i++) {
    printf("\n║                                                             ║");
  };
  printf("\n╠═════════════════════════════════════════════════════════════╣");
  for (int i = 0; i < 22; i++) {
    printf("\n║                                                             ║");
  };
  printf("\n╚═════════════════════════════════════════════════════════════╝ ");
  gotoxy(3, 2);
  printf("Letras  : ");                                                                         // Desde aquí, rellema con las etiquetas
  if (estado >= 1){
    for (int i = 0; i < 12; i++) {
      if (Letras[i] == 0xFF){
        i = 13;
      } else {
        printf("%c ", Letras[i]);
      };
    };
  };
  gotoxy(3, 3);
  if (estado >= 2){
    printf("Longitud: %.2d\t\tRegla: ", longitud[0]);
  } else {
    printf("Longitud:\t\tRegla: ");
  };
  if (estado >= 3){
    printf("%s", eleccion[regla]);
  };
  gotoxy(3, 5);
  printf("Comandos:");                                                                            // Imprime los comando con la letra destacada. Depende del estado los que pone
  if (estado > 0){
      gotoxy(3, 6);
      printf("\033[0;30;47mW:\033[0;0m Subir\t\t\033[0;30;47mS:\033[0;0m Bajar\t\033[0;30;47mE:\033[0;0m Exportar");
      gotoxy(3, 7);
      printf("\033[0;30;47mA:\033[0;0m Pag. Anterior\t\033[0;30;47mD:\033[0;0m Pag. Siguiente");
      switch (estado){                                                                            // Mensajes de la sección media
          case 1  : gotoxy(3, 10);
                    printf("\033[0;32mEsperando longitud...\033[0;0m");
                    break;
          case 2  : gotoxy(3, 10);
                    printf("\033[0;32mEsperando filtro...\033[0;0m");
                    break;
      };
    } else {
      gotoxy(3, 10);
      printf("\033[0;36mNo hay trabajo");
      gotoxy(3, 11);
      printf("\033[0;36mPresione alguna tecla para comenzar");
    };
  gotoxy(3, 8);
  printf("\033[0;30;47mB:\033[0;0m Búsqueda Nueva\t\033[0;30;47mX:\033[0;0m Salir");
  gotoxy(1, 32);
  printf("\033[0;0;0m");
}
