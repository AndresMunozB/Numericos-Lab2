# Reporte de Laboratorio 2 de Algoritmos Numericos

Una de las primera complicaciones para este laboratorio, fue debido a que muchos de los calculos realizados entregaban un valor inf, -inf, nan, -nan. Esto era debido a la precision del tipo de dato utilizado, que en ese entonces era "double". Para arreglar esto, se utilizo el tipo de dato "long double", el cual entrega una mayor presicion frente a los diferentes calculos realizados. Es decir, al cambiar el tipo de dato, los valores cercanos a 0 no se truncaban en 0, por lo tanto un ejemplo es que las divisiones con un número cercano a 0 ya no entrega los valores indeterminados anteriormente mencionados.

Luego de superar la barrera anterior, se presento otro problema dentro de los metodos de diferencias finitas y diferencias dividas. El problema era que los exponentes de los calculos eran demasido grandes, es decir, del orden de los 2100. Luego de analizar el problema se identifico que era debido a que la pitatoria para evaluar las interpolaciones, comenzaba a crecer mucho cuando los puntos eran demasiados (caso de h=0.5 ). Este problema fue arreglado cortanto el polinomio, es decir, al momento de evaluar el programa detecta cuales valores son los que aporta mayor ajuste a la curva, y el resto los desecha. En otras palabras, si el polinomio despues de interpolar resulta ser de grado 10, el programa podria solamente utilizar grado 3 ya que desde el grado 4 en adelante no aporta informacion un ajuste considerable.

Dentro de los resultados obtenidos, se pudo analizar que el mejor método de interpolacion dentro de los programados en este laboratorio, fue el de mínimos cuadrados. Pero si bien es el mas preciso, no es del todo bueno. Ya que al utilizar este método las curvas resultantes, es decir las curvas creadas por la evaluacion del polinomio interpolado, oscilan cerca de la función que se ha interpolado. Cabe recalcar que esta oscilacion se puede observar mas claramente para la primera funcion la cual es una funcion exponencial, mientras que la oscilacion es menor para la otra funcion, la cual no es exponencial. Esta oscilacion alrededor de la primera funcion se podria mejorar aun más siendo mas precisa y la forma de mejorar esto es cambiar la base con la cual se interpola la primera funcion, es decir, una base logaritmica y no una base cuadratica como se ha utilizado y programado en este laboratorio. Por lo tanto, se puede concluir que el método de mínimos cuadrados es preciso pero depende netamente de la base utilizada para interpolar, por lo tanto hay que realizar un estudio previo de la funcion que se desea interpolar para conocer su curva y ver cual es la base que mejor podria interplar dicha función.

RESULTADOS DE CI






#PROGRAMA ¿Como ejecutar?
Dentro de la carpeta "test" se encuentra un archivo llamado makefile, el cual aporta con 3 comandos muy utiles:
1) make install: "Instalar". Este comando crea las carpetas necesarias para poder guardar los archivos de manera ordenada y clara para quien analiza los resulatados. 
2) make clean: Elimina todos los archivos y carpetas que crea el programa.Luego crea nuevamente las carpetas pero sin archvios en su interior.
3) make: Este comando sirve para compilar el programa.

Por lo tanto para poder utilizar el programa es necesario seguir los siguiente pasos:
1) Abrir una consola en la carpeta "test".
2) Ejecutar el comando make install, para crear las carpetas correspondientes.
3) Ejecutar el comando make, para compilar el programa y obtener el ejecutable (main).
4) Ejecutar el programa con el comando ./main

El programa cuenta con un MENU en el cual se pueden realizar los diferentes calculos pedidos para el laboratorio. Esta bien explicado el menu en su interior por lo que no se necesita mayor detalle de este.

#RESULTADOS
Cabe recalcar que los resultados obtenidos se guardan en las diferentes carpetas creadas dentro de la carpeta  "resultados" estas carpetas se explican a continuaciones:
    "DD": Carpeta que contiene los archivos resultantes para el método de Diferencias Divididas que se graficaran en matlab 
    "DF": Carpeta que contiene los archivos resultantes para el método de Diferencias Finitas que se graficarán en matlab 
    "CS": Carpeta que contiene los archivos resultantes para el método de Spline Cubico que se graficarán en matlab 
    "MS": Carpeta que contiene los archivos resultantes para el método de Mínimos Cuadrados que se graficarán en matlab 
    "_Errores: Carpeta que contiene los resutados de los errores dentro de esta carpeta existen 2 archivos que detallan los resutlados para cada función.
    "CI": Carpeta que contiene los resutlados sobre el calculo integra a través de los métodos de simpson y trapecio.

#MATLAB
Dentro de la carpeta principal, se encuentra una subcarpeta llamada matlab. Dentro de esta, se encuentras los diferentes archivos para graficar en matlab los diferentes resutlados obtenidos,para cada uno de los métodos de interpolación. Dentro de estos archivos se encuentra uno en especial llamado "main.m", el cual ofrece un "menu" para poder elegir cuales resultados desea graficar, lo cual facilita un poco el trabajo para quien deba analizar estos gráficos. Cabe recalcar que esta especie de menu se presenta una sola vez por ejecucion del archivo "main.m".
