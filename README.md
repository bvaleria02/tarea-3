<h1><b> Busca Palabras </b></h1>
<i>(Programación de Computadores - Tarea 3)</i>
<p></p>
<p><b>"Busca Palabras"</b> es una aplicación escrita en C, cuyo propósito es identificar, ordenar y analizar secuencias de caracteres, a modo de pañabras, para luego según la entrada del usuario, arrojar por pantalla aquellas que correspondan con los criterios de letras contenidas y longitud.
  
 Actualmente posee una interfaz que es posible visualizar en cualquier terminal, ya que interactúa directamente con esta, evitando el uso de interfaces gráficas que no sean esta. Por esta misma razón, el interactuar con la aplicación se hace por medio del teclado, y por pantalla es posible ver los comandos necesarios para ejecutar una acción, los cuales son:</p>
<ul>
  <li><kbd>B:</kbd> Inicia una nueva búsqeuda de palabras</li>
  <li><kbd>X:</kbd> Termina la ejecución del programa</li>
  <li><kbd>E:</kbd> Exporta a un archivo de texto los resultados</li>
   <li><kbd>Enter:</kbd> Ingresa los valores que se le piden al usuario</li>
  <li><kbd>W o Up:</kbd> Mueve uno hacia adelante los resultados, o uno hacia arriba los menú</li>
  <li><kbd>S o Down:</kbd> Mueve uno hacia atrás los resultados, o uno hacia abajo los menú</li>
  <li><kbd>A o Left:</kbd> Mueve de a 20 la lista de resultados hacia atrás</li>
  <li><kbd>D o Right:</kbd> Mueve de a 20 la lista de resultados hacia adelante</li>
</ul>

## Instalación

Hay dos versiones del programa, siendo la de Linux la que está soportada al 100%, mientras que la de Windows se ha tomado desde una versión anterior del programa, además deaún requerir cierto grado de pruebas antes de decir que está oprativa.

<h3>Linux</h3> <font color="green">Version 0.2.0 Estable</font>

```bash
cd install-linux
make
```

<h3>Windows</h3> <font color="yellow">Version 0.1.2 Beta</font>

```batch
cd install-windows
.\make.bat
```

## Uso

Al iniciar la aplicación se encontrara con un cuadro de texto que pedirá que se introduzcan las letras que utilizara el buscador
Luego pedirá la longitud deseada, y si se quiere filtrar por palabras mas pequeñas, iguales o mas grandes-
Tras esperar un poco de tiempo, el programa arrojará los resultados por pantalla, los cuales el usuario puede navegar con el teclado usando la teclas <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> o <kbd>Arriba</kbd> <kbd>Izquierda</kbd> <kbd>Abajo</kbd> <kbd>Derecha</kbd>.

Los resultados pueden ser exportados a un archivo de texto plano, presionando <kbd>E</kbd> e introduciendo el nombre del archivo.

Si quiere iniciar una nueva búsqueda, puede presionar <kbd>B</kbd>, o si quiere detener la ejecución, solo presione <kbd>X</kbd>.

La base de datos del programa (las palabras cuales trabaja este) se encuentran en un archivo en ./archivos-txt/palabras.txt . Puede alterar a voluntad el contenido de este fichero, pero debe tener la precaución que en aquella carpeta no se encuentren otros archivos como indice.txt o separador.txt.

Una vez modificado, solo ejecute nuevamente el programa y este generará los cálculos que ayudarán a hacer la búsqueda más rápida.
## Créditos

Benjamín Valeria - b.valeria02@ufromail.cl

Diego Jerez - d.jerez04@ufromail.cl
