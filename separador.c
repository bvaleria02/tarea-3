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
#include <termios.h>        // Utilizada para poner la terminal en un cierto modo para leer pulsaciones del teclado
#include <stdlib.h>         // Librería estándar, utilizada para limpiar la pantalla

#define clear() printf("\033[H\033[J")                    // Limpia la pantalla
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))       // Va a una cierta parte de la pantalla

static struct termios old, current;                       // usado para obtener las teclas pulsadas

static char* eleccion[]  = {"Menor que          ", "Igual que          ", "Mayor que          ", "Menor o igual que  ", "Mayor o igual que  ", "Distinto que       ", "Todos              "};

//  Funciones relacionadas con backend del programa

void segundaPasada();
int __stringlenght();
void delay();
char getch();
void limites();
void primeraBusqueda();
int filtroLongitud();
void busquedasPosteriores();
int totalResultados();
void generarArchivoPalabras();
void separarPalabrasPorLetra();

// Funciones relacionadas al frontend del programa

void imprimirPantalla();
void imprimirResultados();
void cuadrado();
void entradaLetras();
int multipleEleccion();
char teclado();

// Fin  de declarar funciones

int main(){
  FILE *palabras = fopen("palabras.txt", "rb");             // Aquí están las palabras almacenadas como texto
  FILE *indice = fopen("indice.txt", "rb+");                // Aquí solo están las direcciones de las palabras
  FILE *separador = fopen("separador.txt", "rb+");          // Aquí están separadas y distribuidas por letra
  FILE *contenedor = fopen(".contenedor.txt", "wb+");       // Archivo temporal donde serán guardadas las palabras
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

  clear();
  if (palabras == NULL){
    cuadrado("   EL archivo con palabras no ha sido encontrado   ", 3, 0);
    gotoxy(24, 14);
    printf("\033[0;31m¡Error Crítico!\033[0;0m");
    gotoxy(19, 23);
    printf("La ejeción ha sido terminada");
    gotoxy(16, 24);
    printf("Presione una tecla para finalizar");
    getch();
    clear();
    exit(0);
  };
  /*                                                      // Descomentar para generar archivos
  if (indice == NULL){
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
    cuadrado("Separador no encontrado", 3, 0);
    getch();
    fseek(palabras, 0l, SEEK_SET);
    fseek(indice, 0l, SEEK_SET);
    fseek(separador, 0l, SEEK_SET);
    separarPalabrasPorLetra(palabras, indice, separador);
  };*/
  d = 0;


                        // --------------- Inicio del programa  -------------------- //

  imprimirPantalla(0, Letras, 0, 0);                        // Pantalla inicial
  tecla = teclado(0);
  if (tecla == 0xFF){                                       // Detecta si se ha presionado una tecla y qué hacer
    exit(0);
  } else if (tecla == 0xFD){
    cuadrado("            Creditos:            ", 6, 4);
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
      longitud[1] = __stringlenght(Letras);
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
      case 0xFD : cuadrado("            Creditos:            ", 6, 4);               // Muestra unos créditos, uwu
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


void imprimirPantalla (int estado, unsigned char Letras[12], int longitud[2], int regla){       // Refresca la pantalla. Disponde de distintos modos que cambian ligeramente los mensajes mostrados
  clear();
  printf("╔════════════════════ Busca Palabras v0.1 ════════════════════╗ ");                   // Crea el marco
  for (int i = 0; i < 7; i++) {
    printf("\n║                                                             ║");
  };
  printf("\n╠═════════════════════════════════════════════════════════════╣");
  for (int i = 0; i < 2; i++) {
    printf("\n║                                                             ║");
  };
  printf("\n╠═════════════════════════════════════════════════════════════╣");
  for (int i = 0; i < 22; i++) {
    printf("\n║                                                             ║");
  };
  printf("\n╚═════════════════════════════════════════════════════════════╝ ");
  gotoxy(3, 2);
  printf("Letras  : ");                                                                         // Desde aquí, rellema con las etiquetas
  if (estado >= 1){
    for (int i = 0; i < 12; i++) {
      if (Letras[i] == 0xFF){
        i = 13;
      } else {
        printf("%c ", Letras[i]);
      };
    };
  };
  gotoxy(3, 3);
  if (estado >= 2){
    printf("Longitud: %.2d\t\tRegla: ", longitud[0]);
  } else {
    printf("Longitud:\t\tRegla: ");
  };
  if (estado >= 3){
    printf("%s", eleccion[regla]);
  };
  gotoxy(3, 5);
  printf("Comandos:");                                                                            // Imprime los comando con la letra destacada. Depende del estado los que pone
  if (estado > 0){
      gotoxy(3, 6);
      printf("\033[0;30;47mW:\033[0;0m Subir\t\t\033[0;30;47mS:\033[0;0m Bajar");
      gotoxy(3, 7);
      printf("\033[0;30;47mA:\033[0;0m Pag. Anterior\t\033[0;30;47mD:\033[0;0m Pag. Siguiente");
      switch (estado){                                                                            // Mensajes de la sección media
          case 1  : gotoxy(3, 10);
                    printf("\033[0;32mEsperando longitud...\033[0;0m");
                    break;
          case 2  : gotoxy(3, 10);
                    printf("\033[0;32mEsperando filtro...\033[0;0m");
                    break;
      };
    } else {
      gotoxy(3, 10);
      printf("\033[0;36mNo hay trabajo");
      gotoxy(3, 11);
      printf("\033[0;36mPresione alguna tecla para comenzar");
    };
  gotoxy(3, 8);
  printf("\033[0;30;47mB:\033[0;0m Búsqueda Nueva\t\033[0;30;47mX:\033[0;0m Salir");
  gotoxy(1, 32);
  printf("\033[0;0;0m");
}


void cuadrado(char *texto, int alto, int modo){                                 // Crea un cuadrado en el medio de la pantalla, encima de totalResultados
                                                                                /* Modos:
                                                                                      0: Mostrar solo texto
                                                                                      1: Texto y cuadro de entrada
                                                                                      2: Texto y elección sí/no
                                                                                      3: Texto y elección múltiple
                                                                                      4: Texto y créditos
                                                                                */
    int longitud = strlen(texto);                                               // Obtiene la longitud del texto, para calcular el tamaño del cuadro
    if (modo == 3){
        alto += 2;
    };
    int x = (32 - ((longitud + 2) >> 1));
    int y = (15 - (alto >> 1));
    gotoxy(x, y);                                                               // Imprime el borde exterior
    printf("┌");
    for (int i = 0; i < longitud + 2; i++) {
      printf("─");
    };
    printf("┐");
    for (int i = 0; i < 1; i++) {
      gotoxy(x, (y+i+1));
      printf("│");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("│");
    };

    gotoxy(x, y + 2);
    printf("│ %s │", texto);                                                    // Imprime el texto ingresado

    for (int i = 0; i < alto ; i++) {
      gotoxy(x, y + i + 3);
      printf("│");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("│");
    };
    gotoxy(x, y + alto + 3);
    printf("└");
    for (int i = 0; i < longitud + 2; i++) {
      printf("─");
    };
    printf("┘");
    switch(modo){                                                               // Rellena con diferentes cosas, dependiendo del modo
      case  0 : gotoxy(1, 32);
                break;
      case  1 : gotoxy(x+2, y + alto +1 );
                for (int i = 0; i < longitud - 1; i++) {
                  printf("\033[0;30;47m ");
                };
                printf("\033[0;0m ");
                gotoxy(x+3, y + alto +1 );
                break;
      case  2 : gotoxy(32 - (longitud >> 2) - 2, y + alto +1 );
                printf("[Sí]");
                gotoxy(32 + (longitud >> 2) + 2, y + alto +1 );
                printf("[No]");
                printf("\033[0;0m ");
                gotoxy(1, 32);
                break;
      case  3 : for (int i = 0; i < alto - 2; i++) {
                gotoxy(x+5, y + 4 + i);
                printf("%s", eleccion[i]);
                };
                break;
      case  4 : gotoxy(x+3, y + 4);
                printf("Diego Jerez");
                gotoxy(x+3, y + 5);
                printf("Benjamín Valeria");
                gotoxy(x+3, y + 7);
                printf("Presione una tecla para cerrar");
                break;
    };

}

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

int multipleEleccion(int cantidad){                                             // Gestiona las entradas de elecciones múltiples
  int posicion = 0;
  int c = 0;
  char tecla = 0;
  int x = 19;
  int y = 15;
  getch();                                                                      // Limpieza de la parte de los controles
  gotoxy(3, 7);
  printf("                                        ");
  gotoxy(3, 8);
  printf("                                        ");
  gotoxy(3, 7);
  printf("\033[0;30;47mENTER:\033[0;0m Aceptar");
  while (c == 0){
    for (int i = 0; i < cantidad; i++) {                                        // Limpia la entrada, para después resaltar
      gotoxy(x, y + i);
      printf("\033[0;0;0m  %s", eleccion[i]);
    }
    gotoxy(x, y + posicion);                                                    // Resalta la opción elegida
    printf("\033[0;30;47m» %s", eleccion[posicion]);
    gotoxy(1, 32);
    tecla = teclado(1);                                                         // Lee el teclado, para irse hacia arriba o abajo
    switch(tecla){
      case  0x1 : if (posicion == 0){
                      posicion = cantidad - 1;
                    } else {
                      posicion--;
                    };
                    break;
      case  0x2 :  if (posicion == cantidad - 1){
                      posicion = 0;
                    } else {
                      posicion++;
                    };
                    break;
      case  0x7F :  c = 1;
                    break;
    };
  };
  printf("\033[0;0;0m");                                                        // Devuelve la terminal a la normalidad
  return posicion;
}

char teclado (int modo){                                                        // Se encarga de leer el teclado, y devolver un número dependiendo de la tecla presionada. Posse varios modos, además
  unsigned char tecla = 0;
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
                      case  0xA : tecla = 0x7F;
                                  a = 1;
                                  break;
                      case  'X' : tecla = 0xFF;
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
      };
    };
  return tecla;
}


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

void primeraBusqueda (int direcciones[12], int limSuperior[12], int regla, int longitud, FILE *separador, FILE *contenedor, FILE *palabras){      // compara entre las dos primeras letras las similitudes
    int posicion[2] = {0, 0};
    int punteroLetra[2];
    int a[1] = {0};
    int filtro = 0;
    fseek(contenedor, 0, SEEK_SET);
    while (direcciones[0] + (posicion[0] << 2) <= limSuperior[0]){
        fseek(separador, direcciones[0] + (posicion[0] << 2), SEEK_SET);                                                                          // lee desde el archivos los punteros de las palabras (precalculados anteriormente)
        fread(a, sizeof(int),1,separador);
        punteroLetra[0] = a[0];
        fseek(separador, direcciones[1] + (posicion[1] << 2), SEEK_SET);
        fread(a, sizeof(int),1,separador);
        punteroLetra[1] = a[0];
        if (punteroLetra[0] == punteroLetra[1]){                                                                                                  // Solo en el caso de similitudes, las escribe en el archivo
            filtro = filtroLongitud(palabras, regla, longitud, (direcciones[0] + (posicion[0] << 2)), separador);
            if (filtro == 1){
              fwrite(punteroLetra, sizeof(int),1,contenedor);
            };
            posicion[0]++;
            posicion[1]++;

        } else if (punteroLetra[0] > punteroLetra[1]){
            posicion[1]++;
        } else if (punteroLetra[0] < punteroLetra[1]){
            posicion[0]++;
        };
      };
    a[0] = 0xFFFFFFFF;                                                                                                                            // Escribe un dígito finalizador
    fwrite(a, sizeof(int),1,contenedor);
}

void busquedasPosteriores (int j, int direcciones[12], int limSuperior[12], FILE *separador, FILE *contenedor, unsigned char Letras[12]){        // Para la segunda y tercera letra, y después
    int posicion[2] = {0, 0};
    int punteroLetra[2];
    int a[1] = {0};
    int b = 0;
    int c = 0;
    int noIgual[1] = {0xFFFFFFFE};
    fseek(contenedor, 0, SEEK_SET);
    while (c == 0){
        fseek(contenedor, (posicion[0] << 2), SEEK_SET);                                                                                          // Carga los punteros, uno del archivo de los resultados y el otro donde los punteros y las letras
        fread(a, sizeof(int),1,contenedor);
        punteroLetra[0] = a[0];
        fseek(separador, (direcciones[j + 1] + (posicion[1] << 2)), SEEK_SET);
        fread(a, sizeof(int),1,separador);
        punteroLetra[1] = a[0];
        //gotoxy(1, 33); printf("%.8x %.8x %.8x", posicion[0] << 2, punteroLetra[0], punteroLetra[1]);
        //printf("\n%c", Letras[j + 1]);
        if (punteroLetra[0] == 0xFFFFFFFF){                                                                                                       // Comparaciones y operaciones de búsqueda- SI llega al final, se detiene
          c = 1;
        } else if (punteroLetra[0] == punteroLetra[1]){
          //printf("aaaa %d", b);
          fseek(contenedor, (b << 2), SEEK_SET);
          fwrite(punteroLetra, sizeof(int),1,contenedor);
          posicion[0]++;
          //posicion[1] = 0;
          b++;
        } else if (limSuperior[j + 1] <= (direcciones[j+1] + (posicion[1] << 2))){
          /*fseek(contenedor, ((posicion[0]) << 2), SEEK_SET);
          fwrite(noIgual, sizeof(int),1,contenedor);*/
          posicion[0]++;
          posicion[1] = 0;
        /*} else if (punteroLetra[0] != punteroLetra[1]){
          posicion[1]++;
        };*/
      } else if (punteroLetra[0] > punteroLetra[1]){
            posicion[1]++;
      } else if (punteroLetra[0] < punteroLetra[1]){
            posicion[0]++;
      };
    };
    a[0] = 0xFFFFFFFF;
    //printf("\n%d %d", b, b << 2);
    fseek(contenedor, b << 2, SEEK_SET);
    fwrite(a, sizeof(int),1,contenedor);
}


void imprimirResultados (int posicionPantalla, FILE *contenedor, FILE *palabras, int resultados){                                     // Pone los 20 resultados seleccionados en la pantalla
    int puntero[1];
    unsigned char buffer_1[24];
    int a = 0;
    gotoxy(5, 10);
    printf("Resultados: %d", resultados);
    for (int i = 0; i < 20; i++) {
      fseek(contenedor, (posicionPantalla + i) << 2, SEEK_SET);                  // Lee el puntero desde el archivo
      fread(puntero, sizeof(int), 1, contenedor);
      if (puntero[0] == 0xFFFFFFFF){
        i = 20;
      } else {
      fseek(palabras, puntero[0], SEEK_SET);                                    // Almacena la palabra como tal para posteriormente trabajarla
      fread(buffer_1, sizeof(unsigned char), 24, palabras);
      a = 0;
      for (int j = 0; j < 24; j++) {                                            // Elimina todo lo que no sea de la palabra, para quitar la basura que pueda meterse
        if (a == 1){
          buffer_1[j] = 0x0;
        } else if (buffer_1[j] == 0xA){
          a = 1;
          buffer_1[j] = 0x0;
        };
      };
      gotoxy(5, 14 + i);                                                        // Imprime tanto el número como la palabra, una debajo de la anterior hasta llegar a la 20
      printf("%d\t%s", posicionPantalla + i, buffer_1);
      };
    };

}



void segundaPasada (FILE *palabras, FILE *contenedor, unsigned char letras[6], int largo){      // Código no utilizado y que data de una versión anterior del programa. La segunda pasada para verificar no es necesaria en el nuevo
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

int __stringlenght(char *text_string){                                          // strlen no sirve cuanndo no se trata del dígito particular, esto resuelve ese problema y da soporte para toda la sarta de cosas raras que hay en cuanto palabras
    int a = 0;
    unsigned char b = 0;
    for (int i = 0; i < 20; i++) {                                              // Carga la palabra, y si detecta un término, deja de contar
        b = text_string[i];
        if (b == 0x0A){
          i = 21;
        } else if (b == '\0'){
          i = 21;
        } else if (b == 0xFF){
          i = 21;
        } else {
          a++;
        };
    };
    return a;
}

int filtroLongitud (FILE *palabras, int regla, int longitud, int locacion, FILE *separador){   // Con el modo dado, este retorna un 1 si es correcta la longitud a los parámetros
  unsigned char buffer_1[20];
  int largo = 0;
  int a = 0;
  int desplazamiento[1];
  fseek(separador, locacion, SEEK_SET);                                                        // Lee la palabra para posteriormente calcular su longitud
  fread(desplazamiento, sizeof(int), 1, separador);
  locacion = desplazamiento[0];
  fseek(palabras, locacion, SEEK_SET);
  fread(buffer_1, sizeof(unsigned char), 19, palabras);
  largo = __stringlenght(buffer_1);
  switch (regla) {                                                                            // Dependiendo el modo, hará cierta clase de comparaciones
    case 0  : if (largo < longitud){                                                          // Menor que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 1  : if (largo == longitud){                                                         // Igual que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 2  : if (largo > longitud){                                                          // Mayor que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 3  : if (largo <= longitud){                                                         // Menor o igual que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 4  : if (largo >= longitud){                                                         // Mayor o igual que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 5  : if (largo != longitud){                                                         // Es distinto que
                a = 1;
              } else {
                a = 0;
              };
              break;
    case 6  : a = 1;                                                                          // Todo pasa por acá...
              break;
  };
  //printf("\n%d, %d, %d %d %s", regla, largo, longitud, a, buffer_1);
  return a;
}

int totalResultados (FILE *contenedor){                                                       // Calcula dónde está el final de los resultados, y lo devuelve
  int longitud = 0;
  int a = 0;
  int puntero[1];
  fseek(contenedor, 0, SEEK_SET);
  while (a == 0){
    fread(puntero, sizeof(int), 1, contenedor);                                               // Lee hasta que encuentra un 0xFFFFFFFF, si lo hay , se detiene
    if (puntero[0] == 0xFFFFFFFF){
      a = 1;
    } else {
      longitud++;
    };
  };
  return longitud;
}


/* Código legendado de los precálculos. Puede o no estar incluido*/


void generarArchivoPalabras(FILE *palabras, FILE *indice){
    long int largo = 0;
    char letra = 0;
    long int posicion = 0;
    fseek(palabras, 0L, SEEK_END);
    largo = ftell(palabras);
    fseek(palabras, 0l, SEEK_SET);
    posicion = 0;
    fwrite(&posicion, sizeof(int),1,indice);
    for (long int i = 0; i < largo; i++) {
      fread(&letra, sizeof(unsigned char),1,palabras);
      posicion = i + 1;
      if (letra == 0x0A){
        fwrite(&posicion, sizeof(int),1,indice);
      };
    };
}

void separarPalabrasPorLetra(FILE *palabras, FILE *indice, FILE *separador){
  long int largo = 0;
  long int direccion = 0;
  unsigned char letra = 0;
  int contador = 0;
  char palabra_con_letra[16];
  char letra_a_comprobar = 0;
  long int desplazamiento = 0x80;
  fseek(indice, 0L, SEEK_END);
  largo = ftell(indice);
  fseek(indice, 0l, SEEK_SET);
  for(char letra_a_comprobar = 'A'; letra_a_comprobar <= 'Z'; letra_a_comprobar++){
    desplazamiento = ftell(separador);
    if (letra_a_comprobar == 'A'){
      desplazamiento = 0x80;
    } else {
      desplazamiento += 4;
    };
    fseek(separador, (letra_a_comprobar - 0x41) << 2 , SEEK_SET);
    fwrite(&desplazamiento,sizeof(int),1,separador);
    fseek(separador, desplazamiento, SEEK_SET);
  for (int i = 0; i < (largo >> 2); i++) {
    fseek(indice, (i << 2), SEEK_SET);
    fread(&direccion, sizeof(int),1,indice);
    fseek(palabras, direccion, SEEK_SET);
    fread(&palabra_con_letra, sizeof(char),16,palabras);
    fseek(palabras, direccion, SEEK_SET);
    contador = 0;
    while(contador == 0){
      fread(&letra, sizeof(unsigned char),1,palabras);
      letra = letra & 0xDF;
      if (letra == 0x0A){
        contador = 1;
      } else if (letra == letra_a_comprobar) {
        fwrite(&direccion,sizeof(int),1,separador);
        //printf("%s\n", palabra_con_letra);
        contador = 1;
      } else if (letra == 0xC3){
        fread(&letra, sizeof(unsigned char),1,palabras);
        letra = letra & 0xDF;
        switch(letra){
            case  0xA1  : if (letra_a_comprobar == 'A'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xA9  : if (letra_a_comprobar == 'E'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xAD  : if (letra_a_comprobar == 'I'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xB3  : if (letra_a_comprobar == 'O'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
            case  0xBA  : if (letra_a_comprobar == 'U'){
                              fwrite(&direccion,sizeof(int),1,separador);
                              //printf("%s\n", palabra_con_letra);
                              contador = 1;
                            };
                          break;
        };
      } else {
        contador = 0;
      };
    };
  };
};
}


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


// Antiguo algoritmo

/*
  for (int i = 0; i < longitud[1]; i++) {
    fseek(separador, (Letras[i] - 0x41) << 2, SEEK_SET);
    fread(variabletemporal, sizeof(int),1,separador);
    Direcciones[i] = variabletemporal[0];
    fread(variabletemporal, sizeof(int),1,separador);
    Lim_superior[i] = variabletemporal[0];
  };
  for (int i = 0; i < (longitud[1] - 1); i++) {
    if (i == 0){
      while(a == 0){
        fseek(separador, Direcciones[1], SEEK_SET);
        fread(variabletemporal, sizeof(int),1,separador);
        variabletemporal[1] = variabletemporal[0];
        fseek(separador, Direcciones[0], SEEK_SET);
        fread(variabletemporal, sizeof(int),1,separador);
        //clear();
        //printf("Buscando %c y %c\nDirección 1: %.6X\t%.6X\nDirección 2: %.6X\t%.6X", Letras[0], Letras[1], Direcciones[0], variabletemporal[0], Direcciones[1], variabletemporal[1]);
        //delay(20000);
        if (Direcciones[0] == Lim_superior[0]){
            a = 1;
          } else if (Direcciones[1] == Lim_superior[1]){
            a = 1;
          } else if (variabletemporal[0] > variabletemporal[1]){
            Direcciones[1] = Direcciones[1] + 4;
          } else if (variabletemporal[0] < variabletemporal[1]){
            Direcciones[0] = Direcciones[0] + 4;
          } else if (variabletemporal[0] == variabletemporal[1]){
              fseek(palabras, variabletemporal[0], SEEK_SET);
              fread(impresion, sizeof(unsigned char),20,palabras);
              longitud[1] = __stringlenght(impresion);
              if (longitud[1] == longitud[0]){
                fwrite(&variabletemporal,sizeof(int),1,contenedor);
                };
              Direcciones[0] = Direcciones[0] + 4;
              Direcciones[1] = Direcciones[1] + 4;
          };
      };
      variabletemporal[0] = 0xFFFFFFFF;
      fwrite(&variabletemporal,sizeof(unsigned int),1,contenedor);
    } else {
      a = 0;
      b = 0;
      Direcciones[i] = 0;
      while(a == 0){
        fseek(separador, Direcciones[i+1], SEEK_SET);
        fread(variabletemporal, sizeof(unsigned int),1,separador);
        variabletemporal[1] = variabletemporal[0];
        fseek(contenedor, Direcciones[i], SEEK_SET);
        fread(variabletemporal, sizeof(unsigned int),1,contenedor);
        //clear();
        delay(0);
        //printf("\nBuscando %c y %c\nDirección %d: %.6X\t%.6X\nDirección %d: %.6X\t%.6X", Letras[i], Letras[i+1], i+1, Direcciones[i], variabletemporal[i], i+2, Direcciones[i+1], variabletemporal[i+1]);
        if (Direcciones[i+1] >= Lim_superior[i+1]){
            fseek(contenedor, (b + 1) << 2, SEEK_SET);
            variabletemporal[0] = 0xFFFFFFFF;
            fwrite(&variabletemporal,sizeof(unsigned int),1,contenedor);
            //printf("\n%d", b);
            a = 1;
          } else if (variabletemporal[0] == 0xFFFFFFFF){
            fseek(contenedor, (b + 1) << 2, SEEK_SET);
            variabletemporal[0] = 0xFFFFFFFF;
            fwrite(&variabletemporal,sizeof(unsigned int),1,contenedor);
            //printf("\n%d", b);
            a = 1;
          } else if (variabletemporal[0] == variabletemporal[1]){
              b++;
              fseek(contenedor, b << 2, SEEK_SET);
              variabletemporal[2] = variabletemporal[0];
              variabletemporal[0] = variabletemporal[1];
              fwrite(&variabletemporal,sizeof(int),1,contenedor);
              variabletemporal[0] = variabletemporal[2];
              Direcciones[i] = Direcciones[i] + 4;
              Direcciones[i+1] = Direcciones[i+1] + 4;
          } else if (variabletemporal[0] > variabletemporal[1]){
            Direcciones[i+1] = Direcciones[i+1] + 4;
          } else if (variabletemporal[0] < variabletemporal[1]){
            Direcciones[i] = Direcciones[i] + 4;
          } else {
            a = 1;
          };
      };
    };
  };
  a=0;
  b=0;
*/
