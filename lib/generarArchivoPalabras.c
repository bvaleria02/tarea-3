#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla


void generarArchivoPalabras(FILE *palabras, FILE *indice){
  /*
  * Nombre de la función      : Generar Archivo con Palabras
  * Tipo de función           : void.
  * Parámetros                : palabras, archivo - Establece desde donde leer las palabras.
                                indice, archivo - Establece donde dejar los punteros de las palabras
  * Dato de retorno           : ninguno (void).
  * Descripción de la función : Esta función lee el archivo de palabras, y genera un segundo archivo solo con los punteros de la palabras.
  */
    long int largo = 0;
    char letra = 0;
    long int posicion = 0;
    fseek(palabras, 0L, SEEK_END);
    largo = ftell(palabras);
    fseek(palabras, 0l, SEEK_SET);
    posicion = 0;
    fwrite(&posicion, sizeof(int),1,indice);
    for (long int i = 0; i < largo; i++) {
      fread(&letra, sizeof(unsigned char),1,palabras);
      posicion = i + 1;
      if (letra == 0x0A){
        fwrite(&posicion, sizeof(int),1,indice);
      };
    };
}
