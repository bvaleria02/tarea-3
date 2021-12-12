#include "libSeparador.h"
#include <stdio.h>
#include <stdlib.h>


void entradaLetras(unsigned char Letras[12]){                                   // Recibe las letras, y las ordena, separando los espacios
  char buffer_1[25];
  int a = 0;
  int b = 0;
  for (int i = 0; i < 12; i++) {                                                // Inicializa todas las letras con un caracter de espacio
    Letras[i] = 0xFF;
  };
  printf("\033[0;30;47m ");                                                     // Pone el color en blanco en el fondo y letra en negro
  scanf("%[^\n]s", buffer_1);                                                   // Guarda la entrada. Los espacios son incluidos en el string
  for (int i = 0; i < 25; i++) {                                                // limpia todo lo que es sobrante después del término
    if (buffer_1[i] == '\0'){
      b = 1;
    };
    switch (b){
        case 0  : if(buffer_1[i] != 0x20){
                    Letras[a] = buffer_1[i] & 0xDF;
                    a++;
                    };
                  break;
        case 1  : buffer_1[i] = 0xFF;
                  break;

    };
  };
  printf("\033[0;0;0m ");                                                       // Devuelve los colores a la normalidad
}
