all:
	echo Tarea 1/4: Crear objetos
	gcc -c lib/busquedasPosteriores.c
	gcc -c lib/cuadrado.c
	gcc -c lib/delay.c
	gcc -c lib/entradaLetras.c
	gcc -c lib/filtroLongitud.c
	gcc -c lib/generarArchivoPalabras.c
	gcc -c lib/getch.c
	gcc -c lib/imprimirPantalla.c
	gcc -c lib/imprimirResultados.c
	gcc -c lib/limites.c
	gcc -c lib/multipleEleccion.c
	gcc -c lib/primeraBusqueda.c
	gcc -c lib/segundaPasada.c
	gcc -c lib/separarPalabrasPorLetra.c
	gcc -c lib/stringLength.c
	gcc -c lib/teclado.c
	gcc -c lib/totalResultados.c
	gcc -c separador.c
	echo Objetos creados
	echo Tarea 2/4: Compilar programa
	gcc -o main busquedasPosteriores.o cuadrado.o delay.o entradaLetras.o filtroLongitud.o generarArchivoPalabras.o getch.o imprimirPantalla.o imprimirResultados.o limites.o multipleEleccion.o primeraBusqueda.o segundaPasada.o separarPalabrasPorLetra.o stringLength.o teclado.o totalResultados.o separador.o
	echo Compilacion terminada
	echo Tarea 3/4: Mover objetos a /bin
	mv *.o bin/
	mv main ../
	echo Traslacion efectuada
	echo Tarea 4/4: Finalizar

init:
	rm -r bin
	rm ../main
	mkdir bin
	echo Inicialización finalizada
