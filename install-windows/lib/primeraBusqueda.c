#include "libSeparador.h"
#include <stdio.h>         
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

void primeraBusqueda (int direcciones[12], int limSuperior[12], int regla, int longitud, FILE *separador, FILE *contenedor, FILE *palabras){      // compara entre las dos primeras letras las similitudes
    int posicion[2] = {0, 0};
    int punteroLetra[2];
    int a[1] = {0};
    int filtro = 0;
    fseek(contenedor, 0, SEEK_SET);
    while (direcciones[0] + (posicion[0] << 2) <= limSuperior[0]){
        fseek(separador, direcciones[0] + (posicion[0] << 2), SEEK_SET);                                                                          // lee desde el archivos los punteros de las palabras (precalculados anteriormente)
        fread(a, sizeof(int),1,separador);
        punteroLetra[0] = a[0];
        fseek(separador, direcciones[1] + (posicion[1] << 2), SEEK_SET);
        fread(a, sizeof(int),1,separador);
        punteroLetra[1] = a[0];
        if (punteroLetra[0] == punteroLetra[1]){                                                                                                  // Solo en el caso de similitudes, las escribe en el archivo
            filtro = filtroLongitud(palabras, regla, longitud, (direcciones[0] + (posicion[0] << 2)), separador);
            if (filtro == 1){
              fwrite(punteroLetra, sizeof(int),1,contenedor);
            };
            posicion[0]++;
            posicion[1]++;

        } else if (punteroLetra[0] > punteroLetra[1]){
            posicion[1]++;
        } else if (punteroLetra[0] < punteroLetra[1]){
            posicion[0]++;
        };
      };
    a[0] = 0xFFFFFFFF;                                                                                                                            // Escribe un dígito finalizador
    fwrite(a, sizeof(int),1,contenedor);
}
