#ifndef wc_c
#define wc_c

#include "wc.h"

int init_filepointer(const char* filename, FILE *fp) {
    fp = fopen(filename, "r");
    if (fp) {
        return 0;
    } 
    else {
        return 1;
    }
}

int print_wc(const char* filename) {
    FILE *fp = (FILE*)malloc(sizeof(FILE*));
    if (init_filepointer(filename, fp)) {
        printf("Error while trying to open file %s\n", filename);
        free(fp);
        return 1;
    }
    unsigned int char_count = 0;
    unsigned int word_count = 0;
    unsigned int line_count = 0;

    /* main program starts here! */

    printf("Chars: %d\nWords: %d\nLines: %d\n", char_count, word_count, line_count);
    free (fp);
    return 0;
}



#endif /* wc_c */
