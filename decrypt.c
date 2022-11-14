#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char c;

    FILE * readFile = fopen("TextFile.txt", "r");
    if (readFile){
        while ((c = getc(readFile)) != EOF)
            printf(/*"%02X",*/"%c", c);
        fclose(readFile);
    }
    FILE * writeFile = fopen("TextFile.txt", "w");
    if (writeFile){
            // for (char ch = 'a'; ch < 'q'; ch++) /*This one is for going character by character*/
            //     fputc(ch, textFile);
            // fprintf(readFile, "Lalala lalalalala lalala lalalalala"); /*This one does a whole line*/
        fclose(writeFile);
    }

    if (! strcmp(argv[1], "cryptoMagic")){
        for (int i=1; i< argc; i++) {
            if (! strcmp(argv[i], "-E")){
                /*Encrypt*/
                printf("Encrypted");
            }
            else if (! strcmp(argv[i], "-D")){
                /*Decrypt*/
                printf("Decrypted");
            }
            else{
                /*Encrypt*/
            }
        }
    }


    for (int i=1; i< argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }
    return 0;
}