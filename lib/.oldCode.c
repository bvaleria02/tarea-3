#include "libSeparador.h"


/* Código legendado de los precálculos. Puede o no estar incluido*/


// Antiguo algoritmo

/*
  for (int i = 0; i < longitud[1]; i++) {
    fseek(separador, (Letras[i] - 0x41) << 2, SEEK_SET);
    fread(variabletemporal, sizeof(int),1,separador);
    Direcciones[i] = variabletemporal[0];
    fread(variabletemporal, sizeof(int),1,separador);
    Lim_superior[i] = variabletemporal[0];
  };
  for (int i = 0; i < (longitud[1] - 1); i++) {
    if (i == 0){
      while(a == 0){
        fseek(separador, Direcciones[1], SEEK_SET);
        fread(variabletemporal, sizeof(int),1,separador);
        variabletemporal[1] = variabletemporal[0];
        fseek(separador, Direcciones[0], SEEK_SET);
        fread(variabletemporal, sizeof(int),1,separador);
        //clear();
        //printf("Buscando %c y %c\nDirección 1: %.6X\t%.6X\nDirección 2: %.6X\t%.6X", Letras[0], Letras[1], Direcciones[0], variabletemporal[0], Direcciones[1], variabletemporal[1]);
        //delay(20000);
        if (Direcciones[0] == Lim_superior[0]){
            a = 1;
          } else if (Direcciones[1] == Lim_superior[1]){
            a = 1;
          } else if (variabletemporal[0] > variabletemporal[1]){
            Direcciones[1] = Direcciones[1] + 4;
          } else if (variabletemporal[0] < variabletemporal[1]){
            Direcciones[0] = Direcciones[0] + 4;
          } else if (variabletemporal[0] == variabletemporal[1]){
              fseek(palabras, variabletemporal[0], SEEK_SET);
              fread(impresion, sizeof(unsigned char),20,palabras);
              longitud[1] = __stringlenght(impresion);
              if (longitud[1] == longitud[0]){
                fwrite(&variabletemporal,sizeof(int),1,contenedor);
                };
              Direcciones[0] = Direcciones[0] + 4;
              Direcciones[1] = Direcciones[1] + 4;
          };
      };
      variabletemporal[0] = 0xFFFFFFFF;
      fwrite(&variabletemporal,sizeof(unsigned int),1,contenedor);
    } else {
      a = 0;
      b = 0;
      Direcciones[i] = 0;
      while(a == 0){
        fseek(separador, Direcciones[i+1], SEEK_SET);
        fread(variabletemporal, sizeof(unsigned int),1,separador);
        variabletemporal[1] = variabletemporal[0];
        fseek(contenedor, Direcciones[i], SEEK_SET);
        fread(variabletemporal, sizeof(unsigned int),1,contenedor);
        //clear();
        delay(0);
        //printf("\nBuscando %c y %c\nDirección %d: %.6X\t%.6X\nDirección %d: %.6X\t%.6X", Letras[i], Letras[i+1], i+1, Direcciones[i], variabletemporal[i], i+2, Direcciones[i+1], variabletemporal[i+1]);
        if (Direcciones[i+1] >= Lim_superior[i+1]){
            fseek(contenedor, (b + 1) << 2, SEEK_SET);
            variabletemporal[0] = 0xFFFFFFFF;
            fwrite(&variabletemporal,sizeof(unsigned int),1,contenedor);
            //printf("\n%d", b);
            a = 1;
          } else if (variabletemporal[0] == 0xFFFFFFFF){
            fseek(contenedor, (b + 1) << 2, SEEK_SET);
            variabletemporal[0] = 0xFFFFFFFF;
            fwrite(&variabletemporal,sizeof(unsigned int),1,contenedor);
            //printf("\n%d", b);
            a = 1;
          } else if (variabletemporal[0] == variabletemporal[1]){
              b++;
              fseek(contenedor, b << 2, SEEK_SET);
              variabletemporal[2] = variabletemporal[0];
              variabletemporal[0] = variabletemporal[1];
              fwrite(&variabletemporal,sizeof(int),1,contenedor);
              variabletemporal[0] = variabletemporal[2];
              Direcciones[i] = Direcciones[i] + 4;
              Direcciones[i+1] = Direcciones[i+1] + 4;
          } else if (variabletemporal[0] > variabletemporal[1]){
            Direcciones[i+1] = Direcciones[i+1] + 4;
          } else if (variabletemporal[0] < variabletemporal[1]){
            Direcciones[i] = Direcciones[i] + 4;
          } else {
            a = 1;
          };
      };
    };
  };
  a=0;
  b=0;
*/
