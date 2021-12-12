#include "libSeparador.h"
#include <stdio.h>

void busquedasPosteriores (int j, int direcciones[12], int limSuperior[12], FILE *separador, FILE *contenedor, unsigned char Letras[12]){        // Para la segunda y tercera letra, y después
    int posicion[2] = {0, 0};
    int punteroLetra[2];
    int a[1] = {0};
    int b = 0;
    int c = 0;
    int noIgual[1] = {0xFFFFFFFE};
    fseek(contenedor, 0, SEEK_SET);
    while (c == 0){
        fseek(contenedor, (posicion[0] << 2), SEEK_SET);                                                                                          // Carga los punteros, uno del archivo de los resultados y el otro donde los punteros y las letras
        fread(a, sizeof(int),1,contenedor);
        punteroLetra[0] = a[0];
        fseek(separador, (direcciones[j + 1] + (posicion[1] << 2)), SEEK_SET);
        fread(a, sizeof(int),1,separador);
        punteroLetra[1] = a[0];
        //gotoxy(1, 33); printf("%.8x %.8x %.8x", posicion[0] << 2, punteroLetra[0], punteroLetra[1]);
        //printf("\n%c", Letras[j + 1]);
        if (punteroLetra[0] == 0xFFFFFFFF){                                                                                                       // Comparaciones y operaciones de búsqueda- SI llega al final, se detiene
          c = 1;
        } else if (punteroLetra[0] == punteroLetra[1]){
          //printf("aaaa %d", b);
          fseek(contenedor, (b << 2), SEEK_SET);
          fwrite(punteroLetra, sizeof(int),1,contenedor);
          posicion[0]++;
          //posicion[1] = 0;
          b++;
        } else if (limSuperior[j + 1] <= (direcciones[j+1] + (posicion[1] << 2))){
          /*fseek(contenedor, ((posicion[0]) << 2), SEEK_SET);
          fwrite(noIgual, sizeof(int),1,contenedor);*/
          posicion[0]++;
          posicion[1] = 0;
        /*} else if (punteroLetra[0] != punteroLetra[1]){
          posicion[1]++;
        };*/
      } else if (punteroLetra[0] > punteroLetra[1]){
            posicion[1]++;
      } else if (punteroLetra[0] < punteroLetra[1]){
            posicion[0]++;
      };
    };
    a[0] = 0xFFFFFFFF;
    //printf("\n%d %d", b, b << 2);
    fseek(contenedor, b << 2, SEEK_SET);
    fwrite(a, sizeof(int),1,contenedor);
}
