#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#define max 32

int main(int argc, char **argv){
    char c;
    char string[max];
    int i = 0;

    // Looks for the first arguement being cryptoMagic and then sees if the user wants to encrypt or decrypt
    if (! strcmp(argv[1], "cryptoMagic")){
        /*Just copies from crp to txt, no encryption yet*/
        if (! strcmp(argv[2], "-D")){
            /*Decrypt*/
            printf("Decrypted");
            FILE * dreadFile = fopen("TextFile.crp", "r");
            FILE * dwriteFile = fopen("TextFile.txt", "w");
            if (dreadFile && dwriteFile){
                while ((c = getc(dreadFile)) != EOF){
                    string[i] = (char)c;
                    fprintf(dwriteFile, "%s", string);
                    i++;
                }
            }
            fclose(dwriteFile);
            fclose(dreadFile);
        }

        else{
            /*Encrypt*/
            printf("Encrypted");
            FILE * readFile = fopen("TextFile.txt", "r");
            FILE * writeFile = fopen("TextFile.crp", "w");
            if (readFile && writeFile){
                /*Function to change the encrypted text to plain text*/
                while (fgets(string, max, readFile)){
                    while(string[i] != '\0') {
                        char outchar = string[i] - 16;
                        if (outchar < 32) {
                            char outchar = (outchar - 32) + 144 ;
                        }
                        fprintf(writeFile, "%2x",outchar);
                        i++;
                    }
                }
                fprintf(writeFile, "<CR>");
            }
            fclose(writeFile);
            fclose(readFile);
        }
    }
    return 0;
}