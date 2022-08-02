# Questions

## What's `stdint.h`?

Es la funcion que declara un tipo de dato entero que tiene un ancho en especifico.

TODO

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?


Sirve para establecer o declarar una variable de ese tipo de ancho, ya que en ocasiones el programa
puede dar error si no se juega con las variables del mismo rango de longitud EJ= BYTE.

TODO

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1bytes,  DWORD = 4bytes, LONG = 8bytes , WORD = 2bytes.

TODO

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Los primeros 2 bytes de todo archivo BMP tienen que ser el caracter B y despues el caracter M en ascii.

TODO

## What's the difference between `bfSize` and `biSize`?

bfSide: es el tamaño del archivo bmp completo, este incluye los archivos de encabezado.
Mientras que: biSize: especifica el numero de bytes requerido por la estructura.


TODO

## What does it mean if `biHeight` is negative?

El mapa de bits es un DIB " de arriba a abajo" y su origen es la esquina superior izquierda.


TODO

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

Especifica el numero de bits por pixel, define el numero maximo de colores en el mapa de bits.


TODO

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Existe algunas razones por la cuales "fopen" devolveria NULL en la linea 37 de copy.c. como el programa llega
a la linea 37, ahi parece ser 2 argumentos de linea de comandos, y dado que esta escribiendo en un archivo en la linea 37,
si el archivo aun no existe el programa creara el archivo y lo almacenara en le directorio de trabajo actual.
si la computadora no puede asignar suficiente memoria para crear el archivo deseado, esta devolvera NULL. ademas,
puede haber un error de permiso cuando tratando de escribir en un archivo abierto, es posible que no tenga acceso
a ese archivo.

TODO

## Why is the third argument to `fread` always `1` in our code?

Argumento de conteo, el cual contiene el numero maximo de elementos a leer.


TODO

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

"copy.c: 70" esto asigna a <padding> un valor de 3 si <bi.biwidth> es 3.


TODO

## What does `fseek` do?

Esto activa el indicador de posicion de fcheros para el stream apuntado por stream.

TODO

## What is `SEEK_CUR`?

Es el que calcula el desplazamimeto de la posicion actual del indicador de posicion de ficheros.

TODO
