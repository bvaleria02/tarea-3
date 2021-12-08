#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla


void generarArchivoPalabras(FILE *palabras, FILE *indice){
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
