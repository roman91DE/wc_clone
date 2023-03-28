#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/*

SYNOPSIS
    wc [-clm] filename

OPTIONS

    -c      Write to standard output the number of bytes in each input file.
    -l      Write to standard output the number of lines in each input file.
    -w      Write to standard output the number of words in each input file

*/

int _wc(bool cflag, bool lflag, bool wflag, const char* filename) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (!fp) {
    printf("Error while trying to open file %s\n", filename);
    return EXIT_FAILURE;
  }
  unsigned int byte_count = 0;
  unsigned int word_count = 0;
  unsigned int line_count = 0;
  char current_byte;

  while ((current_byte = (char)fgetc(fp)) != EOF) {
    ++byte_count;
    if ((current_byte == ' ')||(current_byte == '\t')) {
      ++word_count;
    } else if (current_byte == '\n') {
      ++line_count;
      ++word_count;
    }
  }
  ++word_count;

  if ((!cflag)&&(!lflag)&&(!wflag)) {
    printf("Bytes:%d\nLines:%d\nWords:%d\n", byte_count, line_count, word_count);
  } else {
    if (cflag) {
        printf("Bytes:%d\n", byte_count);
    }if (lflag) {
        printf("Lines:%d\n", line_count);
    }if (wflag) {
        printf("Words:%d\n", word_count);
    }
  } printf("Filename:%s\n", filename);
  return EXIT_SUCCESS;
}

int main(int argc, const char *argv[]) {

  int cflag = 0;
  int lflag = 0;
  int wflag = 0;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt(argc, argv, "clw")) != -1)
    switch (c) {
    case 'c':
      cflag = true;
      break;
    case 'l':
      lflag = true;
      break;
    case 'w':
      wflag = true;
      break;
    case '?':
      if (isprint(optopt))
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      return 1;
    default:
      abort();
    }

  // iterate files
  const char *filename = NULL;
  for (index = optind; index < argc; index++) {
    _wc(cflag,lflag, wflag, argv[index]);
  }

  return 0;
}
