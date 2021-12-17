#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida

int __stringlength(char *text_string, int modo){                                          // strlen no sirve cuanndo no se trata del dígito particular, esto resuelve ese problema y da soporte para toda la sarta de cosas raras que hay en cuanto palabras
  /*
  * Nombre de la función      : string length (longitud de la cadena).
  * Tipo de función           : entero.
  * Parámetros                : cadena de texto, puntero de cadena de texto - lugar desde donde se lee el texto para buscar su longitud.
                                modo, variable entera - establece el modo por el cual detener la longitud.
  * Dato de retorno           : entero, siendo este el largo de la cadena ingresada.
  * Descripción de la función : Entrega la longitud de la cadena ingresada, pero a diferencia de strlen de string.h, este no se detiene al encontrar
                                un espacio, y además dependiendo el modo, se detiene al encontrar solo un dígito terminador, así como no contar
                                carácteres especiales.
  */
    int a = 0;
    unsigned char b = 0;
    for (int i = 0; i < 63; i++) {                                              // Carga la palabra, y si detecta un término, deja de contar
        b = text_string[i];
        if ((b == 0x0A || b == '\0' || b == 0xFF || b == 0x20) && modo == 0){
          i = 64;
        } else if ((b == 0x0A || b == '\0' || b == 0xFF) && modo > 0){
          i = 64;
        } else if ((b == 0xC2 || b == 0xC3) && modo < 2) {

        } else {
          a++;
        };
    };
    // printf("%i", a);
    return a;
}
