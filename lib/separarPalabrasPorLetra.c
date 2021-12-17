#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida


void separarPalabrasPorLetra(FILE *palabras, FILE *indice, FILE *separador){
  /*
  * Nombre de la función      : Separar Palabras por Letra.
  * Tipo de función           : void.
  * Parámetros                : palabras, archivo - lugar donde se leerán las palabras.
                                indice, archivo - lugar donde están almacenados los punteros de las palabras.
                                separador, archivo - lugar donde serán escritos los resutados de separar las palabras por letra.
  * Dato de retorno           : ninguno (void).
  * Descripción de la función : Genera uno de los archivos de cache que facilitan la búsqueda de las palabras, este estableciendo desde
                                antes de la ejecución la separación por letra, además de poder definir los límites de búsqueda para mayor
                                eficiencia.
  */
  long int largo = 0;
  long int direccion = 0;
  unsigned char letra = 0;
  int contador = 0;
  char palabra_con_letra[16];
  char letra_a_comprobar = 0;
  long int desplazamiento = 0x80;
  fseek(indice, 0L, SEEK_END);
  largo = ftell(indice);
  fseek(indice, 0l, SEEK_SET);
  for(char letra_a_comprobar = 'A'; letra_a_comprobar <= 'Z'; letra_a_comprobar++){
    desplazamiento = ftell(separador);
    if (letra_a_comprobar == 'A'){
      desplazamiento = 0x80;
    } else {
      desplazamiento += 4;
    };
    fseek(separador, (letra_a_comprobar - 0x41) << 2 , SEEK_SET);
    fwrite(&desplazamiento,sizeof(int),1,separador);
    fseek(separador, desplazamiento, SEEK_SET);
  for (int i = 0; i < (largo >> 2); i++) {
    fseek(indice, (i << 2), SEEK_SET);
    fread(&direccion, sizeof(int),1,indice);
    fseek(palabras, direccion, SEEK_SET);
    fread(&palabra_con_letra, sizeof(char),16,palabras);
    fseek(palabras, direccion, SEEK_SET);
    contador = 0;
    while(contador == 0){
      fread(&letra, sizeof(unsigned char),1,palabras);
      letra = letra & 0xDF;
      if (letra == 0x0A){
        contador = 1;
      } else if (letra == letra_a_comprobar) {
        fwrite(&direccion,sizeof(int),1,separador);
        //printf("%s\n", palabra_con_letra);
        contador = 1;
      } else if (letra == 0xC3){
        fread(&letra, sizeof(unsigned char),1,palabras);
        letra = letra & 0xDF;
        switch(letra){
            case  0xA1  : if (letra_a_comprobar == 'A'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xA9  : if (letra_a_comprobar == 'E'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xAD  : if (letra_a_comprobar == 'I'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xB3  : if (letra_a_comprobar == 'O'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xBA  : if (letra_a_comprobar == 'U'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
        };
      } else {
        contador = 0;
      };
    };
  };
};
}
