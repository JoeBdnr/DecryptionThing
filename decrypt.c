#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

int main(int argc, char **argv){
    char c;
    // printf(argv[3]);
    // printf("\n");
    // char *d;
    // strcpy(d, argv[3]);
    // printf("the length of %s is: %i", d, strlen(d));
    // printf("\n");
    // remove(d);
    // char *base;
    // strcpy(base, d);
    // printf(d);
    // printf("\n");

/*Need to get the .txt (extension) off the filename*/
/*The two text files need to be changed in a function that will encrypt/decrypt them*/

    // FILE * readFile = fopen("TextFile.txt", "r");
    // FILE * readFile = fopen("TextFile.txt", "r");
    // if (readFile){
    //     while ((c = getc(readFile)) != EOF)
    //         printf(/*"%02X",*/"%c", c);
    // }

    // FILE * writeFile = fopen("TextFile.crp", "w");
    // if (writeFile){
    //         // for (char ch = 'a'; ch < 'q'; ch++) /*This one is for going character by character*/
    //         //     fputc(ch, writeFile);
    //         fprintf(writeFile, "Message"); /*This one does a whole line*/
    // }


    // Looks for the first arguement being cryptoMagic and then sees if the user wants to encrypt or decrypt
    if (! strcmp(argv[1], "cryptoMagic")){
        /*Just copies from crp to txt, no encryption yet*/
        if (! strcmp(argv[2], "-D")){
            /*Decrypt*/
            printf("Decrypted");
            FILE * dreadFile = fopen("TextFile.crp", "r");
            FILE * dwriteFile = fopen("TextFile.txt", "w");
            if (dreadFile && dwriteFile){
            /*Function to change the encrypted text to plain text*/
                while ((c = getc(dreadFile)) != EOF){
                    putc(c, dwriteFile);
                }
            }
            fclose(dwriteFile);
            fclose(dreadFile);
            /*unlink(dreadFile)*/

        }
        /*Just copies from txt to crp, no encryption yet*/
        else{
            /*Encrypt*/
            printf("Encrypted");
            FILE * readFile = fopen("TextFile.txt", "r");
            FILE * writeFile = fopen("TextFile.crp", "w");
            if (readFile && writeFile){
                /*Function to change the encrypted text to plain text*/
                while ((c = getc(readFile)) != EOF){
                    putc(c, writeFile);
                }
            }
            fclose(writeFile);
            fclose(readFile);
        }
    }

    // This just prints all my arguements
    for (int i=1; i< argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }
    return 0;
}

// void crypt(int encrypt, int argc, char **argv){
//     char c;
//     if (encrypt){
//         FILE * readFile = fopen("TextFile.txt", "r");
//         FILE * writeFile = fopen("TextFile.crp", "w");
//         if (readFile && writeFile){
//             /*Code to change the plain text to ecrypted text*/
//             while ((c = getc(readFile)) != EOF){
//                 putc(c, writeFile);
//             }
//         }
//     }
//     else{
//         FILE * readFile = fopen("TextFile.crp", "r");
//         FILE * writeFile = fopen("TextFile.txt", "w");
//         if (readFile && writeFile){
//             /*Code to change the encrypted text to plain text*/
//             while ((c = getc(readFile)) != EOF){
//                 putc(c, writeFile);
//             }
//         }
//     }
// }