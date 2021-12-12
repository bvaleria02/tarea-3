#include <stdio.h>

//  Funciones relacionadas con backend del programa

    void segundaPasada(FILE *palabras, FILE *contenedor, unsigned char letras[6], int largo);
    int __stringlength(char *text_string, int modo);
    void delay(int time);
    char getch(void);
    void limites(unsigned char Letras[12], int direcciones[12], int limSuperior[12], FILE *separador);
    void primeraBusqueda(int direcciones[12], int limSuperior[12], int regla, int longitud, FILE *separador, FILE *contenedor, FILE *palabras);
    int filtroLongitud(FILE *palabras, int regla, int longitud, int locacion, FILE *separador);
    void busquedasPosteriores(int j, int direcciones[12], int limSuperior[12], FILE *separador, FILE *contenedor, unsigned char Letras[12]);
    int totalResultados(FILE *contenedor);
    void generarArchivoPalabras(FILE *palabras, FILE *indice);
    void separarPalabrasPorLetra(FILE *palabras, FILE *indice, FILE *separador);

// Funciones relacionadas al frontend del programa

    void imprimirPantalla(int estado, unsigned char Letras[12], int longitud[2], int regla);
    void imprimirResultados(int posicionPantalla, FILE *contenedor, FILE *palabras, int resultados);
    void cuadrado(char *texto, int alto, int modo);
    void entradaLetras(unsigned char Letras[12]);
    int multipleEleccion(int cantidad);
    char teclado(int modo);

// Fin  de declarar funciones
