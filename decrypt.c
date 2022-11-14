#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char c;

/*The two text files need to be changed in a function that will encrypt/decrypt them*/

    FILE * readFile = fopen("TextFile.txt", "r");
    // if (readFile){
    //     while ((c = getc(readFile)) != EOF)
    //         printf(/*"%02X",*/"%c", c);
    // }

    FILE * writeFile = fopen("TextFile.crp", "w");
    // if (writeFile){
    //         // for (char ch = 'a'; ch < 'q'; ch++) /*This one is for going character by character*/
    //         //     fputc(ch, writeFile);
    //         fprintf(writeFile, "Message"); /*This one does a whole line*/
    // }

    // Looks for the first arguement being cryptoMagic and then sees if the user wants to encrypt or decrypt
    if (! strcmp(argv[1], "cryptoMagic")){
        if (strcmp(argv[2], "-D") == 0){
            /*Decrypt*/
            printf("Decrypted");
            if (readFile && writeFile){
                while ((c = getc(readFile)) != EOF){
                    putc(c, writeFile);
                }    
            }
        }
        else{
            /*Encrypt*/
            printf("Encrypted");
        }
    }

    // This just prints all my arguements
    for (int i=1; i< argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }

    fclose(writeFile);
    fclose(readFile);
    return 0;
}