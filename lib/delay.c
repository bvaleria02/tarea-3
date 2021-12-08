#include "libSeparador.h"

void delay(int time){                     // Genera un pequeño retardo, usado para fines de testeo
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
