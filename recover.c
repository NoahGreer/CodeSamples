/**
 * Noah Greer
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    // variable to reference the input filename
    const char* infile = "card.raw";
    
    // open the input file
    FILE* inptr = fopen(infile, "rb");
    
    // ensure the input file was opened successfully
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }
    
    // temporary storage
    unsigned char block[512];
    
    // pointer to the output file
    FILE* outptr;
    
    // counter to create the output filenames
    int filecount = 0;

    // toggle to determine when a jpg signature has been found
    bool foundsignature = false;
    
    // toggle to determine when we are in the jpg file
    bool inimgfile = false;
    
    // place to store the generated output filenames of the form "###.jpg"
    char outfile[8];
    
    // search through the raw file one block at a time for jpg files by their signature
    // expecting to read 1 element of size sizeof(block)
    while (fread(&block, sizeof(block), 1, inptr) == 1)
    {
        // check the first three bytes in the current block for the constant part of the jpg signature
        // also check the fourth byte for the variable part of the jpg signature; it must be between 0xe0 and 0xef
        if (block[0] == 0xff && 
            block[1] == 0xd8 && 
            block[2] == 0xff && 
            block[3] >= 0xe0 && 
            block[3] <= 0xef)
        {
            // set the found signature toggle so that we know to create the file later
            foundsignature = true;
            
            // if we are already in an image file close it, increment the filecount, and toggle inimgfile
            if (inimgfile)
            {
                // close the last output image file
                fclose(outptr);

                // finished writing a recovered jpg; increase the file counter for the next filename
                filecount++;
                
                // reset inimgfile so we start a new file
                inimgfile = false;
            }
        }
        
        // if we found a jpg signature and we are not already in an image file then create a new file to begin writing to
        if (foundsignature && !inimgfile)
        {
            // generate the next file name of the form "###.jpg"
            sprintf(outfile, "%.3i.jpg", filecount);
            
            // create the output file
            outptr = fopen(outfile, "w");
            
            // ensure the output file was created successfully
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", outfile);
                return 2;
            }
            
            // reset so that we will know when the next jpg signature is found
            foundsignature = false;
            
            // remember that we are now in an image file so that we can begin writing blocks to it
            inimgfile = true;
        }
        
        if (inimgfile)
        {
            // write the current block to the output file
            // expecting to write 1 element of size sizeof(block)
            // ensure the write was sucessful
            if (fwrite(&block, sizeof(block), 1, outptr) != 1)
            {
                fclose(inptr);
                fclose(outptr);
                fprintf(stderr, "Could not write to %s.\n", outfile);
                return 3;
            }
        }
    }
    
    // close the file 
    if (feof(inptr))
    {
        fclose(inptr);
        fclose(outptr);
    }
    else
    {
        fclose(inptr);
        fclose(outptr);
        return 4;
    }

    return 0;
}