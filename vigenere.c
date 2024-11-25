#include "vigenere.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tocipher(char *p, char *k) {
  char *cipher = (char *)malloc(sizeof(p));
  int ki = 0, ci = 0;

  for (int pi = 0; pi < strlen(p) - 1; ++pi) {
    // convert ascii charecters to alphabetic number
    p[pi] = p[pi] - 'A';
    k[ki] = k[ki] - 'A';

    printf("Key Size: %ld\n", strlen(k));
    printf("KI: %d\n", ki);

    // convert to cipher text as ascii
    cipher[pi] = ((p[pi] + k[ki]) % 26) + 'A';
    ++ki;

    // reset the key's index
    if (ki == strlen(k) - 1)
      ki = 0;
  }

  return cipher;
  free(cipher);
}
