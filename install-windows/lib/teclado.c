#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida
#include <conio.h>

char teclado (int modo){                                                        // Se encarga de leer el teclado, y devolver un número dependiendo de la tecla presionada. Posse varios modos, además
  /*
  * Nombre de la función      : Teclado.
  * Tipo de función           : char.
  * Parámetros                : "modo" de tipo int - Establece cuáles teclas se espera que el usuario ingrese según un número.
  * Dato de retorno           : Tecla pulsada.
  * Descripción de la función : Esta función se encargará de leer entradas del teclado, y dependiendo del modo, relacionarlas con un
                                número para la lógica del programa.
  */
  unsigned int tecla = 0;
  int a = 0;
  int b = 0;
  while (a == 0){
      tecla = getch();
      tecla = tecla & 0xDF;                                                     // Esto hace que mayúsculas y minúsculas se lean por igual
      switch (modo){
          case  0 : switch(tecla){
                      case  'C' : tecla = 0xFD;
                                  a = 1;
                                  break;
                      case  'B' : tecla = 0xFE;
                                  a = 1;
                                  break;
                      case  'X' : tecla = 0xFF;
                                  a = 1;
                                  break;
                      default   : a = 0;
                                  break;
                      };
                      break;
          case  1 : switch(tecla){
                      case  'W' : tecla = 1;
                                  a = 1;
                                  break;
                      case  'S' : tecla = 2;
                                  a = 1;
                                  break;
                      case  0xD : tecla = 0x7F;
                                  a = 1;
                                  break;
                      case  'X' : tecla = 0xFF;
                                  a = 1;
                                  break;
                      case 0xE048 : tecla = 1;
                                    a = 1;
                                    break;
                      case 0xE050 : tecla = 2;
                                    a = 1;
                                    break;

                      /*default   : a = 0;
                                  break;*/
                      };
                      break;
          case  2 : switch(tecla){
                      case  'W' : tecla = 1;
                                  a = 1;
                                  break;
                      case  'S' : tecla = 2;
                                  a = 1;
                                  break;
                      case  'A' : tecla = 3;
                                  a = 1;
                                  break;
                      case  'D' : tecla = 4;
                                  a = 1;
                                  break;
                      case  'E' : tecla = 5;
                                  a = 1;
                                  break;
                      case  'C' : tecla = 0xFD;
                                  a = 1;
                                  break;
                      case  'B' : tecla = 0xFE;
                                  a = 1;
                                  break;
                      case  'X' : tecla = 0xFF;
                                  a = 1;
                                  break;

                      case 0xE048 : tecla = 1;
                                    a = 1;
                                    break;
                      case 0xE050 : tecla = 2;
                                    a = 1;
                                    break;
                      case 0xE04B : tecla = 3;
                                    a = 1;
                                    break;
                      case 0xE04D : tecla = 4;
                                    a = 1;
                                    break;
                      default   : a = 0;
                                  break;
                      };
                      break;
      };
    };
  return tecla;
}
