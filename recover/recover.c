#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])   // Esto para la función de todo.
{

// Argc cuenta el numero de argumentos.
// El argv cuenta el numero de los indices de los elementos ingresados.

    int y = 0;
    char array [10]; // Del tammaño de la imagen.
    BYTE picture[512]; // El tamaño  de la imagen, esto es lo que pesa.


    if (argc !=  2)  // Es diferente de dos
    {
        fprintf(stderr, "Segmentation Fault");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    FILE *salida;

    while (fread(picture, 512, 1, inptr)) // Lo lea una vez es el 1.
    {

        if (picture[0] == 0xff && picture[1] == 0xd8 && picture[2] == 0xff && picture[3] >= 0xe0 && picture[3] <= 0xef)
        {
            sprintf(array, "%0.3i.jpg", y);// Va imprimir o etiquetar el nombre de los archivos.
            // No tienen nombre las imagenes entonces aqui se le pone nombre a la imagenes.
            salida = fopen(array, "w");
            y++;
        }

        if (salida != NULL)
        {
            fwrite(picture, 512, 1, salida);
        }
    }

    fclose(inptr);
    fclose(salida);

    return 0;

}