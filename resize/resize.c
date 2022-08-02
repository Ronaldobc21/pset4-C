// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;

    }


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    int cod = atoi(argv[1]);


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }


    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, codbf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    codbf = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, codbi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    codbi = bi;


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 ;

    codbi.biWidth  = bi.biWidth  * cod;
    codbi.biHeight = bi.biHeight * cod;

    int padding_code = (4 - (codbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 ;


    codbi.biSizeImage   = (padding_code + codbi.biWidth * sizeof(RGBTRIPLE)) * abs(codbi.biHeight);
    codbf.bfSize        = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + codbi.biSizeImage;



    // write outfile's BITMAPFILEHEADER
    fwrite(&codbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&codbi, sizeof(BITMAPINFOHEADER), 1, outptr);



    // determine padding for scanlines


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        for (int p = 0; p < cod; p++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int ñ = 0; ñ < cod; ñ++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding_code; k++)
            {
                fputc(0x00, outptr);
            }

            fseek(inptr, -(padding + bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);

        }

        fseek(inptr, (padding + bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
