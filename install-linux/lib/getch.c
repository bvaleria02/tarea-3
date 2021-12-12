#include <termios.h>        // Utilizada para poner la terminal en un cierto modo para leer pulsaciones del teclado
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla
#include "libSeparador.h"
#include <stdio.h>          // Librería estándar de entrada y salida


static struct termios old, current;                       // usado para obtener las teclas pulsadas

char getch(void){                         // Lee la entrada de teclado sin necesidad de pulsar enter
  char ch;
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  current.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &current);
  ch = getchar();
  tcsetattr(0, TCSANOW, &old);
  return ch;
}
