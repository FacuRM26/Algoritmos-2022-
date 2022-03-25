#>>Caso 2
##>>Fabricio Ríos Montero

Los tiempos no se tomaron los dados por el clock ya que da numeros algo confusos, por lo que se uso el tiempo de ejecucion total que da el programa al 
terminar, el clock se puso por un tema estetico


Quicksort Logaritmico:


Para comprobarlo se insertaran valores de 200 mil en 200 mil empenzando en 200 mil.


Se llenara el array con elementos aleatorios y se tomara como pivote el primer elemento del arreglo.


Resultados del tiempo segun cantidad de elementos en el arreglo:
t1=200.000=0.923
t2=400.000=1.044
t3=600.000=1.383
t4=800.000=1.607
t5=1.000.000=1.069


Ahora remplzamos la n con la cantidad de valores en el array en log(n)=
l1=5.301
l2=5.602
l3=5.778
l4=5.903
l5=6
Ahora sacamos la diferencia que hay entre los valores:
t2/t1=1.131
t3/t2=1.325
t4/t3=1.161
t5/t4=1.069

l2/l1=1.056
l3/l2=1.031
l4/l3=1.021
l5/l4=1.016

Como podemos ver tienen un comportamiento similar, cada vez hay menos diferencia pero es un cambio minimo, igual como vemos en los tiempos apesar de 
que entre cada uno hay 200mil elementos de más la diferencia de es muy pequeña, por lo cual la curva de crecimiento es muy baja tal cual seria el 
crecimiento de una funcion logaritmica. Podemos ver mas claro esto en la figura 1 que esta en el repositorio. El quicksort cuando el array tiene elementos
random tendera a ser logaritmico aunque esto tiene muchos factores, como el pivote, y el ordenamiento que tienen los elementos, por esto aveces el coste
puede ser mayor que en otros.


Quicksort Cuadratico
Para comprobarlo se probaran agragar valores de 5 mil en 5 mil empenzando en 10 mil al arreglo.
Se llenara el array con valores ordenados y pivote se tomara el primer elmento del arreglo ya que esto empeora el algoritmo
Resultados del tiempo segun cantidad de elementos en el arreglo:
t1=10.000=1.419
t2=15.000=2.195
t3=20.000=3.694
t4=25.000=4.639
t5=30.000=6.543
t6=35.000=9.421
t7=40.000=11.154

Ahora remplzamos la n con la cantidad de valores en el array en (n^2)=
l1=100.000
l2=225.000
l3=400.000
l4=625.000
l5=900.000
l6=1.225.000
l7=1.600.000
Ahora sacamos la diferencia que hay entre los valores:
t2/t1=1.547
t3/t2=1.683
t4/t3=1.256
t5/t4=1.410
t6/t5=1.389
t7/t6=1.184

l2/l1=2.25
l3/l2=1.778
l4/l3=1.562
l5/l4=1.44
t6/t5=1.361
t7/t6=1.306
En este podemos ver que los tiempos de ejecuccion crecen de manera muy acelarada, a pesar que solo aumentamos 5000 cada vez, entre la diferencia.
La diferencia que entre los tiempos tambien es mas pronunciada y es muy similar a la funcion cuadratica a cuanto su avance. Por esto se puede 
confirmar que es cuadratica debido a su rapido crecicmiento a pesar de la poca diferencia de elementos. Esto lo podemos a preciar en la figura 2.
El algoritmo quicksort tiene dificultades cuando el array esta ordenado, ademas entre mas a los extremos  este el pivote mas carga tendra uno de los 
lados por lo cual al escoger el primero elemento en una lista ordenada seria el extremo de ese array lo cual empeora aun mas el algoritmo llevandolo a
ser cuadratico.
 


 Insertion sort
lineal
Para comprobarlo se agragaran valores de 100 mil en 100 mil empenzando en 100 mil al arreglo.
Se llenara el array con valores ordenados de 0 hasta n , donde n es el tamaño del arreglo.
Resultados del tiempo segun cantidad de elementos en el arreglo:
t1=100.000=0.882
t2=200.000=0.946
t3=300.000=1.004
t4=400.000=1.125
t5=500.000=1.062

Ahora remplzamos la n con la cantidad de valores en el array en (n)=
l1=100.000
l2=200.000
l3=300.000
l4=400.000
l5=500.000

Ahora sacamos la diferencia que hay entre los valores:
t2/t1=1.073
t3/t2=1.061
t4/t3=1.121
t5/t4=0.944

l2/l1=2.
l3/l2=1.5
l4/l3=1.334
l5/l4=1.25

Como podemos ver el crecimiento de los tiempos  no varia mucho entre mas elementos es un crecimiento lento aunque mayor que el de un logarimico,tambien
con la diferencias entre los valores podemos ver con comportamiento muy similar exepto en la primer comparacion.Esto se puede apreciar tambien la 
figura 3 donde tienen un comportamiento muy similar. Por lo cual por su comportamiento similar y su crecimiento no  tan grande podemos decir que es lineal



Cuadratico
Para comprobarlo se agragaran valores de 20 mil en 20 mil empenzando en 20 mil al arreglo.
Se llenara el array con valores ordenados inversamente de 0 hasta n , donde n es el tamaño del arreglo.
Resultados del tiempo segun cantidad de elementos en el arreglo:
t1=20.000=1.586
t2=40.000=4.366
t3=60.000=9.776
t4=80.000=15.926
t5=100.000=27.086

Ahora remplzamos la n con la cantidad de valores en el array en (n)=
l1=400.000
l2=1.600.000
l3=3.600.000
l4=6.400.000
l5=10.000.000

Ahora sacamos la diferencia que hay entre los valores:
t2/t1=2.75
t3/t2=2.239
t4/t3=1.629
t5/t4=1.701

l2/l1=4
l3/l2=2.25
l4/l3=1.778
l5/l4=1.563

En esta ocasion podemos ver el crecimiento bastante grande en los tiempos a pesar de que solo sumamos 20 mil, y la diferencia entre uno y otro cada vez 
mayor.Tambien podemos ver que entre la linea cuadratica y los valores que obtuvimos tienen un comportamiento muy similar,esto se puede ver en la figura 4
este comportamiento.Por este crecimiento tan elevado y su similitud con el comportamiento de la funcion cuadratica podemos estar seguros que tiene ese coste.  

Nota:Para el resto de pruebas del InsertionSort ,descomentar partes del codigo debido que no me deja crear 2 veces un arreglo,por alguna razon que desconozco.

Pivote aleatorio y fijo
El pivote va a afectar segun cada ocasion, un pivote aleatorio normalmente dara un algoritmo cuadratico, pero en ciertas ocasiones dara logaritmico, todo depende 
de que tan al extremo del arreglo este el numero, si el pivote da un 100 y los elementos van de uno a un millon sera poco eficiente, en cambio si en el mismo contxto 
nos da 500 mil el algoritmo sera muy eficiente.
Un pivote fijo servira si sabemos bien el rango que tomaran los numeros para asi buscar que se lo más cercano al centro, asi la lista se dividira de la mejor manera.
Por lo que podemos concluir que esto depende de que tanto se conozca de la lista y de la suerte del numero aleatorio que obtengamos  



Freetext
lineal
Para comprobarlo se utilizara el algoritmo de  Boyer Moore Horspool ,se creo una combinacion de textos lo que hace un texto de 10 megas el cual se
leera y luego se buscara las palabras que mas se repiten en el texto.
Resultados del tiempo segun la busqueda:
t1=4310=1.483         palabra=uno
t2=200.000=1.362      palabra=ellos
t3=300.000=1.479      palabra=the
t4=400.000=1.739      palabra=los
t5=67694=1.639        palabra=no

Ahora remplzamos la n con la cantidad de valores en el array en (n)donde n son las veces que aparece en el texto
l1=4.310
l2=16.410
l3=43.278
l4=49252
l5=67.694

Ahora sacamos la diferencia que hay entre los valores:
t2/t1=0.984
t3/t2=1.086
t4/t3=1.176
t5/t4=0.984

l2/l1=3.807
l3/l2=2.637
l4/l3=1.380
l5/l4=1.374

Lastimosamente los ejemplos entre si unos tienen mayor cantidad de apariciones que el otro por lo cual las comparaciones son algo extrañas
pero igual podemos sacar una conclusion con los resultados.Igual como podemos ver la similitud en el comportamiento es similar aunque por los 
resultados que obtuvimos el tiempo es un poco distinto a la lineal pero entra en el rango de error. Esto lo podemos ver mas claro en la figura 5.Tambien podemos ver que la diferencia de tiempo 
entre las busquedas es minima, ya que su crecimiento es moderado al ser lineal, por todo esto podemos concluir que efectivamente tiene un O(n).
