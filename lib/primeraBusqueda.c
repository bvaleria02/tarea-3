#include "libSeparador.h"
#include <stdio.h>
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

void primeraBusqueda (int direcciones[12], int limSuperior[12], int regla, int longitud, FILE *separador, FILE *contenedor, FILE *palabras){      // compara entre las dos primeras letras las similitudes
  /*
  * Nombre de la función      : Primera Búsqueda.
  * Tipo de función           : void.
  * Parámetros                : direcciones, arreglo de tipo int - Establece desde dónde empezar a buscar para comparar letras.
                                limSuperior, arreglo de tipo int - Establece hasta dónde buscar cuando se comparar una letra.
                                regla, variable entera - elije el modo por el cual operará el filtro por longitud.
                                longitud, variable entera - elije donde poner el foco cuando se filtra por longitud.
                                separador, archivo - lugar donde están separadas las palabras por letra.
                                contenedr, archivo - lugar donde se leeran y almacenarán los resultados.
                                palabras, archivo - lugar donde se leerán las palabras para filtrar por longitud
  * Dato de retorno           : ninguno (void).
  * Descripción de la función : Esta función compara dos letras una a una, y almacena en un archivo si encuentra que en ambas letras hay un puntero similar
                                además, en caso de hallar una coincidencia, filtra según la longitud por distintos modos.
  */
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
