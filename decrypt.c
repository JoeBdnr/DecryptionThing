#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char c;

    // FILE * textFile = fopen("TextFile.txt", "r");
    // if (textFile){
    //     while ((c = getc(textFile)) != EOF)
    //         // printf("%02X",/*"%c",*/ c);
    //         printf("%02X",c);
    //     fclose(textFile);
    // }
    FILE * textFile = fopen("TextFile.txt", "w");
    if (textFile){
            // for (char ch = 'a'; ch < 'q'; ch++) /*This one is for going character by character*/
            //     fputc(ch, textFile);
            fprintf(textFile, "Lalala lalalalala lalala lalalalala"); /*This one does a whole line*/
        fclose(textFile);
    }

    for (int i=1; i< argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }
    return 0;
}


// int main (int argc, char **argv) {
    
//     if(argc == 1) {
//         printf("Need a .foo file");
//         return 0;
//     }

//     char *ext = strrchr(argv[1], '.');
//     if(!ext || strcmp(ext, ".foo")) {
//         printf("Not a .foo file");
//         return 0;
//     }

//     char *basename = (strrchr(argv[1], '\\'));
//     if(!basename) {
//         basename = argv[1];
//     } else {
//         basename++;
//     }

//     char *out_file = (char*) malloc((strlen(basename)+1)*sizeof(char));
//     sprintf(out_file, "%.*s%s", (int) (ext - basename), basename, ".bar");
// }