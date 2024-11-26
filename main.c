#include "vigenere.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Enter Plain Text: ");
  char *p = getstr(255);

  printf("Enter Key: ");
  char *k = getstr(255);

  char *c = encrypt(p, k);

  printf("Cipher Text: ");
  printf("%s\n", c);

  p = decrypt(c, k);

  printf("Plain Text: ");
  printf("%s\n", c);

  free(c);
  free(p);
  free(k);

  return 0;
}
