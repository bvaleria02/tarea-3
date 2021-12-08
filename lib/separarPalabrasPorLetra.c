#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida


void separarPalabrasPorLetra(FILE *palabras, FILE *indice, FILE *separador){
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
