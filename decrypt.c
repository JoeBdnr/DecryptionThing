#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char c;

    FILE * textFile = fopen("TextFile.txt", "r");
    if (textFile){
        while ((c = getc(textFile)) != EOF)
            printf("%02X",/*"%c",*/ c);
        fclose(textFile);
    }
    for (int i=1; i< argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }
    // argc and argv
    // atoi 
    return 0;
}