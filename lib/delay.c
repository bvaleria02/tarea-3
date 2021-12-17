#include "libSeparador.h"

void delay(int time){                     // Genera un pequeño retardo, usado para fines de testeo
  /*
  * Nombre de la función      : Delay.
  * Tipo de función           : void.
  * Parámetros                : "time" de tipo int - Las veces que será repetido el código.
  * Dato de retorno           : ninguno (void).
  * Descripción de la función : Esta función genera un retardo dentro de la ejecución del programa. No se utiliza más que en las versiones
                                de desarrollo para probar el funcionamiento al imprimir por consola.
  */
  int a;
  time = time << 2;
  for (int i = 0; i < time; i++) {
    a++;
    a--;
    a++;
    a--;
    a++;
    a--;
    a++;
    a--;
    a++;
  };
}
