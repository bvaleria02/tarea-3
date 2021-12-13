/* Universidad de La Frontera
 * Departamento de Ingeniería Eléctrica
 *
 * ICC-202 PROGRAMACION DE COMPUTADORES
 *
 * Tarea 2
 *
 * Autores: Diego Jerez . (d.jerez04@ufromail.cl)
 *          Benjamín Valeria. (b,valeria02@ufromail.cl)
 *
 * Fecha:       Noviembre 14. 2021
 *
 *   Este programa busca palabras que contengan tanto una secuencia de letras introducidas por el usuario, como una longitud, que puede tener ciertas reglas como ser de un cierto largo, inferior, superior, etc.
 */




// Definir variables utilizadas a lo largo del código


#include <stdio.h>          // Librería estándar de entrada y salida
#include <string.h>         // Utilizada para la función strlen, además de manejo de arreglos
#include <conio.h>        // Utilizada para poner la terminal en un cierto modo para leer pulsaciones del teclado
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla
#include "lib/libSeparador.h"

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

void exportarResultados();

int main(){
  FILE *palabras = fopen("archivos-txt/palabras.txt", "rb");             // Aquí están las palabras almacenadas como texto
  FILE *indice = fopen("archivos-txt/indice.txt", "rb+");                // Aquí solo están las direcciones de las palabras
  FILE *separador = fopen("archivos-txt/separador.txt", "rb+");          // Aquí están separadas y distribuidas por letra
  FILE *contenedor = fopen("archivos-txt/.contenedor.txt", "wb+");       // Archivo temporal donde serán guardadas las palabras
  FILE *escritura = fopen("si.txt", "wb+");
  unsigned char Letras[12];                                 // Almacena las letras ingresadas por el usuario
  unsigned int direcciones[12];                             // Direccion desde donde empezar a buscar
  unsigned int limSuperior[12];                             // Y hasta donde detenerse
  int a = 0;                                                // Uso interno para bucles
  int b = 0;
  int d = 0;
  long int e = 0;
  int longitud[2];                                          // 0: cantidad de letras a buscar por palabra // 1: cantidad de letras ingresadas
  int regla = 0;                                            // Utilizado para seleccionar un filtro por longitud
  unsigned char tecla = 0;                                  // entrada de teclado
  int posicionPantalla = 0;                                 // para la impresión de los resultados, indica desde donde imprimir
  int resultados = 0;                                       // Total de resultados obtenidos

                        // --------------- Precálculos  -------------------- //

  system("cls");
  if (palabras == NULL){
    cuadrado("   EL archivo con palabras no ha sido encontrado   ", 3, 0);
    gotoxy(24, 14);
    printf("\033[0;31m¡Error Crítico!\033[0;0m");
    gotoxy(19, 23);
    printf("La ejeción ha sido terminada");
    gotoxy(16, 24);
    printf("Presione una tecla para finalizar");
    getch();
    system("cls");
    exit(0);
  };
                                                  // comentar para no generar archivos
  if (indice == NULL){
    indice = fopen("archivos-txt/indice.txt", "wb+");
    cuadrado("Indice no encontrado", 3, 0);
    printf("%d", d);
    gotoxy(19, 23);
    printf("Generando archivo, espere un momento");
    getch();
    fseek(palabras, 0l, SEEK_SET);
    //fseek(indice, 0l, SEEK_SET);
    generarArchivoPalabras(palabras, indice);
  };
  if (separador == NULL){
    separador = fopen("archivos-txt/separador.txt", "wb+");
    cuadrado("Separador no encontrado", 3, 0);
    getch();
    fseek(palabras, 0l, SEEK_SET);
    fseek(indice, 0l, SEEK_SET);
    fseek(separador, 0l, SEEK_SET);
    separarPalabrasPorLetra(palabras, indice, separador);
  };
  d = 0;


                        // --------------- Inicio del programa  -------------------- //

  imprimirPantalla(0, Letras, 0, 0);                        // Pantalla inicial
  tecla = teclado(0);
  if (tecla == 0xFF){                                       // Detecta si se ha presionado una tecla y qué hacer
    exit(0);
  } else if (tecla == 0xFD){
    cuadrado("            Créditos:            ", 6, 4);
    getch();
  };
  while (d == 0){                                           // bucle principal
    a = 0;
    gotoxy(3, 10);  printf("\033[0;32mEsperando letras...   \033[0;0m"); gotoxy(3, 11);  printf("\033[0;32m                                       \033[0;0m");
    while (a != 1){
      cuadrado("  Ingrese las letras a comparar  ", 4, 1);
      if (a == 2){                                                                // Esto aparece si el usuario ha puesto menos de dos letras
        gotoxy(15, 20);
        printf("│ \033[0;31mDebe ingresar al menos dos letras\033[0;0m │");
        gotoxy(15, 21);
        printf("│                                   │");
        gotoxy(15, 22);
        printf("└───────────────────────────────────┘");
        gotoxy(17, 18);
      };
      entradaLetras(Letras);
      longitud[1] = __stringlength(Letras, 0);
      getch();
      if (longitud[1] < 2){
          a = 2;
      } else {
        a = 1;
      };
    };
  a = 0;                                                                            // Retorna a 0 la variable a, usada para bucles
  imprimirPantalla(1, Letras, 0, 0);
  cuadrado("  Ingrese la cantidad de letras a filtrar  ", 3, 1);                    // Este codigo de acá solo resimprime la pantalla y crea cuadrados con texto o elecciones para ingreesar
  scanf("%d", &longitud[0]);
  longitud[0]++;
  imprimirPantalla(2, Letras, longitud, 0);
  cuadrado(" Ingrese la regla para buscar ", 7, 3);
  regla = multipleEleccion(7);                                                      // Abre un diálogo de elección múltiple y se encarga de leer la entrada
  imprimirPantalla(3, Letras, longitud, regla);
  limites(Letras, direcciones, limSuperior, separador);                             // Calcula, con las letras dadas, límite inferior y superior de cada una de ellas
  delay(20000);                                                                     // Retardo, utilizado solo para efectos visuales
  primeraBusqueda(direcciones, limSuperior, regla, longitud[0], separador, contenedor, palabras);       // Busca entre las primeras dos letras, y las similitudes las pone en un archivo
  if (longitud[1] > 2){                                                                                 // Solo se usa si hay más de dos letras, de otra forma sigue adelante
  for (int i = 1; i < longitud[1] - 1; i++) {
    busquedasPosteriores(i, direcciones, limSuperior, separador, contenedor, Letras);                   // Compara si es que en el archivo creado, las palabras coinciden con el resto de letras, descartando las que no
  };
};

  //segundaPasada(palabras, contenedor, Letras, longitud[1]);
  resultados = totalResultados(contenedor);                                         // Caclcula el total de resutltados obtenidos, leyendo del archivo

  while (a == 0){                                                                   // Bucle, ya que aquí el usuario puede moverse y desplazarse por los resultados
    imprimirPantalla(4, Letras, longitud, regla);
    imprimirResultados(posicionPantalla, contenedor, palabras, resultados);         // Imprime los 20 resultado a partir de una posicion
    tecla = teclado(2);                                                             // Lee el teclado
    switch (tecla) {
      case 1    : if (posicionPantalla == resultados){                              // Aumenta en 1 la posicion. Si está en pantalla el máximo, se detiene.
                    posicionPantalla = resultados;
                  } else if (resultados < 20){
                    posicionPantalla = 0;
                  } else {
                    posicionPantalla++;
                  };
                  break;
      case 2    : if (posicionPantalla == 0){                                       // Disminuye en 1 la posicion. Si está en pantalla el mínimo, se detiene.
                    posicionPantalla = 0;
                  } else if (resultados < 20){
                    posicionPantalla = 0;
                  } else {
                    posicionPantalla--;
                  };
                  break;
      case 3    : if (posicionPantalla < 20){                                       // Aumenta en 20 la posicion. Si están en pantalla el máximo, se detiene.
                    posicionPantalla = 0;
                  } else if (resultados < 20){
                    posicionPantalla = 0;
                  } else {
                    posicionPantalla = posicionPantalla - 20;
                  };
                  break;
      case 4    : if (posicionPantalla > resultados - 20){                        // Disminuye en 20 la posicion. Si está en pantalla el mínimo, se detiene.
                    posicionPantalla = resultados - 20;
                  } else if (resultados < 20){
                    posicionPantalla = 0;
                  } else {
                    posicionPantalla = posicionPantalla + 20;
                  };
                  break;
      case 5    : cuadrado("¿Desea exportar los resultados a un archivo?", 4, 2);
                  tecla = getch() & 0xDF;
                  if (tecla != 'S' && tecla != 'Y') break;
                  imprimirPantalla(4, Letras, longitud, regla);
                  imprimirResultados(posicionPantalla, contenedor, palabras, resultados);         // Imprime los 20 resultado a partir de una posicion
                  cuadrado("    Ingrese el nombre del archivo    ", 3, 1);
                  exportarResultados(contenedor, palabras);
                  cuadrado("Archivo exportado", 3, 0);
                  getch();
                  a = 0;
                  break;
      case 0xFD : cuadrado("            Créditos:            ", 6, 4);               // Muestra unos créditos, uwu
                  getch();
                  break;
      case 0xFE : a = 1;                                                             // Empieza desde nuevo la búsqueda
                  break;
      case 0xFF : gotoxy(1, 36);                                                     // Detiene la ejecución del programa
                  exit(0);
                  break;
    };
  };
  };
  gotoxy(1, 32);                                                                      // Mueve el cursor al fondo de la pantalla
  return 0;
}


void exportarResultados(FILE *contenedor, FILE *palabras){
  unsigned char nombreArchivo[128];
  unsigned char buffer_ch[24];
  int a = 0;
  int largo = 0;
  int direccion[1];
  char nl_char = '\n';

  scanf("%128s", nombreArchivo);
  FILE *escritura = fopen(nombreArchivo, "wb+");
  fseek(contenedor, 0, SEEK_SET);
  fseek(escritura, 0, SEEK_SET);
  system("cls");
  while(a == 0){
    fread(direccion, sizeof(int), 1, contenedor);
    if (direccion[0] == 0xFFFFFFFF) break;
    fseek(palabras, direccion[0], SEEK_SET);
    fread(buffer_ch, sizeof(unsigned char), 24, palabras);
    // printf("%4x\n", direccion[0]);
    largo = __stringlength(buffer_ch, 2);
    // printf(" %d\n", b);
    fwrite(buffer_ch, sizeof(unsigned char), largo, escritura);
    fwrite(&nl_char,sizeof(char),1,escritura);
  };
  fclose(escritura);
}
