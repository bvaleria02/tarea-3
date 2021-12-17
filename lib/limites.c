#include "libSeparador.h"
#include <stdio.h>

void limites (unsigned char Letras[12], int direcciones[12], int limSuperior[12], FILE *separador){   // Calcula los límites para la búsqueda
  /*
  * Nombre de la función      : Límites.
  * Tipo de función           : void.
  * Parámetros                : Letra, arreglo de char - donde se leerán los carácteres para establecer los límites
                                direcciones, arreglo de enteros - establece desde dónde se empezará por buscar al leer una letra.
                                limSuperior, arreglo de enteros - establece hasta dónde se buscará al leer una letra
                                separador, archivo - luegar donde se almacenan los punteros de los límites donde buscar, dependiendo la letra.
  * Dato de retorno           : ninguno (void).
  * Descripción de la función : Esta función guarda en dos arreglos tanto los límites inferiores como superiores desde los cuales acotar la búsqueda.
  */
    int a[1];
    for (int i = 0; i < 12; i++) {                                                                    // Dependiendo de la letra, busca en el archivo los límites que ya han sido precalculados
      if (Letras[i] == 0xFF){
        direcciones[i] = 0;
        limSuperior[i] = 0;
      } else {
        fseek(separador, (Letras[i] - 0x41) << 2, SEEK_SET);
        fread(a, sizeof(int),1,separador);
        direcciones[i] = a[0];
        fread(a, sizeof(int),1,separador);
        limSuperior[i] = a[0] - 4;
      };
    };
}
