#include "libSeparador.h"
#include <stdio.h>

void limites (unsigned char Letras[12], int direcciones[12], int limSuperior[12], FILE *separador){   // Calcula los límites para la búsqueda
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
