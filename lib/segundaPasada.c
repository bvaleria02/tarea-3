#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida


void segundaPasada (FILE *palabras, FILE *contenedor, unsigned char letras[6], int largo){      // Código no utilizado y que data de una versión anterior del programa. La segunda pasada para verificar no es necesaria en el nuevo algoritmo
  /*
  * Nombre de la función      : Segunda Pasada.
  * Tipo de función           : void.
  * Parámetros                : palabras, archivo - lugar donde se leerán las palabras para corroborar que el filtro es correcto
                                contenedr, archivo - lugar donde se leeran y almacenarán los resultados.
                                letras, arreglo de char - almacena las letras con las cuales se comprobarán las palabras.
                                largo, variable entera - largo de la palabra esperado
  * Dato de retorno           : ninguno (void).
  * Descripción de la función : Deprecado porque el nuevo algoritmo provee soporte para mayor cantidad de letras, además de
                                ser más eficiente y efectivo. Servía en el pasado solo porque surgían errores al momento de
                                comparar, y esto ayudaba a filtrar una segunda vez.
  */
  char bufferPalabra[32];
  int flagLetras = 0;
  int direccionPalabra[1];
  int a = 0;
  int c = 0;
  int noCorresponde[1] = {0xFFFFFFFE};
  //printf("%c %c %c %c %c %c", letras[0], letras[1], letras[2], letras[3], letras[4], letras[5]);
  while (a == 0) {
      flagLetras = 0;
      fseek(contenedor, (c << 2), SEEK_SET);
      fread(direccionPalabra, sizeof(int),1,contenedor);

      if (direccionPalabra[0] == 0xFFFFFFFF){
        a = 1;
      } else {
      fseek(palabras, direccionPalabra[0], SEEK_SET);
      fread(bufferPalabra, sizeof(char),32,palabras);
      //printf("\n %x %s", direccionPalabra[0], bufferPalabra);
      for (int i = 0; i < 32; i++) {
        if (bufferPalabra[i] == 0xA){
          i = 32;
        };
        for (int j = 0; j < largo; j++) {
          //printf("%d, %c %c", j, (bufferPalabra[i] & 0xDF), letras[j]);
          if ((bufferPalabra[i] & 0xDF) == letras[j]){
            flagLetras = flagLetras | (0x1 << j);
            j = 7;
            break;
          };
        };
      };
      //printf("%.2x\n", flagLetras);
      if (flagLetras != ((1 << largo) - 1)){
        fseek(contenedor, (c << 2), SEEK_SET);
        fwrite(noCorresponde, sizeof(int),1,contenedor);
      };
      c++;
    };
  };
}
