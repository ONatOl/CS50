/**
 * recover.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }
    
    // open input file 
    FILE *inFile = fopen(argv[1], "rb");
    if (inFile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    
    // pointer to output file
    FILE *outFile = NULL; 
    
    char outFileNow[8];
    int count = 0;
    uint8_t *buffer = malloc(512);
    
    while (fread(buffer, 1, 512, inFile) == 512)
    {
        if (buffer[0] == 0xff && 
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        
        {
            // close output file
            if (outFile != NULL) 
            fclose(outFile);
                    
            sprintf(outFileNow, "%03d.jpg", count);
            count++;
            outFile = fopen(outFileNow, "wb");
        }  
        if (outFile != NULL)
            fwrite(buffer, 1, 512, outFile);
    }
    free(buffer);
    
    fclose(inFile);
    fclose(outFile);

    return 0;
}
